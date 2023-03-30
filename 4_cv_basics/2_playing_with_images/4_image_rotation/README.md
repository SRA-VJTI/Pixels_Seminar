# ROTATION OF IMAGES

Rotation and Translation are affine transformations on images, i.e., the collinearity of the points on the images is maintained. This means that those points which remained on a line before the transformation remain preserved on a same line after the transformation.

Image rotation is done keeping a point as a reference (here the center of the image) and rotating the image using the *warpAffine()* function.

*This is the original image*

![dog](https://user-images.githubusercontent.com/103985810/227202034-a533a8c5-39f2-4520-82a8-25c30b3ded36.jpeg)

*This is the rotated image*

![rotated](https://user-images.githubusercontent.com/103985810/227202114-6e76ef24-4cd1-438d-9d81-053ec39e8698.png)

## Usage Instructions
1. Navigate to ```../Pixels_Seminar/4_cv_basics/2_playing_with_images/4_image_rotation```
2. Open terminal in this folder
3. run   ```make clean``` to clean out any previous builds
4. type ```make build``` to build the executable
5. run ```make run```