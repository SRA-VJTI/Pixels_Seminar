# Bitwise Operations and Masking
1. Lower pixel values are close to BLACK
2. Higher pixel values are close to WHITE
3. These operations are done bitwise i.e. Pixel wise. 
4. The logic of operation remains same as that of seen in logical/ bitwise operations

#### Illustrations
#### Input Images 
<img src="images/bitwise_ip1.png" align="left" width="300" height="300"/>&nbsp;&nbsp;
<img src="images/bitwise_ip2.png" align = "centre" width="300" height="300"/>

#### Bitwise AND
<img src="images/bitwise_and1.png" width="300" height="300"/>

#### Bitwise OR
<img src="images/bitwise_or1.png" width="300" height="300"/>

#### Bitwise XOR
<img src="images/bitwise_xor.png" width="300" height="300"/>

#### Bitwise NOT
1. Image1 - Bitwise NOT/inversion of Input Image 1  
2. Image2 - Bitwise NOT/inversion of Input Image 2

<img src="images/bitwise_not1.png" align="left" width="300" height="300"/>&nbsp; &nbsp;<img src="images/bitwise_not2.png" align="justified" width="300" height="300"/>

# Masking
1. Masking is an image processing method in which we define a small 'image piece' and use it to modify a larger image.  
2. When talking about editing and processing images the term 'masking' refers to the practice of using a mask to protect a specific area of an image, just as you would use masking tape when painting your house. 
3. Masking an area of an image protects that area from being altered by changes made to the rest of the image.
4. Masking is the process that is underneath many types of image processing, including edge detection, motion detection, and noise reduction
5. Usually binary masks are used (BLACK and WHITE)
6. Generally, BLACK portions are those which are undesired and want to be removed/ masked off
6. Generally, WHITE portions are those which are desired and want to be retained in the original image


The purpose of this code is to understand the basics of masking.
It tries to do so by taking an input image and creating a png with a transparent background from the "fake png's" users might have downloaded.


## Working
1. We define a Mat container ```image``` which takes in an input image from the user.
2. We then call our function ```Mat masking(Mat image)``` which takes in the user input image as it's argument and returns the final image as another Mat container aka image.
3. The function achieves it's simple masking operation by comparing the RGB values of pixels with the RGB values of colours to be masked/ignored.
if their values match we do not write anything to our new image.
If the values of the RGB to be neglected don't match with the current pixel RGB values, we then write it to our new transparent image.
4.The program then returns the new image, saves it and displays it on the user screen.

## Usage
1. Navigate to ../Pixels_Seminar/4_cv_basics/5_masking
2. Open terminal in this folder
3. run   ```make clean``` to lean out any previous builds
4. type ```make build FILE=5_Masking_Basics.cpp``` to build the executable
5. run ```make run FILE=5_Masking_Basics.cpp```
6. You should now have an imshow window open showing you the output as well as a newly created image in your folder named ```true_logo.png``` which you can view with your image viewer (recommended) 
