import sys
from tkinter import *
from PIL import ImageTk, Image

def rgb565_to_rgb888(v):
    r = (v >> 11) & 0x1F
    g = (v >> 5) & 0x3F
    b = v & 0x1F

    r = (r << 3) | (r >> 2)
    g = (g << 2) | (g >> 4)
    b = (b << 3) | (b >> 2)
    return (r, g, b)

def getImageFromBytes(buffer):
    img = Image.new("RGB", (16, 16))

    for y in range(16):
        for x in range(16):
            pos = y * 16 + x

            rgb = buffer[pos]
            
            r, g, b = rgb565_to_rgb888(rgb)
            
            img.putpixel((x, y), (r, g, b))

    return img.resize((640, 640), Image.Resampling.NEAREST)

class Controller:
    def __init__(s, label):
        s.offset = 0
        s.img_x = 0
        s.img_y = 0
        s.variables = [0, 0, 0, 0]
        s.skip_next_instruction = False
        s.buffer = None
        s.replacement_color = 0xFFFFFFFF
        s.tick_ms = 0
        s.img_buffer = [0] * (16 * 16)
        s.panel = label

    def loadAnimation(s, b):
        s.buffer = b
        s.offset = 0

        #fill img_buffer
        for i in range(16*16):
            color = int.from_bytes(b[s.offset:s.offset+2], byteorder="little")
            s.img_buffer[s.offset//2] = color

            s.offset += 2

        #get tick_ms
        s.tick_ms = int.from_bytes(b[s.offset:s.offset+2], byteorder="little")
        s.offset += 2

        #get replacement_color
        s.replacement_color = int.from_bytes(b[s.offset:s.offset+2], byteorder="little")
        s.offset += 2

        #get base position
        s.img_x = int.from_bytes(b[s.offset:s.offset+2], byteorder="little")
        s.offset += 2
        s.img_y = int.from_bytes(b[s.offset:s.offset+2], byteorder="little")
        s.offset += 2

        s.variables = [0, 0, 0, 0]
        s.skip_next_instruction = False

        s.panel.image = ImageTk.PhotoImage(getImageFromBytes(s.img_buffer))
        s.panel.grid()

        img_tk = ImageTk.PhotoImage(getImageFromBytes(s.img_buffer))
        s.panel.config(image=img_tk)
        s.panel.image = img_tk

    def step(s):
        if s.buffer == None:
            return

        s.applyScreenChanges()

        #execute codes
        current_code = 0xFF
        pending_false_branch = False

        while True:
            #get code
            current_code = int.from_bytes(s.buffer[s.offset:s.offset+1], byteorder="little")
            s.offset += 1

            #get args for code
            args = []
            n_args = s.getNumberOfArgsForCode(current_code)

            for i in range(n_args):
                arg = int.from_bytes(s.buffer[s.offset:s.offset+1], byteorder="little")
                s.offset += 1
                args.append(arg)

            #dont execute the false case if the previous case was true
            if s.skip_next_instruction:
                s.skip_next_instruction = False
                continue

            #execute the logic
            if current_code == 0x01: #move
                s.img_x += s.to_signed(args[0])
                s.img_y += s.to_signed(args[1])
                print(f"Move x : {args[0]}, y : {args[1]}. Image now at x : {s.img_x}, y : {s.img_y}")

            elif current_code == 0x03: #jump
                s.jump(args)

            elif current_code in [0x04, 0x05, 0x06, 0x07]: #add var
                s.variables[[0x04, 0x05, 0x06, 0x07].index(current_code)] += s.to_signed(args[0])
                print(f"Add variable. Variables : {s.variables}")

            elif current_code == 0x08: #case
                s.case_code(args)
                if not s.skip_next_instruction:
                    pending_false_branch = True

            elif current_code in [0x12, 0x13, 0x14, 0x15]: # set var
                s.variables[[0x12, 0x13, 0x14, 0x15].index(current_code)] = s.to_signed(args[0])
                print(f"Set variable. Variables : {s.variables}")

            if current_code in [0x00, 0x02, 0x03]:
                if pending_false_branch:
                    if current_code != 0x03:
                        false_code = int.from_bytes(s.buffer[s.offset:s.offset+1], byteorder="little")
                        s.offset += 1
                        s.offset += s.getNumberOfArgsForCode(false_code)
                    pending_false_branch = False
                break

            if pending_false_branch and current_code != 0x08:
                s.skip_next_instruction = True
                pending_false_branch = False

        if current_code == 0x00: #loop
            s.loadAnimation(s.buffer)

    def applyScreenChanges(s):
        #get number of changes
        n = int.from_bytes(s.buffer[s.offset:s.offset+1], byteorder="little")
        s.offset += 1

        #apply changes
        for i in range(n):
            #get pixels coordinates
            xy = int.from_bytes(s.buffer[s.offset:s.offset+1], byteorder="little")
            s.offset += 1

            x = xy >> 4
            y = xy & 0x0F

            #get pixel color
            color_val = int.from_bytes(s.buffer[s.offset:s.offset+2], byteorder="little")
            s.offset += 2

            #apply changes
            s.img_buffer[(y * 16) + x] = color_val

        #redraw
        img_tk = ImageTk.PhotoImage(getImageFromBytes(s.img_buffer))
        s.panel.config(image=img_tk)
        s.panel.image = img_tk

    def getNumberOfArgsForCode(s, code):
        codes_bytes_args = {
            0x00:0,
            0x01:2, #args : x, y
            0x02:0,
            0x03:1, #args : frame
            0x04:1, #args : value
            0x05:1, #args : value
            0x06:1, #args : value
            0x07:1, #args : value
            0x08:3, #args : variable/ value, opperation, variable/ valuegs : value
            0x09:0,
            0x10:0,
            0x11:0,
            0x12:1, #args : value
            0x13:1, #args : value
            0x14:1, #args : value
            0x15:1, #args : value
            0x16:0,
            0x17:0,
            0x18:0,
            0x19:0
        }

        return codes_bytes_args.get(code, 0)

    def jump(s, args):
        n_frame = 0
        tmp_offset = 520

        while n_frame != args[0]:
            n_changes = int.from_bytes(s.buffer[tmp_offset:tmp_offset+1], byteorder="little")
            tmp_offset += 1
            tmp_offset += n_changes * 3

            tmp_current_code = 0xFF
            while tmp_current_code not in [0x00, 0x02, 0x03]:
                tmp_current_code = int.from_bytes(s.buffer[tmp_offset:tmp_offset+1], byteorder="little")
                tmp_offset += 1

                tmp_n_args = s.getNumberOfArgsForCode(tmp_current_code)
                tmp_offset += tmp_n_args

                if tmp_current_code == 0x08:
                    for i in range(2):
                        tmp_current_code = int.from_bytes(s.buffer[tmp_offset:tmp_offset+1], byteorder="little")
                        tmp_offset += 1

                        tmp_n_args = s.getNumberOfArgsForCode(tmp_current_code)
                        tmp_offset += tmp_n_args

            n_frame += 1

        s.offset = tmp_offset

        print(f"Jump to {s.offset}")

    def case_code(s, args):
        if args[0] in [0x16, 0x17, 0x18, 0x19]:
            a = s.variables[[0x16, 0x17, 0x18, 0x19].index(args[0])]
        else:
            a = s.to_signed(args[0])

        if args[2] in [0x16, 0x17, 0x18, 0x19]:
            b = s.variables[[0x16, 0x17, 0x18, 0x19].index(args[2])]
        else:
            b = s.to_signed(args[2])

        if not ((args[1] == 0x09 and a < b) or (args[1] == 0x10 and a > b) or (args[1] == 0x11 and a == b)):
            s.skip_next_instruction = True

        if args[1] == 0x09:
            opperand = "<"
        elif args[1] == 0x10:
            opperand = ">"
        else:
            opperand = "="
        print(f"Case : {a} {opperand} {b}")

    def to_signed(s, val):
        return val - 256 if val > 127 else val

if len(sys.argv) == 1:
    raise AttributeError("You need to specify an animation file : animation_viewer.py animation.bin")

anim_path = sys.argv[1]

root = Tk()
root.title(anim_path)
root.geometry("640x640")

bin_file = open(anim_path, "br")
px_bytes = bin_file.read()
bin_file.close()

panel = Label(root)
controller = Controller(panel)
controller.loadAnimation(px_bytes)

def run_animation():
    controller.step()
    root.after(controller.tick_ms, run_animation)

root.after(controller.tick_ms, run_animation)

root.mainloop()