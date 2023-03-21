# Image Representation

## Table Of Contents
- [Table Of Contents](#table-of-contents)
- [How do we represent Image?](#How-do-we-represent-Image?)
- [SOME IMPORTANT TERMINOLOGIES](#SOME-IMPORTANT-TERMINOLOGIES)
- [COLOUR MODELS](#COLOUR-MODELS)
    * [ADDITIVE MODEL](#ADDITIVE-MODEL)
    * [SUBTRACTIVE MODEL](#SUBTRACTIVE-MODEL)
    * [HSV COLOUR MODEL](#HSV-COLOUR-MODEL)
- [Different Image Storing Formats](#Different-Image-Storing-Formats)
    * [Bitmap (.bmp)](#Bitmap-(.bmp))
    * [Tiff Format](#Tiff-Format)
    * [Jpg Format](#Jpg-Format)
    * [Png Format](#Png-Format)
- [Installations](#Installations)
- [Build and run the executables](#Build-and-run-the-executables)

## How do we represent Image?

- It can be represented in various forms. 
- As most of the time, representation

  refers to the way that brings information, such as color is coded digitally,

  and how the image is stored, i.e., how an image file is structured.

- So,for the simplicity of computing it is represented in a matrix form.


## SOME IMPORTANT TERMINOLOGIES

1. Pixel: Pixel is the smallest unit of a picture displayed on the computer screen.

A pixel includes its own:-

● Intensity

● Name or Address

The size of the image is defined as the total number of pixels in the horizontal direction times the total

number of pixels in the vertical direction. For eg: (512 x 512,640 x 480, or 1024 x 768).

## BINARY IMAGES


![BINARY IMAGES](./images/b&w.PNG)

## GRAYSCALE IMAGES
![GRAYSCALE IMAGES](./images/gray.PNG)

## RGB IMAGES
![RGB IMAGES](./images/rgb.PNG)

2. **Resolution**: The number of pixels per unit is called the resolution

of the image.The sharpness of the picture on display depends on the

resolution and the size of the monitor.

It includes-

● **Image Resolution**: The distance between two pixels.

● **Screen Resolution**: The number of horizontal and vertical pixels displayed on the screen is called

Screen Resolution.

For Example– 640 x 480, 1024 x 768 (Horizontal x Vertical)


3. **Aspect Ratio**: The ratio of image’s width to its height is known as

the aspect ratio of an image. The height and width of an image are

measured in length or number of pixels.

For Example: If a graphics has an aspect ratio of 2:1, it means the width is twice large to height.

It includes–

● **Frame aspect ratio**: Horizontal /Vertical Size

● **Pixel aspect ratio**: Width of Pixel/Height of Pixel

## COLOUR MODELS

Color model is a 3D color coordinate system to produce all range of color through the primary color set.
Their types are:

### ADDITIVE MODEL

● It is also named as “RGB model.” RGB stands for Red, Green, Blue.

● The Additive color model uses a mixture of light to display colors.

● The perceived color depends on the transmission of light.

● It is used in digital media.For eg: Computer Monitor, Television etc.

![ADDITIVE MODEL](./images/add.PNG)

### SUBTRACTIVE MODEL

● It is also named as “CMYK Model.” CMYK stands for Cyan, Magenta, Yellow, and Black.

● The Subtractive model uses a reflection of light to display the colors.

● The perceived color depends on the reflection of light.

● The CMYK model uses printing inks. For Example: Paint, Pigments, and color filter etc.

![SUBTRACTIVE MODEL](./images/subt.PNG)

### HSV COLOUR MODEL

● These are schemes that describe the way colors combine to create the spectrum we see.

● Unlike RGB and CMYK, which use primary colors, HSV is closer to how humans perceive color.

● It has three components: hue, saturation, and value. This color space describes colors (hue or tint)

in terms of their shade (saturation or amount of gray) and their brightness value.

![HSV COLOUR MODEL](./images/hsv(img).PNG)

### THREE COMPONENTS

**HUE**: Hue is the color portion of the model, expressed as a number from 0 to 360 degrees:

Red falls between 0 and 60 degrees.

Yellow falls between 61 and 120 degrees.

Green falls between 121 and 180 degrees.

Cyan falls between 181 and 240 degrees.

Blue falls between 241 and 300 degrees.

Magenta falls between 301 and 360 degrees.

**SATURATION**: Saturation describes the amount of gray in a particular color, from 0 to 100 percent.

Reducing this component toward zero introduces more gray and produces a faded effect. Sometimes,

saturation appears as a range from 0 to 1, where 0 is gray, and 1 is a primary color.

**VALUE (OR BRIGHTNESS)**: Value works in conjunction with saturation and describes the brightness or

intensity of the color, from 0 to 100 percent, where 0 is completely black, and 100 is the brightest and

reveals the most color.



   
* All images are stored in the computer as rectangular pixels. The resolution is an image referign to the number of pixels in a grid. Higher resolutions can be more details can be stored in an image. 
* Images are stored and transmitted using image file formats, which are digital file formats. Each file format has an own method for storing and compressing image data, which can affect how many pixels an image can have.


## The goal of this topic is to familiarise you with various Image Storing Formats 


## Different Image Storing Formats

#### Bitmap (.bmp)

* The BMP(Bitmap) format simply records the colour of each pixel with no compression(typically).
* It simply stores the image pixels by pixels.  This means that a BMP image file can contain a large number of pixels, but the file size will also be very large. For example, a 1920x1080 pixel BMP image can be over 6 MB in size.

#### Tiff Format

* A TIFF, which stands for Tag Image File Format, is a computer file used to store raster graphics and image information. A favourite among photographers, TIFFs are a handy way to store high-quality images before editing if you want to avoid lossy file formats. 

* TIFF files are a lossless form of file compression, which means they’re larger than most but don’t lose image quality.

#### Jpg Format

* A JPG file is a raster image saved in the JPEG format, commonly used to store digital photographs and graphics created by image-editing software. JPEG features lossy compression that can significantly reduce the size of an image without much degradation and supports up to 16,777,216 colors.

* This means that a JPEG image file can contain a moderate number of pixels while still maintaining reasonable image quality. For example, a 1920x1080 pixel JPEG image can be under 1 MB in size.


#### Png Format
* A PNG file is an image saved in the Portable Network Graphic (PNG) format, commonly used to store web graphics, digital photographs, and images with transparent backgrounds. It is a raster graphic similar to a .JPG image but is compressed with lossless compression and supports transparency.

* This means that a PNG image file can contain a moderate number of pixels while still maintaining high image quality. For example, a 1920x1080 pixel PNG image can be under 3 MB in size.


## Installations

To install sdl and its related libraries :
> sudo apt-get install libsdl2-2.0-0 \
> sudo apt-get install libsdl2-image-dev


## Build and run the executables

Now that you are aware with the various image storing formats, let's look at how to create and execute executables.

After cloning in the Pixels_Seminar repository, get into the image_storing_formats folder using cd command 

`cd /Pixels_Seminar/Image_storing_formats`

image_storing_formats.cpp is our code file.

Perform make command 

`make`

To run 

- `./image <image_path>)`\
  for eg : `./image /home/chinmay/Pixels_Seminar/3_cv_basics/1_image_representation/image.bmp`

This will display the image.

#### Run without make
If you want to run the code without make then just type

- `g++ -g image_storing_formats.cpp -o output $(pkg-config --cflags --libs sdl2 SDL2_image)`

and then
- `./image <image_path>)`\
  for eg : `./image /home/chinmay/Pixels_Seminar/3_cv_basics/1_image_representation/image.bmp`
  
  
This will display the image.
