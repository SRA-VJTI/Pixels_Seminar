# Image Translation with OpenCV

## TRANSLATION OF IMAGES

This is another type of Affine transformation where the image is shifted in the 2D plane through fixed distances on the x and y axes.

### Steps:
1. The image is first read and stored in the Mat format.
2. The distances in the x and y axes are defined through which the image has to be moved (tx and ty respectively).
3. The translation matrix which is a two dimensional matrix is created using these values. This matrix contains information for the image to be moved in the x and y directions.
4. Providing positive values for tx will shift the image to right and negative values will shift the image to the left. Similarly, positive values of ty will shift the image down while negative values will shift the image up.

This guide walks you through translating (shifting) images using OpenCV with C++. Follow the steps below to compile and run the code to understand how image translation works using both built-in functions and manual pixel manipulation.

---

## Directory Structure
Navigate to the project folder containing the source code:

```bash
cd 4_cv_basics/2_playing_with_images/3_image_translation
```

---

## Compilation
Compile the `main.cpp` file using the following command:

```bash
make -f ../Makefile build SRC=main.cpp  
```

**Note:** Ensure you have OpenCV installed and `pkg-config` set up correctly.

---

## Running the Program
Run the compiled executable:

```bash
./main
```

Upon running, the program will:
- Read and display the original grayscale image.
- Translate the image using OpenCV's `warpAffine` function.
- Perform manual translation using pixel-wise operations.
- Display all processed images in separate windows.

---

## How the Code Works
1. **Reading the Image:** Loads a grayscale image from the `./assets/` directory.
2. **Setting Translation Values:** Calculates translation distances `tx` (horizontal shift) and `ty` (vertical shift) as one-fourth of the image dimensions.
3. **Creating Translation Matrix:** Uses OpenCV's `cv::Mat` to build a 2x3 affine transformation matrix.
4. **Applying Translation:**
   - **Method 1:** Uses `cv::warpAffine` for smooth and efficient translation.
   - **Method 2:** Manually translates the image by shifting pixel values using nested loops.
5. **Displaying Results:** Shows the original, translated (OpenCV method), and manually translated images in separate windows.

---

## Example Outputs
- **Original Image:** Displays the original grayscale image.

  <img width="257" alt="image" src="https://github.com/user-attachments/assets/ffb27737-95a4-4283-bbd2-23b89855068d" />

- **Translated Image:**
  
  <img width="515" alt="image" src="https://github.com/user-attachments/assets/149b9330-c537-470c-b2cf-a8a2636b341c" />


---

## Troubleshooting
- **OpenCV Not Found:** Verify your OpenCV installation:
  ```bash
  pkg-config --modversion opencv4
  ```
- **Permission Denied:** Make the file executable:
  ```bash
  chmod +x image_translation
  ```
- **Image Not Found:** Ensure the image `dog.jpeg` is located in the `./assets/` directory. Update the image path in the code if necessary.
- **Window Not Opening:** Check for errors in the console and ensure GUI display support is enabled on your system.

---

## Conclusion
This exercise demonstrates how to perform image translation using both OpenCV’s built-in functions and manual pixel manipulation. Experiment with different translation values and images to gain a deeper understanding of how affine transformations work.

---

## Resources
- [OpenCV Geometric Transformations Documentation](https://docs.opencv.org/)
- [C++ Reference](https://en.cppreference.com/)


































