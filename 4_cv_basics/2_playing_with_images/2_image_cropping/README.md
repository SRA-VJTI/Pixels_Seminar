# Image Cropping and Resizing with OpenCV

The most popular of all image processing applications is image cropping. OpenCV offers functionality to do the same.

### Steps:
1. Read an image from the directory and convert it to the Mat format.
2. Declare three more Mat objects.
3. Obtain the dimensions of the image using the *size()* function.
4. Resize the image using the *resize()* function which takes in the size of the final image as the last parameter. Since in the example, the final size is half the initial size, alternate rows of pixels would be removed.
5. To crop an image, we created another image and declaring with the original image with changed dimentions using the *Range()* function.
6. We created another image in which we crop it using the loop method by creating a image with cropped image dimantions and filling those under loop from original image.
7. Finally, we display all the images that we have created.

*This is the original image*

<img width="250" alt="image" src="https://github.com/user-attachments/assets/6bb351c9-30aa-417b-af28-a040f2949f4f" />


---

This guide walks you through cropping, resizing, and accessing pixel values in images using OpenCV with C++. Follow the steps below to compile and run the code to understand how these image processing techniques work.

---

## Directory Structure
Navigate to the project folder containing the source code:

```bash
cd 4_cv_basics/2_playing_with_images/2_image_cropping
```

---

## Compilation
Compile the `main.cpp` file using the following command:

```bash
g++ -std=c++11 main.cpp -o image_cropping `pkg-config --cflags --libs opencv4`
```

**Note:** Ensure you have OpenCV installed and `pkg-config` set up correctly.

---

## Running the Program
Run the compiled executable:

```bash
./image_cropping
```

Upon running, the program will:
- Read and display the original grayscale image.
- Resize the image to half its original dimensions.
- Display all processed images in separate windows.
---

## Example Outputs
- **Original Image:** Displays the original grayscale image.

<img width="255" alt="image" src="https://github.com/user-attachments/assets/2683f3f0-4fe5-4a74-ab76-0bc1d0747924" />


- **Resized Image:** Shows the image scaled down to 50% of its original size.

<img width="470" alt="image" src="https://github.com/user-attachments/assets/76e44c69-6b94-434b-ab20-88a3e47b887b" />


- **Cropped Image (Slicing):**

<img width="199" alt="image" src="https://github.com/user-attachments/assets/e360cd7a-d1f8-42ba-b91a-ca00fcb4249a" />


---

## Troubleshooting
- **OpenCV Not Found:** Verify your OpenCV installation:
  ```bash
  pkg-config --modversion opencv4
  ```
- **Permission Denied:** Make the file executable:
  ```bash
  chmod +x image_cropping
  ```
- **Image Not Found:** Ensure the image `dog.jpeg` is placed in the `./assets/` directory. Update the image path in the code if needed.
- **Window Not Opening:** Check for errors and ensure GUI display support is enabled on your system.

---

## Conclusion
This exercise demonstrates how to perform basic image operations like cropping, resizing, and pixel access using OpenCV. Experiment with different crop regions, resize scales, and images to gain a deeper understanding.

---

## Resources
- [OpenCV Image Processing Documentation](https://docs.opencv.org/)
- [C++ Reference](https://en.cppreference.com/)





































