## TRANSLATION OF IMAGES

This is another type of Affine transformation where the image is shifted in the 2D plane through fixed distances on the x and y axes.

### Steps:
1. The image is first read and stored in the Mat format.
2. The distances in the x and y axes are defined through which the image has to be moved (tx and ty respectively).
3. The translation matrix which is a two dimensional matrix is created using these values. This matrix contains information for the image to be moved in the x and y directions.
4. Providing positive values for tx will shift the image to right and negative values will shift the image to the left. Similarly, positive values of ty will shift the image down while negative values will shift the image up.

*This is the original image*

![dog](../assets/window.png)

*This is the translated image*

![translated](../assets/Translated.png)
