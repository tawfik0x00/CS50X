from PIL import Image, ImageFilter

image = Image.open("image.bmp")
image = image.filter(ImageFilter.FIND_EDGES)
image.save("out.bmp")
