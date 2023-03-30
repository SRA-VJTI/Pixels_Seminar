## List of Contents:
1. [Bitwise Operations](#Bitwise-Operations)
    1. [Bitwise AND](#1.-Bitwise-AND-(A-intersection-B))
    2. [Bitwise OR](#2.-Bitwise-OR-(A-union-B))
    3. [Bitwise XOR](#3.-Bitwise-XOR-(Mutually-Exclusive))
2. [Masking](#Masking)
3. [Working](#Working)
4. [Usage Instructions](#Usage)
5. [Example Illustration](#Example)


# Bitwise Operations
When we perform masking, we see for either black or white or any colour and perform operations according to it. We can also perform bitwise operations on the image when we need to extract only the required part of the image.

Consider the following input images:  


![image 1](https://user-images.githubusercontent.com/99654265/227601983-c6f6d6f5-eb45-4ab7-8cb4-90f5f0473a7b.png)
![image 2](https://user-images.githubusercontent.com/99654265/227602241-5a8c4194-9b94-4232-8f62-102255c7edc6.png)

The Bitwise operations we can perform on them are:
#### 1. Bitwise AND (A intersection B)  
![Bitwise AND](https://user-images.githubusercontent.com/99654265/227602694-a658aa5a-5f25-4054-8179-70bb0b09aeb6.png)

#### 2. Bitwise OR (A union B)  
![Bitwise OR](https://user-images.githubusercontent.com/99654265/227602846-882d276a-54db-4297-a3a4-b1fcb37734de.png)

#### 3. Bitwise XOR (Mutually Exclusive)  
![Bitwise XOR](https://user-images.githubusercontent.com/99654265/227610937-ed4dcb0c-3b9a-464c-8315-48e91a9777ea.png)

and finally Bitwise NOT corresponds to A' and B' with respect to set theory.

Results with a subject and the OpenCV logo
![image](https://user-images.githubusercontent.com/99654265/227612770-bf40900d-2a7c-4bda-a7ef-2a730ba3a706.png)



### Masking
Masking is the process of hiding or covering a particular area, so with this code we try to get actual desired PNG's (With transparent background) from fake supposed PNG's you might have downloaded by performing some logical operations. The part with the background gets masked and we are left with the desired image.
We do this by checking the RGB values of the input image with a reference value, here we do that using logical operators.

## Working
1. We define a Mat container ```image``` which takes in an input image from the user.
2. We then call our function ```Mat masking(Mat image)``` which takes in the user input image as it's argument and returns the final image as another Mat container aka image.
3. The function achieves it's simple masking operation by comparing the RGB values of pixels with the RGB values of colours to be masked/ignored.
if their values match we do not write anything to our new image.
If the values of the RGB to be neglected don't match with the current pixel RGB values, we then write it to our new transparent image.
4. The program then returns the new image, saves it and displays it on the user screen.

## Usage
0. (Optional) If you are facing include errors try changing ```#include <opencv2/opencv.hpp>``` to ```#include <opencv4/opencv2/opencv.hpp>```    which might potentially resolve your error, or a simple google search will help.
1. Navigate to ../Pixels_Seminar/4_cv_basics/5_masking
2. Open terminal in this folder
3. run   ```make clean``` to lean out any previous builds
4. type ```make SRC=main.cpp``` to build the executable
5. You should now have an imshow window open showing you the output as well as a newly created image in your ```assets``` folder named ```bg_free.png``` which you can view with your image viewer (recommended) 


## Example
#### Input Image
![Nike.png](https://i.imgur.com/aX8x8QT.png "nike.png")

#### Output Image
![bg_free.png](https://i.imgur.com/xJvIrrn.png "bg_free.png")