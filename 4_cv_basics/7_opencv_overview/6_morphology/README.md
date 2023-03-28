## MORPHOLOGICAL OPERATIONS

OpenCV morphological image processing is a procedure for modifying the geometric structure in the image. In morphism, we find the shape and size or structure of an object. we use morphological operations in computer vision and image processing in the following ways:

<ul>
<li>Removing Noise
<li>Identify intensity bumps or holes in the picture.
<li>Isolation of individual elements and joining disparate elements in image.
</ul>

Normally, morphological operations are done after convolving an image to a specific kernel or spatial filter. In a morphological operation, each image pixel is generated from the value of other pixels in its neighborhood.

Different type of operations

<ul>
<li><b>Dilation</b>: Dilation adds pixels on the object boundaries.
<li><b>Erosion</b>: Erosion removes pixels on object boundaries.
<li><b>Open</b>: Erosion followed by Dilation using the same structuring element for both operations.
<li><b>Close</b>: Dilation followed by Erosion using the same structuring element for both operations.
</ul>

Morphological operations apply a structuring element to an input image, creating an output image of the same size. This structuring element is a matrix of 1’s and 0's.The number of pixels added or removed from the object in an image depends on the shape and size of the structuring element used to process the image. In the morphological dilation and erosion operations, the state of any given pixel in the output image is determined by applying a rule to the corresponding pixel and its neighbors in the input image. The rule used to process the pixels defines the morphological operation as a dilation or an erosion.

### Erosion

Erosion is a fundamental morphological operation in image processing. This operation erodes foreground pixels in an image at their boundaries. After the erosion operation, objects in an image becomes smaller where as the holes within the object (if any) becomes larger. In this technique, each pixel value of the resultant image is calculated as the minimum value of the neighborhood of the pixel defined by the kernel. Erosion increases the darker shades and decreases the whiter shades.

### Dilation

Dilation is much similar to erosion operation. The difference is that the resultant image pixels are calculated as the maximum value of the neighborhood of the pixel defined by the kernel. Dilation increases the whiter shades and decreases the darker shades.

### Opening and Closing operations

Opening and closing are two important operations in image processing. They are derived from the fundamental operations erosion and dilation. Morphological opening is the process of dilating an erode object by a structuring element. It tries to removes small objects from the foreground ( bright pixels) of an image, placing them in the background. Morphological closing on an image is defined as a dilation followed by an erosion. It is used to remove small holes in the foreground, changing small islands of background into foreground.

The combination of opening and closing is generally used to clean up artifacts in the image before using the image for digital analysis.

### Gradient

It is the difference between dilation and erosion of an image.

### Expected Results

<table>
<tr>
<th colspan="2" style="text-align:center"> MORPHOLOGICAL OPERATIONS </th>

</tr>
<td style="text-align:center">
<b>Input Image</b>
</td>
<td style="text-align:center">
<b>Eroded Image</b>
</td>
<tr>

</tr>
<td>
<image src="../assets/images/morphology_opencv1.png">
</td>
<td>
<image src="../assets/images/morphology_opencv2.png">
</td>
<tr>

</tr>
<td style="text-align:center">
<b>Dilated Image</b>
</td>
<td style="text-align:center">
<b>Opened Image</b>
</td>
<tr>

</tr>
<td>
<image src="../assets/images/morphology_opencv3.png">
</td>
<td>
<image src="../assets/images/morphology_opencv4.png">
</td>
<tr>

</tr>
<td style="text-align:center">
<b>Closed Image</b>
</td>
<td style="text-align:center">
<b>Gradient of Image</b>
</td>
<tr>

</tr>
<td>
<image src="../assets/images/morphology_opencv5.png">
</td>
<td>
<image src="../assets/images/morphology_opencv6.png">
</td>
<tr>

</table>
