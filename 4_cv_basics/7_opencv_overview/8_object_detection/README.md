## Object Detection

#### HSV colorspace

1. HSV (hue, saturation, value) colorspace is a model to represent the colorspace similar to the RGB color model. 2. Since the hue channel models the color type, it is very useful in image processing tasks that need to segment objects based on its color.
2. Variation of the saturation goes from unsaturated to represent shades of gray and fully saturated (no white component).
3. Value channel describes the brightness or the intensity of the color.

<img src="../assets/images/hsv.jpg"/>

The following screenshot shows an HSV colormap for fast color lookup. The x axis denotes hue, with values in (0,180), the y axis (1) denotes saturation with values in (0,255), and the y axis (2) corresponds to the hue values corresponding to S = 255 and V = 255. To locate a particular color in the colormap, just look up the corresponding H and S range, and then set the range of V as (25, 255). For example, the orange color of the fish we are interested in can be searched in the HSV range from (5, 75, 25) to (25, 255, 255), as observed here:

<img src="../assets/images/od_hsv.png"/>

The `inRange()` function from OpenCV was used for color detection. It accepts the HSV input image along with the color range (defined previously) as parameters.

`cv::inRange()` accepts three parameters—the input image, and the lower and upper limits of the color to be detected, respectively. It returns a binary mask, where white pixels represent the pixels within the range and black pixels represent the one outside the range specified.

To change the color of the fish detected, it is sufficient to change the hue (color) channel value only; we don't need to touch the saturation and value channels.

The bitwise arithmetic with OpenCV was used to extract the foreground/background.

### Illustration

<img src="../assets/images/inrange1.jpeg" width = "400" height="550" align = "left"/>

<img src="../assets/images/inrange2.jpeg" width = "400" height="400"/>

### Expected Results

<!-- Object Detection -->
<table>
<tr>
<th colspan="2" style="text-align:center"> OBJECT DETECTION </th>
</tr>
<tr>
<th style="text-align:center"> img</th>
<th style="text-align:center"> hsv </th>
</tr>
<tr>
<td><image src="../assets/images/img.png" alt = "Image1" width = 350 height="200"></td>
<td><image src="../assets/images/hsv.png" alt = "Image1" width = 350 height="200"></td>
</tr>

<tr>
<th style="text-align:center"> mask1</th>
<th style="text-align:center"> mask2 </th>
</tr>
<tr>
<td><image src="../assets/images/mask1.png" alt = "Image1" width = 350 height="200"></td>
<td><image src="../assets/images/mask2.png" alt = "Image1" width = 350 height="200"></td>

<tr>
<th style="text-align:center"> mask</th>
<th style="text-align:center"> target </th>
</tr>
<tr>
<td><image src="../assets/images/mask_od.png" alt = "Image1" width = 350 height="200"></td>
<td><image src="../assets/images/target.png" alt = "Image1" width = 350 height="200"></td>
</tr>
