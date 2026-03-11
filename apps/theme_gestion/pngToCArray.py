from PIL import Image
import os

def png_to_c_array(var_name):
    # Open the image and rezise
    img = Image.open(f"apps/theme_gestion/customs_backgrounds/{var_name}")

    # Resize the image to screen size (320*240)
    img = img.resize((320, 240))
    
    # We convert to RGBA for compatibility
    img = img.convert("RGBA")
    img.putalpha(255)
    
    w, h = img.size
    pixels = list(img.getdata())
    name = background.replace(".png", "")

    # convert to RGB 565
    rgb565_data = []
    for r, g, b, a in pixels:
        rgb24 = (r << 16) | (g << 8) | b
        rgb565 = ((rgb24 & 0xF80000) >> 8) | ((rgb24 & 0x00FC00) >> 5) | ((rgb24 & 0x0000F8) >> 3)
        rgb565_data.append(rgb565)

    # Generate C code
    c_code = f"// Image {var_name} ({w}x{h})\n"
    c_code += f"const uint16_t {name}[{w*h}] = "
    c_code += "{\n"
    for i, val in enumerate(rgb565_data):
        if i % w == 0:
            c_code += "    "
        c_code += f"0x{val:04X}, "
        if (i + 1) % w == 0:
            c_code += "\n"
    c_code += "};\n"

    # Generate header
    h_code = f"extern const uint16_t {name}[];\n"

    return h_code, c_code

print("Creating custom backgrounds")

c_code = "#include \"customs_backgrounds.h\"\n"
h_code = "#ifndef CUSTOMS_BACKGROUNDS_H\n#define CUSTOMS_BACKGROUNDS_H\n#include <stdint.h>\n"

counter = 0
list_background = []

# Process all PNG images
for background in os.listdir("apps/theme_gestion/customs_backgrounds/"):
    full_path = os.path.join("apps/theme_gestion/customs_backgrounds/", background)
    if not os.path.isdir(full_path) and background.lower().endswith(".png"):
        print(f"Compiling {background}")
        part_h, part_c = png_to_c_array(background)
        h_code += part_h
        c_code += part_c + "\n"
        counter += 1
        list_background.append(background)
    elif not background.lower().endswith(".png"):
        print(f"{background} needs to be a PNG image")

# Add extern declarations to header
h_code += f"extern const int NB_BACKGROUNDS_CUSTOM;\n"
h_code += f"extern const uint16_t* background_list_custom[];\n"
h_code += "#endif\n"

# Add definitions to cpp
c_code += f"const int NB_BACKGROUNDS_CUSTOM = {counter};\n\n"
if counter >0: c_code += "const uint16_t* background_list_custom[NB_BACKGROUNDS_CUSTOM] = {\n"
else: c_code += "const uint16_t* background_list_custom[1] = {\n"
for i, background in enumerate(list_background):
    name = background.replace(".png", "")
    c_code += f"    {name}"
    if i < len(list_background) - 1:
        c_code += ",\n"
    else:
        c_code += "\n"
c_code += "};\n"

#write file content
with open("apps/theme_gestion/background/customs_backgrounds.h", "w") as f:
    f.write(h_code)
    f.close()

with open("apps/theme_gestion/background/customs_backgrounds.cpp", "w") as f:
    f.write(c_code)
    f.close()

print("Succefully created custom backgrounds")