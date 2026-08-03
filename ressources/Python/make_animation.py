import sys
import json

def rgb888_to_rgb565(rgb888):
    r8 = (rgb888 >> 16) & 0xFF
    g8 = (rgb888 >> 8) & 0xFF
    b8 = rgb888 & 0xFF
    return ((r8 & 0xF8) << 8) | ((g8 & 0xFC) << 3) | (b8 >> 3)

if len(sys.argv) == 1:
    raise AttributeError("You need to specify an animation file : make_animation.py animation.json")

anim_path = sys.argv[1]

animation_file = open(anim_path, "r")
anim_json = json.load(animation_file)
animation_file.close()

output_bytes = b""

ms_time = anim_json["time"]
frames = anim_json["animation"]
replacement_color = int(anim_json["replacement_color"], 16)
position_base = anim_json["position"]

base_img_file = open(anim_json["base"], "br")
base_img = base_img_file.read()
base_img_file.close()

output_bytes += base_img
output_bytes += ms_time.to_bytes(length=2, byteorder="little")
output_bytes += rgb888_to_rgb565(replacement_color).to_bytes(length=2, byteorder="little")
output_bytes += int(position_base[0]).to_bytes(length=2, byteorder="little")
output_bytes += int(position_base[1]).to_bytes(length=2, byteorder="little")

codes_bytes_trad = {
    "loop":0x00,
    "move":0x01, #args : x, y
    "next":0x02,
    "jump":0x03, #args : frame
    "add_0":0x04, #args : value
    "add_1":0x05, #args : value
    "add_2":0x06, #args : value
    "add_3":0x07, #args : value
    "case":0x08, #args : variable/ value, opperation, variable/ value
    "lower":0x09,
    "higher":0x10,
    "equal":0x11,
    "set_0":0x12, #args : value
    "set_1":0x13, #args : value
    "set_2":0x14, #args : value
    "set_3":0x15, #args : value
    "var_0":0x16,
    "var_1":0x17,
    "var_2":0x18,
    "var_3":0x19
}

exit_codes = ["next", "jump", "loop"]
args_signed = ["move", "add_0", "add_1", "add_2", "add_3", "set_0", "set_1", "set_2", "set_3"]
case_var = ["var_0", "var_1", "var_2", "var_3", "lower", "higher", "equal"]

for f in frames:
    pixels = f["pixels"]
    colors = f["colors"]
    codes = f["codes"]

    assert len(pixels) == len(colors), "Missings somes values"

    # we put number of changes on 1o
    output_bytes += len(pixels).to_bytes(byteorder="little")

    for i in range(len(pixels)):
        # we put on 1o x and y because 0<=x<16 and 0<=y<16
        x = pixels[i][0]
        y = pixels[i][1]

        assert 0<=x<16 and 0<=y<16

        x_4b = (x << 4)

        xy = (x_4b | y).to_bytes(byteorder="little")

        # we put the color on 2o (uint16)
        c = colors[i]
        ch = int(c, 16)
        c565 = rgb888_to_rgb565(ch)

        output_bytes += xy
        output_bytes += c565.to_bytes(length=2, byteorder="little")

    # we put all codes on 1o and with args if necessary
    code_bytes = b""
    has_conditional_pending = False
    
    for instruction in codes:
        code = instruction[0]
        args = instruction[1]
        
        code_bytes += codes_bytes_trad[code].to_bytes(byteorder="little")

        for arg in args:
            if isinstance(arg, str) and arg in codes_bytes_trad:
                code_bytes += codes_bytes_trad[arg].to_bytes(byteorder="little")
            else:
                code_bytes += int(arg).to_bytes(byteorder="little", signed=code in args_signed)

        if code == "case":
            has_conditional_pending = True
        elif code in exit_codes:
            if has_conditional_pending:
                has_conditional_pending = False
            else:
                break
    output_bytes += code_bytes

last_index = anim_path.rfind(".")

output_file = open(f"{anim_path[:last_index]}.bin", "bw")
output_file.write(output_bytes)
output_file.close()