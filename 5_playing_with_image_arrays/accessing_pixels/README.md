# ACCESSING INDIVIDUAL PIXEL VALUES OF IMAGES
This exercise mainly deals with accessing and manipulating the pixel and hence, the colour values of the images. This becomes especially important in image processing operations when we need to change the appearance of an image.

The program is divided into two parts:
    1. Changing alternate rows of the image to black so that it gets a zipped appearance,
    2. Changing the values of the blue channel of the image.

## PART 1
In this section, we change the pixel values of all the channels in alternate rows to 0 so that these rows obtain a black colour.

### Steps:
1. We declare and define the Mat object 'img' and store the image in Mat container format.
2. The function for blacking out rows is defined.
3. The dimensions of the image are obtained and a choice is given to the user. If the choice is 0, this function is executed.
4. In this function, using two for loops and the '.at' operator, the pixel values of alternate rows whose numbers are divisible by 2 are changed to 0.
5. The image is returned and displayed.



## PART 2
This section is similar to the first one, except that instead of changing all the channel values to 0, we are increasing the blue channel values of each pixel to 255, i.e., the maximum value.

The steps here almost remain the same. Instead of choosing 0, the user must choose 1 to execute this functionality.
Here again, with the help of 2 for loops and the .at operator, we set the values of the blue channel to 255.

On observation, we see that the images in the Mat format are stored by default in the BGR format and they are accessed in the same order, i.e., 0 for Blue, 1 for Green and 2 for Red.