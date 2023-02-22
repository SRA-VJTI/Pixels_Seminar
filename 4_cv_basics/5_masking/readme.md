# Masking
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
