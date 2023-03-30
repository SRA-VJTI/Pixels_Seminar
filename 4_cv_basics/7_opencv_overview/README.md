# Table of Contents

- [Introduction to OpenCV](#introduction-to-opencv)
  - [Computer Vision vs Image Processing](#computer-vision-vs-image-processing)
  - [Applications](#applications-of-computer-vision)
- [Usage](#usage)
- [Function Description](#function-description)
- [Read/Display Image](1_read_display_image)
- [Grayscale](2_grayscale/README.md)
- [Resizing](3_resizing/README.md)
- [Blending](4_blending/README.md)
- [Masking](5_masking/README.md)
- [Morphology](6_morphology/README.md)
- [Contours](7_contours/README.md)
- [Object Detection](8_object_detection/README.md)

# **Introduction to OpenCV**

### _OpenCV_ is a cross-platform library using which we can develop real-time computer vision applications. It mainly focuses on image processing, video capture and analysis including features like face detection and object detection.

1. OpenCV is an Open Source, C++ based API(Application Programming Interface) Library for Computer Vision.
2. It includes several computer vision algorithms.
3. Explore more of OpenCV [here](https://opencv.org/).

- **Computer Vision** :
  Computer Vision can be defined as a discipline that explains how to reconstruct, interrupt, and understand a 3D scene from its 2D images, in terms of the properties of the structure present in the scene. It deals with modeling and replicating human vision using computer software and hardware.

- Computer Vision overlaps significantly with the following fields −

  1. **Image Processing** − It focuses on image manipulation.

  2. **Pattern Recognition** − It explains various techniques to classify patterns.

  3. **Photogrammetry** − It is concerned with obtaining accurate measurements from images.

## **Computer Vision Vs Image Processing :**

1. Image processing deals with image-to-image transformation. The input and output of image processing are both images.

2. Computer vision is the construction of explicit, meaningful descriptions of physical objects from their image. The output of computer vision is a description or an interpretation of structures in 3D scene.

## **Applications of Computer Vision :**

1. **Medicine Application** :

- Classification and detection (e.g. lesion or cells classification and tumor detection)
- 3D human organ reconstruction (MRI or ultrasound)
- Vision-guided robotics surgery

---

2. **Industrial Automation Application**

- Defect detection
- Assembly
- Barcode and package label reading
- Object sorting

---

3. **Security Application**

- Biometrics (iris, finger print, face recognition)

---

4. **Surveillance**:

- Detecting certain suspicious activities or behaviors

---

5. **Transportation Application**

- Autonomous vehicle
- Safety, e.g., driver vigilance monitoring

## Usage

Once the requirements are satisfied, you can easily download the project and use it on your machine.

1. First navigate to the folder `opencv_overview`
2. Navigate to the required folder.

```
 make SRC=<subfolder>/main.cpp
 ./Opencv_overview
```

For example, if the subfolder is `5_masking` then the following commands needs to be executed:

```
make SRC=5_masking/main.cpp
./Opencv_overview
```

## Function Description

Refer this from **google** and [OpenCv Docs](https://docs.opencv.org/master/index.html)

<table>

<tr>
<th>
Sr. No.
</th>
<th>Function Name</th>
<th>Parameters</th>
<th>Description</th>
</tr>

<tr>
<td>1</td>
<td>cv::Mat cv::imread(const cv::String& filename, int flags = cv::IMREAD_COLOR)
</td>
<td><b>filename</b>: A string specifying the path of the image file to be loaded.

<b>flags</b>: An optional integer value specifying the color space of the loaded image. Possible values include:
<b>cv::IMREAD_COLOR</b>: Loads the image in the RGB color space. This is the default value.
<b>cv::IMREAD_GRAYSCALE</b>: Loads the image as a grayscale image.
<b>cv::IMREAD_UNCHANGED</b>: Loads the image as is, including any alpha channel information.</td>

<td>The imread function is used to load an image from a file into a cv::Mat object. The function takes a filename and an optional flag parameter to specify the color space of the loaded image.</td>
</tr>

<tr>
<td>2</td>
<td>void cv::imshow(const cv::String& winname, cv::InputArray mat)
</td>
<td><b>winname</b>: A string specifying the name of the window to display the image in.

<b>mat</b>: A cv::Mat object representing the image to be displayed.</td>

<td>The imshow function is used to display an image in a window.</td>
</tr>

<tr>
<td>3</td>
<td>void cv::cvtColor(cv::InputArray src, cv::OutputArray dst, int code, int dstCn = 0)
</td>
<td><b>src</b>: A cv::Mat object representing the input image.

<b>dst</b>: A cv::Mat object representing the output image.

<b>code</b>: An integer value specifying the color conversion code. This value can be one of the following:

<b>cv::COLOR_BGR2GRAY</b>: Converts an RGB image to grayscale.

<b>cv::COLOR_BGR2HSV</b>: Converts an RGB image to the HSV color space.

<b>cv::COLOR_BGR2Lab</b>: Converts an RGB image to the CIE Lab\* color space.

<b>cv::COLOR_BGR2YCrCb</b>: Converts an RGB image to the YCrCb color space.

<b>cv::COLOR_BGR2XYZ</b>: Converts an RGB image to the CIE XYZ color space.

<b>dstCn</b>: An optional integer value specifying the number of output channels. If set to 0 (default), the number of output channels will be the same as the number of input channels.</td>

<td>The cvtColor function is used to convert an image from one color space to another.</td>
</tr>

<tr>
<td>4</td>
<td>void cv::addWeighted(
    cv::InputArray src1, double alpha, cv::InputArray src2, double beta, double gamma, cv::OutputArray dst, int dtype = -1)
</td>
<td><b>alpha</b>: Weight of the first image, a scalar value of type double.

<b>src2</b>: The second input image, same type as src1.

<b>beta</b>: Weight of the second image, a scalar value of type double.

<b>gamma</b>: A scalar value added to each sum, a scalar value of type double.

<b>dst</b>: Output image, same type as src1 and src2, and of the same size as src1 and src2. Can be cv::Mat, cv::MatExpr, cv::Matx, or cv::UMat.

<b>dtype</b> (optional): The optional depth of the output image. If not specified, it defaults to -1, which means that the output image will have the same depth as the input images.</td>

<td>The addWeighted function multiplies the first input image (src1) by a scalar value alpha, multiplies the second input image (src2) by a scalar value beta, and adds these two weighted images together. Then, it adds a scalar value gamma to each pixel value in the resulting image, and stores the output in dst</td>
</tr>

<tr>
<td>5</td>
<td>double cv::threshold(cv::InputArray src, cv::OutputArray dst, double thresh, double maxval, int thresholdType)
</td>
<td><b>src</b>: The input image, of type cv::Mat, cv::MatExpr, cv::Matx, or cv::UMat.

<b>dst</b>: The output binary image, of the same type and size as src, and of type cv::Mat, cv::MatExpr, cv::Matx, or cv::UMat.

<b>thresh</b>: The threshold value, a scalar value of type double.

<b>maxval</b>: The maximum value to use with the THRESH_BINARY and THRESH_BINARY_INV thresholding types, a scalar value of type double.

<b>thresholdType</b>: The type of thresholding operation to perform, an integer value from the cv::ThresholdTypes enumeration.</td>

<td>The threshold function applies a fixed-level threshold to the input image, which means that it classifies each pixel as either foreground or background based on a threshold value.</td>
</tr>

<tr>
<td>6</td>
<td>void cv::bitwise_and(cv::InputArray src1, cv::InputArray src2, cv::OutputArray dst, cv::InputArray mask = cv::noArray())

</td>
<td><b>src1</b>: The first input array or scalar, of type cv::Mat, cv::MatExpr, cv::Matx, cv::Scalar, or double.

<b>src2</b>: The second input array or scalar, same type as src1.

<b>dst</b>: The output array, of the same type and size as src1 and src2, and of type cv::Mat, cv::MatExpr, or cv::Matx.

<b>mask </b>(optional): An optional operation mask, of type cv::Mat, cv::MatExpr, or cv::Matx. If specified, the operation is only performed on the non-zero elements of mask.</td>

<td>The cv::bitwise_and function performs a bitwise logical AND operation between the elements of two input arrays or scalars (src1 and src2), and stores the result in the output array (dst). The input arrays or scalars must have the same size and type. If one of the inputs is a scalar, it is broadcasted to the size of the other input array.</td>
</tr>

<tr>
<td>7</td>
<td>void cv::bitwise_or(cv::InputArray src1, cv::InputArray src2, cv::OutputArray dst, cv::InputArray mask = cv::noArray())
</td>
<td><b>src1</b>: The first input array or scalar, of type cv::Mat, cv::MatExpr, cv::Matx, cv::Scalar, or double.

<b>src2</b>: The second input array or scalar, same type as src1.

<b>dst</b>: The output array, of the same type and size as src1 and src2, and of type cv::Mat, cv::MatExpr, or cv::Matx.

<b>mask</b> (optional): An optional operation mask, of type cv::Mat, cv::MatExpr, or cv::Matx. If specified, the operation is only performed on the non-zero elements of mask.</td>

<td>The cv::bitwise_or function performs a bitwise logical OR operation between the elements of two input arrays or scalars (src1 and src2), and stores the result in the output array (dst). The input arrays or scalars must have the same size and type. If one of the inputs is a scalar, it is broadcasted to the size of the other input array.</td>
</tr>

<tr>
<td>8</td>
<td>void cv::resize(cv::InputArray src, cv::OutputArray dst, cv::Size dsize, double fx = 0, double fy = 0, int interpolation = cv::INTER_LINEAR)
</td>
<td><b>src</b>: The input image to be resized, of type cv::Mat, cv::MatExpr, or cv::UMat.

<b>dst</b>: The output image, of type cv::Mat, cv::MatExpr, or cv::UMat.

<b>dsize</b>: The new size of the output image, specified as a cv::Size object, or a tuple of (width, height).

<b>fx (optional)</b>: The scale factor along the horizontal axis. If both dsize and fx are zero, the scaling factor is computed as <b>(double)dst.cols / src.cols.</b>

<b>fy (optional)</b>: The scale factor along the vertical axis. If both dsize and fy are zero, the scaling factor is computed as <b>(double)dst.rows / src.rows.</b>

<b>interpolation (optional)</b>: The interpolation method to be used for resizing. It can be one of the following: <b>cv::INTER_NEAREST</b>, <b>cv::INTER_LINEAR</b>, <b>cv::INTER_CUBIC</b>, <b>cv::INTER_AREA</b>, <b>cv::INTER_LANCZOS4</b>, or <b>cv::INTER_LINEAR_EXACT</b>. The default is <b>cv::INTER_LINEAR.</b></td>

<td>The cv::resize function resizes the input image (src) to the specified new size (dsize) and stores the result in the output image (dst). The size of the output image can be specified either as a cv::Size object or a tuple of (width, height).</td>
</tr>

<tr>
<td>9</td>
<td>void cv::bitwise_not(cv::InputArray src, cv::OutputArray dst, cv::InputArray mask = cv::noArray())
</td>
<td><b>src</b>: The input array to be inverted, of type cv::Mat, cv::MatExpr, cv::Matx, cv::Scalar, or double.

<b>dst</b>: The output array, of the same type and size as src, and of type cv::Mat, cv::MatExpr, or cv::Matx.

<b>mask (optional)</b>: An optional operation mask, of type cv::Mat, cv::MatExpr, or cv::Matx. If specified, the operation is only performed on the non-zero elements of mask.</td>

<td>The cv::bitwise_not function inverts the input array (src) bitwise and stores the result in the output array (dst). The input array can be of type cv::Mat, cv::MatExpr, cv::Matx, cv::Scalar, or double.</td>
</tr>

<tr>
<td>10</td>
<td>void cv::bitwise_xor(cv::InputArray src1, cv::InputArray src2, cv::OutputArray dst, cv::InputArray mask = cv::noArray())
</td>
<td><b>src1</b>: The first input array, of type cv::Mat, cv::MatExpr, cv::Matx, cv::Scalar, or double.

<b>src2</b>: The second input array, of the same type and size as src1, and of type cv::Mat, cv::MatExpr, cv::Matx, cv::Scalar, or double.

<b>dst</b>: The output array, of the same type and size as src1 and src2, and of type cv::Mat, cv::MatExpr, or cv::Matx.

<b>mask (optional)</b>: An optional operation mask, of type cv::Mat, cv::MatExpr, or cv::Matx. If specified, the operation is only performed on the non-zero elements of mask.</td>

<td>The cv::bitwise_xor function computes the bitwise exclusive OR (XOR) between the two input arrays (src1 and src2) and stores the result in the output array (dst). The input arrays can be of type cv::Mat, cv::MatExpr, cv::Matx, cv::Scalar, or double.</td>
</tr>

<tr>
<td>11</td>
<td>void cv::inRange(cv::InputArray src, cv::InputArray lowerb, cv::InputArray upperb, cv::OutputArray dst)
</td>
<td><b>src</b>: The input array to be checked against the range boundaries, of type cv::Mat, cv::MatExpr, cv::Matx, cv::Scalar, or double.

<b>lowerb</b>: The lower boundary array or scalar, of the same type as src. If a scalar is used, it is implicitly converted to a single-element array.

<b>upperb</b>: The upper boundary array or scalar, of the same type as src. If a scalar is used, it is implicitly converted to a single-element array.

<b>dst</b>: The output binary array, of type cv::Mat, cv::MatExpr, or cv::Matx, with the same size as src.</td>

<td>The cv::inRange function checks each element of the input array (src) against the corresponding lower and upper boundary values (lowerb and upperb, respectively). If the element is within the specified range, the corresponding element in the output array (dst) is set to 255 (white); otherwise, it is set to 0 (black).</td>
</tr>

<tr>
<td>12</td>
<td>void cv::Canny(cv::InputArray image, cv::OutputArray edges, double threshold1, double threshold2, int apertureSize = 3, bool L2gradient = false)
</td>
<td><b>image</b>: The input single-channel 8-bit or floating-point image, of type cv::Mat, cv::MatExpr, or cv::Matx.

<b>edges</b>: The output binary edge map, of type cv::Mat, cv::MatExpr, or cv::Matx, with the same size as image.

<b>threshold1</b>: The first threshold value for the hysteresis procedure.

<b>threshold2</b>: The second threshold value for the hysteresis procedure. This value should be greater than threshold1.

<b>apertureSize (optional)</b>: The size of the Sobel kernel used for edge detection. By default, apertureSize=3.

<b>L2gradient (optional)</b>: A flag indicating whether to use the L2 norm for gradient calculation. By default, L2gradient=false.</td>

<td>The cv::Canny function applies the Canny edge detection algorithm to the input image (image) and produces a binary edge map in the output array (edges).</td>
</tr>

<tr>
<td>13</td>
<td>void cv::findContours(cv::InputOutputArray image, cv::OutputArrayOfArrays contours, cv::OutputArray hierarchy, int mode, int method, cv::Point offset = cv::Point())
</td>
<td><b>image</b>: The input single-channel 8-bit image, of type cv::Mat, cv::MatExpr, or cv::Matx.

<b>contours</b>: The output vector of detected contours, represented as a vector of points. Each contour is stored as a vector of points.

<b>hierarchy</b>: The output optional vector of contour hierarchies, represented as a vector of integers. Each element in the hierarchy vector corresponds to a contour, and stores information about the relationship between the current contour and its parent, child, and sibling contours. If the hierarchy parameter is set to cv::noArray(), no hierarchy information is computed.

<b>mode</b>: The contour retrieval mode, which determines how the contours are retrieved and represented. Possible values are:

<b>cv::RETR_EXTERNAL</b>: Retrieves only the external contours, i.e., the contours that form the outermost boundary of the object.

<b>cv::RETR_LIST</b>: Retrieves all of the contours without establishing any hierarchical relationships between them.

<b>cv::RETR_CCOMP</b>: Retrieves all of the contours and organizes them into a two-level hierarchy. The first level contains the external contours, while the second level contains the contours of holes inside the external contours. The hierarchy information can be retrieved from the hierarchy output parameter.

<b>cv::RETR_TREE</b>: Retrieves all of the contours and organizes them into a tree hierarchy. Each contour is a child of its parent contour, except for the external contours, which have no parent. The hierarchy information can be retrieved from the hierarchy output parameter.

<b>method</b>: The contour approximation method, which determines how the contours are approximated and represented. Possible values are:
<b>cv::CHAIN_APPROX_NONE</b>: Stores all of the contour points without approximating them.
<b>cv::CHAIN_APPROX_SIMPLE</b>: Approximates the contour by storing only its endpoints. For example, a straight line segment would be stored as its two endpoints.
<b>cv::CHAIN_APPROX_TC89_L1</b>, <b>cv::CHAIN_APPROX_TC89_KCOS</b>: Applies the Teh-Chin chain approximation algorithm with either the L1 or kcos distance metric. These methods tend to produce more accurate approximations than <b>cv::CHAIN_APPROX_SIMPLE</b>, but are also slower.

<b>offset (optional)</b>: An optional offset applied to each contour point. This can be useful for adjusting the contours to match the original image coordinates.</td>

<td>The cv::findContours function detects contours in the input image (image) and stores them in the output contours vector. The function can also compute a hierarchical representation of the contours and store it in the hierarchy vector.</td>
</tr>

<tr>
<td>14</td>
<td>void cv::drawContours(cv::InputOutputArray image, cv::InputArrayOfArrays contours, int contourIdx, const cv::Scalar& color, int thickness = 1, int lineType = cv::LINE_8, cv::InputArray hierarchy = cv::noArray(), int maxLevel = INT_MAX, cv::Point offset = cv::Point())
</td>
<td><b>image</b>: The input/output image, of type cv::Mat, cv::MatExpr, or cv::Matx.

<b>contours</b>: The input vector of contours to draw, represented as a vector of points. Each contour is stored as a vector of points.

<b>contourIdx</b>: The index of the contour to draw. If this parameter is set to -1, all contours are drawn.

<b>color</b>: The color of the contour, specified as a cv::Scalar value.

<b>thickness</b>: The thickness of the contour lines, in pixels. If this parameter is negative, the contour is filled instead of drawn.

<b>lineType</b>: The type of line segments used to draw the contour. Possible values are cv::LINE_4, cv::LINE_8, and cv::LINE_AA

<b>hierarchy</b>: Optional input hierarchy information used to draw only a subset of the contours. If this parameter is set to cv::noArray(), all contours are drawn.

<b>maxLevel</b>: The maximum level in the hierarchy to draw. This parameter is used only if hierarchy is provided.

<b>offset</b>: An optional offset applied to each contour point. This can be useful for adjusting the contours to match the original image coordinates.</td>

<td>The cv::drawContours function draws contours onto the input/output image. The function takes as input a vector of contours (contours) and an index of the contour to draw (contourIdx), and draws the specified contour onto the image.
</td>

<tr>
<td>15</td>
<td>
void cv::erode ( InputArray src,
OutputArray dst,
InputArray kernel,
Point anchor = Point(-1,-1),
int iterations = 1) 
</td>
<td>

<b>src</b>: input image; the number of channels can be arbitrary, but the depth should be one of CV_8U, CV_16U, CV_16S, CV_32F or CV_64F.

<b>dst</b>: output image of the same size and type as src.

<b>kernel</b>: structuring element used for erosion; if element=Mat(), a 3 x 3 rectangular structuring element is used. Kernel can be created using getStructuringElement.

<b>anchor</b>: position of the anchor within the element; default value (-1, -1) means that the anchor is at the element center.

<b>iterations</b>: number of times erosion is applied.

</td>

<td>
Erodes an image by using a specific structuring element.

The function erodes the source image using the specified structuring element that determines the shape of a pixel neighborhood over which the minimum is taken.

</td>
</tr>

<tr>
<td>
16
</td>

<td>
void cv::dilate ( InputArray src,
OutputArray dst,
InputArray kernel,
Point anchor = Point(-1,-1),
int iterations = 1) 
</td>

<td>

<b>src</b>: input image; the number of channels can be arbitrary, but the depth should be one of CV_8U, CV_16U, CV_16S, CV_32F or CV_64F.

<b>dst</b>: output image of the same size and type as src.

<b>kernel</b>: structuring element used for dilation; if element=Mat(), a 3 x 3 rectangular structuring element is used. Kernel can be created using getStructuringElement

<b>anchor</b>: position of the anchor within the element; default value (-1, -1) means that the anchor is at the element center.

<b>iterations</b>: number of times dilation is applied.

</td>

<td>
Dilates an image by using a specific structuring element.

The function dilates the source image using the specified structuring element that determines the shape of a pixel neighborhood over which the maximum is taken.

</td>
</tr>

<tr>
<td>
17
</td>

<td>
void cv::morphologyEx ( InputArray src,
OutputArray dst,
int op,
InputArray kernel,
Point anchor = Point(-1,-1),
int iterations = 1) 
</td>

<td>
<b>src</b>: Source image. The number of channels can be arbitrary. The depth should be one of CV_8U, CV_16U, CV_16S, CV_32F or CV_64F.

<b>dst</b>: Destination image of the same size and type as source image.

<b>op</b>: Type of a morphological operation
<u>Options (MorphTypes)</u>

- MORPH_ERODE
- MORPH_DILATE
- MORPH_CLOSE
- MORPH_OPEN
- MORPH_GRADIENT

<b>kernel</b>: Structuring element. It can be created using getStructuringElement.

<b>anchor</b>: Anchor position with the kernel. Negative values mean that the anchor is at the kernel center.

<b>iterations</b>: Number of times erosion and dilation are applied.

</td>

<td>
Performs advanced morphological transformations.

The function cv::morphologyEx can perform advanced morphological transformations using erosion and dilation as basic operations.

</td>

</table>
