from PIL import Image, ImageFilter

#blur image
image = Image.open("image.bmp")
image = image.filter(ImageFilter.BoxBlur(1))
image.save("out.bmp")

