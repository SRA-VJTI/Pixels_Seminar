## TRANSLATION OF IMAGES

This is another type of Affine transformation where the image is shifted in the 2D plane through fixed distances on the x and y axes.

### Steps:
1. The image is first read and stored in the Mat format.
2. The distances in the x and y axes are defined through which the image has to be moved (tx and ty respectively).
3. The translation matrix which is a two dimensional matrix is created using these values. This matrix contains information for the image to be moved in the x and y directions.
4. Providing positive values for tx will shift the image to right and negative values will shift the image to the left. Similarly, positive values of ty will shift the image down while negative values will shift the image up.

*This is the original image*

![dog](https://user-images.githubusercontent.com/103985810/227202371-1396fd0a-ce7a-4150-a6ce-59fa2ab8ea76.jpeg)

*This is the translated image*

![translated](https://user-images.githubusercontent.com/103985810/227202475-8d0775a5-475f-46c2-8139-46476fa065a3.png)
