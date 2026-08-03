from PIL import Image
import sys

def get_image_diff(image_path_1, image_path_2):
    img1 = Image.open(image_path_1).convert('RGB')
    img2 = Image.open(image_path_2).convert('RGB')

    width1, height1 = img1.size
    width2, height2 = img2.size

    if (width1, height1) != (width2, height2):
        raise ValueError(f"Images are not the same size ! ({width1}x{height1} vs {width2}x{height2})")

    pixels = []
    colors = []

    for y in range(height1):
        for x in range(width1):
            p1 = img1.getpixel((x, y))
            p2 = img2.getpixel((x, y))

            if p1 != p2:
                r, g, b = p2
                hex_color = f"0x{r:02X}{g:02X}{b:02X}"
                
                pixels.append([x, y])
                colors.append(hex_color)

    return pixels, colors

if len(sys.argv) < 3:
    print("Usage: python diff_images.py image_1.png image_2.png")
else:
    file1 = sys.argv[1]
    file2 = sys.argv[2]

    diff_pixels, diff_colors = get_image_diff(file1, file2)

    import json
    print('"pixels": ' + json.dumps(diff_pixels))
    print('"colors": ' + json.dumps(diff_colors))