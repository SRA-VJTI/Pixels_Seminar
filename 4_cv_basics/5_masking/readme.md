# Masking
Masking is the process of hiding or covering a particular area, so with this code we try to get actual desired PNG's (With transparent background) from fake supposed PNG's you might have downloaded by performing some logical operations. The part with the background gets masked and we are left with the desired image.
We do this by checking the RGB values of the input image with a reference value.

## Working
1. We define a Mat container ```image``` which takes in an input image from the user.
2. We then call our function ```Mat masking(Mat image)``` which takes in the user input image as it's argument and returns the final image as another Mat container aka image.
3. The function achieves it's simple masking operation by comparing the RGB values of pixels with the RGB values of colours to be masked/ignored.
if their values match we do not write anything to our new image.
If the values of the RGB to be neglected don't match with the current pixel RGB values, we then write it to our new transparent image.
4. The program then returns the new image, saves it and displays it on the user screen.

## Usage
1. Navigate to ../Pixels_Seminar/4_cv_basics/5_masking
2. Open terminal in this folder
3. run   ```make clean``` to lean out any previous builds
4. type ```make build FILE=5_Masking_Basics.cpp``` to build the executable
5. run ```make run FILE=5_Masking_Basics.cpp```
6. You should now have an imshow window open showing you the output as well as a newly created image in your folder named ```bg_free.png``` which you can view with your image viewer (recommended) 
