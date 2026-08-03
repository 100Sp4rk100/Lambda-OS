from PIL import Image
import sys

def rgb888_to_rgb565(r8, g8, b8):
    return ((r8 & 0xF8) << 8) | ((g8 & 0xFC) << 3) | (b8 >> 3)

if len(sys.argv) == 1:
    raise AttributeError("You need to specify an image : img2bin.py img")

img_path = sys.argv[1]

original_img = Image.open(img_path)

img_no_rgb = original_img.resize((16, 16))
img = img_no_rgb.convert("RGB")

output_bytes = b""

for y in range(16):
    for x in range(16):
        px = img.getpixel((x, y))

        r8, g8, b8 = px
        rgb = rgb888_to_rgb565(r8, g8, b8)

        output_bytes += rgb.to_bytes(length=2, byteorder="little")

last_index = img_path.rfind(".")

output_file = open(f"{img_path[:last_index]}.bin", "bw")
output_file.write(output_bytes)
output_file.close()