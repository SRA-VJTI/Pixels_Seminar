# CROPPING OF IMAGES

The most popular of all image processing applications is image cropping. OpenCV offers functionality to do the same.

### Steps:
1. Read an image from the directory and convert it to the Mat format.
2. Declare two more Mat objects.
3. Obtain the dimensions of the image using the *size()* function.
4. Resize the image using the *resize()* function which takes in the size of the final image as the last parameter. Since in the example, the final size is half the initial size, alternate rows of pixels would be removed.
5. To crop an image, we use the *Rect()* function. This takes the coordinates of the diagonals of the rectangle which is to be cropped out of the image.
6. Finally, we display the images that we have created.