# ROTATION OF IMAGES

Rotation and Translation are affine transformations on images, i.e., the collinearity of the points on the images is maintained. This means that those points which remained on a line before the transformation remain preserved on a same line after the transformation.

Image rotation is done keeping a point as a reference (here the center of the image) and rotating the image using the *warpAffine()* function.