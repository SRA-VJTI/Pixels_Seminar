# Image Storing Formats


## Table Of Contents
- [Table Of Contents](#table-of-contents)
- [Different Image Storing Formats](#different-image-storing-formats)
    * [Bitmap (.bmp)](#bitmap-(.bmp))
    * [Tiff Format](#tiff-format)
    * [Jpg Format](#jpg-format)
    * [Png Format](#png-format)
- [Installations](#installations)
- [Build and run the executables](#build-and-run-the-executables)
   
* All images are stored in the computer as rectangular pixels. The resolution is an image referign to the number of pixels in a grid. Higher resolutions can be more details can be stored in an image. 
* Images are stored and transmitted using image file formats, which are digital file formats. Each file format has an own method for storing and compressing image data, which can affect how many pixels an image can have.


## The goal of this topic is to familiarise you with various Image Storing Formats 


## Different Image Storing Formats

#### 1) Bitmap (.bmp)

* The BMP(Bitmap) format simply records the colour of each pixel with no compression(typically).
* It simply stores the image pixels by pixels.  This means that a BMP image file can contain a large number of pixels, but the file size will also be very large. For example, a 1920x1080 pixel BMP image can be over 6 MB in size.

#### 2) Tiff Format

* A TIFF, which stands for Tag Image File Format, is a computer file used to store raster graphics and image information. A favourite among photographers, TIFFs are a handy way to store high-quality images before editing if you want to avoid lossy file formats. 

* TIFF files are a lossless form of file compression, which means they’re larger than most but don’t lose image quality.

#### 3) Jpg Format

* A JPG file is a raster image saved in the JPEG format, commonly used to store digital photographs and graphics created by image-editing software. JPEG features lossy compression that can significantly reduce the size of an image without much degradation and supports up to 16,777,216 colors.

* This means that a JPEG image file can contain a moderate number of pixels while still maintaining reasonable image quality. For example, a 1920x1080 pixel JPEG image can be under 1 MB in size.


#### 4) Png Format
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
  for eg : `./image /home/chinmay/Pixels_Seminar/image_storing_formats/image.bmp`

This will display the image.

#### Run without make
If you want to run the code without make then just type

- `g++ -g image_storing_formats.cpp -o output $(pkg-config --cflags --libs sdl2 SDL2_image)`

and then
- `./image <image_path>)`\
  for eg : `./image /home/chinmay/Pixels_Seminar/image_storing_formats/image.bmp`
  
  
This will display the image.
