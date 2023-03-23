# **Morphology**

## **Table of Contents:**

1. [Basics of Morphology](#basics-of-morphology)
    1. [Erosion](#erosion)
    1. [Dilation ](#dilation)
    1. [Applications of Morphological operations](#applications-of-basic-morphological-operations)
1. [Compound Operations](#compound-morphological-operations)
    1. [Opening](#opening)
    1. [Closing](#closing)
    1. [Gradient](#gradient)
    1. [Applications of Compound Morphological operations](#applications-of-compound-morphological-operations)

## **Basics of Morphology**

- Morphology denotes a branch of biology that deals with the form and structure of animals and plants.

- But as far as image processing is concerned morphology is about regions and shapes. It is used as a **tool for extracting image components**
that are useful in representing regions and shapes.

- Morphological operations rely only on the relative ordering of pixel values, not on their numerical values, and therefore are especially
suited to the processing of binary images.

- It needs two inputs, one is our **original image**, second one is called **structuring element** or **kernel** which decides the nature of operation.

- In a morphological operation, the value of each pixel in the output image is based on a comparison of the corresponding pixel in the input image
and its neighbors with structuring element.

- Two basic morphological operators are **Erosion** and **Dilation**

- Morphological operations are used for preprocessing for OCR algorithms,
detecting barcodes, detecting license plates, and more. 

- And sometimes a clever use of morphological operations can allow you to avoid more complicated (and computationally expensive) machine learning and deep learning algorithms.
  

## **Erosion**

**Basics of Erosion**:
- Erodes away the boundaries of foreground object. 
- Used to diminish the features of an image.

The structuring elements shrinks an image by stripping away a layer of pixels from both the inner and outer boundaries of regions. 

By using erosion, we can eliminate small details and the holes and gaps between different regions become larger. 

In a binary image, a pixel is set to 0 if any of the neighboring pixels have the value 0. Morphological erosion removes islands and small objects
so that only substantive objects remain.

<p align="center">
    <img src = "./assets/normal_image.png" width="200" height="250"/> <img src = "./assets/erroded_image.png"width="200" height="250"/>
</p>  
  

**Working of Erosion**:

1. A kernel (a matrix of odd size 3,5,7..) is convolved with the image.
2. A pixel in the original image (either 1 or 0) will be considered 1 only if all the pixels under the kernel is 1, otherwise it is eroded
(made to zero).
3. Thus all the pixels near boundary will be discarded depending upon the size of kernel.
4. So the thickness or size of the foreground object decreases or simply white region decreases in the image.

  
<p align="center">
    <img src = "./assets/erosion.gif"/>
</p>


## **Dilation**

**Basics of dilation**:
- Increases the object area.
- Used to accentuate features.

The assigned structuring element is used for probing and expanding the shapes contained in the input image.

Dilation has the opposite effect to erosion. It adds a layer of pixels to both the inner and outer boundaries of regions.

That is, the value of the output pixel is the maximum value of all pixels in the neighborhood. In a binary image, a pixel is set to 1 if any
of the neighboring pixels have the value 1. 

Morphological dilation makes objects more visible and fills in small holes in objects.

  
<p align="center">
    <img src="./assets/normal_image.png"width="200" height="250"/> <img src="./assets/dilation.png" width="200" height="250"/>
</p>

**Working of dilation**:
1. A kernel (a matrix of odd size 3,5,7..) is convolved with the image.
2. A pixel element in the output image is ‘1’ if atleast one pixel under the kernel is ‘1’.
3. It increases the white region in the image or size of foreground object increases.

<p align="center">
    <img src="./assets/dilation.gif"/>
</p>  
  
## **Applications of basic morphological operations**:

- Surface metrology. 
- Compound operations

## **Compound Morphological Operations**

- Compound operations are represented as combinations of erosion, dilation, and simple set-theoretic operations such as the complement of
a binary image, intersection and union of two or more binary images. 

- Opening, Closing and Gradient are types of compound operations.

## **Opening**

It is achieved by first eroding an image and then dilating it. Opening removes any narrow connections and lines between two regions.

The opening operation erodes an image and then dilates the eroded image, using the same structuring element for both operations.
Morphological opening is useful for removing small objects from an image while preserving the shape and size of larger objects in the image.

Opening is so called because it can open up a gap between objects connected by a thin bridge of pixels. Any regions that have survived the
erosion are restored to their original size by the dilation:

Results of opening with a square structuring element

<p align="center">
    <img src="./assets/opening.png" width="400" height="250"/>
</p>  

## **Closing**

It is done by first dilating the image and then eroding it. The order is the reverse of opening. Closing fills up any narrow black regions
or holes in the image.

The closing operation dilates an image and then erodes the dilated image, using the same structuring element for both operations.
Morphological closing is useful for filling small holes from an image while preserving the shape and size of the objects in the image.

In this case, the dilation and erosion should be performed with a rotated by 180 structuring element. Typically, the latter is symmetrical,
so that the rotated and initial versions of it do not differ.

<p align="center">
    <img src="./assets/closing.png" width="400" height="250"/>
</p>

## **Gradient**

The difference between the dilation and the erosion of the image. This is used to find boundaries or edges in an image. It recommended to
apply some filtering before calculating the gradient because it is very sensitive to noise.

<p align="center">
    <img src="./assets/gradient.png" width="400" height="250"/>
</p>
    
## **Applications of Compound morphological operations**:

1. Fingerprint feature extraction
2. Recognisation of handwritten characters
3. Edge detection
4. Coin counting and valuation