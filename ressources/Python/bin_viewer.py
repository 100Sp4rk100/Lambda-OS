from PIL import Image
import sys

def rgb565_to_rgb888(v):
    r = (v >> 11) & 0x1F
    g = (v >> 5) & 0x3F
    b = v & 0x1F

    r = (r << 3) | (r >> 2)
    g = (g << 2) | (g >> 4)
    b = (b << 3) | (b >> 2)
    return (r, g, b)

if len(sys.argv) == 1:
    raise AttributeError("You need to specify a binary file : bin_viewer.py img.bin")

bin_path = sys.argv[1]

img = Image.new("RGB", (16, 16))

bin_file = open(bin_path, "br")
px_bytes = bin_file.read()

for y in range(16):
    for x in range(16):
        pos = (y * 16 + x) * 2

        rgb = px_bytes[pos:pos + 2]

        v = int.from_bytes(rgb, byteorder="little")
        
        r, g, b = rgb565_to_rgb888(v)
        
        img.putpixel((x, y), (r, g, b))
bin_file.close()

img.show()