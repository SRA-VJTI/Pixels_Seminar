# Image Storing Formats

* All images are stored in the computer as rectangular pixels. The resolution is an image referign to the number of pixels in a grid. Higher resolutions can be more details can be stored in an image. 
* Images are stored and transmitted using image file formats, which are digital file formats. Each file format has an own method for storing and compressing image data, which can affect how many pixels an image can have.


## The goal of this topic is to familiarise you with various Image Storing Formats 


## Different Image Storing Formats

#### 1) Bitmap (.bmp)

* The BMP(Bitmap) format simply records the colour of each pixel with no compression(typically).
* It simply stores the image pixels by pixels.  This means that a BMP image file can contain a large number of pixels, but the file size will also be very large. For example, a 1920x1080 pixel BMP image can be over 6 MB in size.

#### 2) .tiff

* A TIFF, which stands for Tag Image File Format, is a computer file used to store raster graphics and image information. A favourite among photographers, TIFFs are a handy way to store high-quality images before editing if you want to avoid lossy file formats. 

* TIFF files are a lossless form of file compression, which means they’re larger than most but don’t lose image quality.

#### 3) .jpg

* A JPG file is a raster image saved in the JPEG format, commonly used to store digital photographs and graphics created by image-editing software. JPEG features lossy compression that can significantly reduce the size of an image without much degradation and supports up to 16,777,216 colors.

* This means that a JPEG image file can contain a moderate number of pixels while still maintaining reasonable image quality. For example, a 1920x1080 pixel JPEG image can be under 1 MB in size.


#### 4) .png

* A PNG file is an image saved in the Portable Network Graphic (PNG) format, commonly used to store web graphics, digital photographs, and images with transparent backgrounds. It is a raster graphic similar to a .JPG image but is compressed with lossless compression and supports transparency.

* This means that a PNG image file can contain a moderate number of pixels while still maintaining high image quality. For example, a 1920x1080 pixel PNG image can be under 3 MB in size.

## Build and run the executables

Now that you are aware with the various image storing formats, let's look at how to create and execute executables.

After cloning in the Pixels_Seminar repository, get into the Image_storing_formats folder using cd command 

`cd /Pixels_Seminar/Image_storing_formats`

Image_storing_formats.cpp is our code file.

Perform make command in 

`make`

To run and build the `Image_storing_formats.cpp` file perform 

`./Image_storing_formats`

The output will show Image size, Bits per pixel and Image data size.



