# Accessing Pixel Values with OpenCV
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
This section is similar to the first one, except that instead of changing the alternate channel values to 0, we are increasing the blue channel values of each pixel to 255, i.e., the maximum value.

The steps here almost remain the same. Instead of choosing 0, the user must choose 1 to execute this functionality.
Here again, with the help of 2 for loops and the .at operator, we set the values of the blue channel to 255.

On observation, we see that the images in the Mat format are stored by default in the BGR format and they are accessed in the same order, i.e., 0 for Blue, 1 for Green and 2 for Red.

*This is the original image*

![Original Image](https://user-images.githubusercontent.com/103985810/226842324-3afe2553-e5d7-402f-92e9-ff59e7c57cf2.jpeg)

*On choosing option 0*

![Option 0 result](https://user-images.githubusercontent.com/103985810/226842865-4e4b8ca7-6d49-47a4-b50c-86fb07ea693e.png)

*On choosing option 1*

![Option 1 result](https://user-images.githubusercontent.com/103985810/226843490-d960e0c4-1ee1-4448-b076-c35d6113bf85.png)


---

This guide walks you through accessing and manipulating pixel values in images using OpenCV with C++. Follow the steps below to compile and run the code, and see how pixel access works in practice.

---

## Directory Structure
Navigate to the project folder containing the source code:

```bash
cd 4_cv_basics/2_playing_with_images/0_accessing_pixels
```

---

## Compilation
Compile the `main.cpp` file using the following command:

```bash
make -f ../Makefile build SRC=main.cpp  
```

---

## Running the Program
Run the compiled executable:

```bash
./main
```

Upon running, you will be prompted to select an option (**0** or **1**). The output window will vary based on your choice.

---

## Example Outputs
### Option 0: Display Original Image with Accessed Pixels
![Option 0 Output](https://github.com/user-attachments/assets/134550b8-55c7-4d24-9ea4-6d0b89825dd0)

---

### Option 1: Display Modified Image with Pixel Manipulation
![Option 1 Output](https://github.com/user-attachments/assets/8e40d4dd-9bd1-446d-b36c-4b77afbb011c)

---

## Troubleshooting
- **OpenCV Not Found:** Ensure OpenCV is installed and the `pkg-config` command works:
  ```bash
  pkg-config --modversion opencv4
  ```
- **Permission Denied:** Run the following command to make the file executable:
  ```bash
  chmod +x pixel_access
  ```
- **Missing Images:** Ensure the input images are in the same directory or update the image path in `main.cpp`.

---

## Conclusion
This exercise helps you understand how to access and manipulate individual pixel values using OpenCV. Play around with different images and modify the code to deepen your understanding.

---

## Resources
- [OpenCV Documentation](https://docs.opencv.org/)
- [C++ Reference](https://en.cppreference.com/)
