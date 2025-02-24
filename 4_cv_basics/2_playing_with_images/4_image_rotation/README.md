# Image Rotation with OpenCV

Rotation and Translation are affine transformations on images, i.e., the collinearity of the points on the images is maintained. This means that those points which remained on a line before the transformation remain preserved on a same line after the transformation.

Image rotation is done keeping a point as a reference (here the center of the image) and rotating the image using the *warpAffine()* function.

---

This guide explains how to rotate images using OpenCV with C++. You'll learn how to compile and run the code, and understand the image rotation process using affine transformations.

---

## Directory Structure
Navigate to the folder containing the source code:

```bash
cd 4_cv_basics/2_playing_with_images/4_image_rotation
```

---

## Compilation
Compile the `main.cpp` file using the following command:

```bash
g++ -std=c++11 main.cpp -o image_rotation `pkg-config --cflags --libs opencv4`
```

✅ **Tip:** Ensure you have OpenCV installed and `pkg-config` set up correctly.

---

## Running the Program
Run the compiled executable:

```bash
./image_rotation
```

Upon running, the program will:
- Read and display the original image.
- Rotate the image by a specified angle (90° in this example).
- Display the rotated image in a new window.

---

## How the Code Works
1. **Reading the Image:** Loads an image from the `./assets/` directory.
2. **Rotate Function:**  
   - Takes an image and rotation angle as inputs.  
   - Calculates the rotation matrix using `cv::getRotationMatrix2D` centered at the image's midpoint.  
   - Applies the rotation using `cv::warpAffine`.  
3. **Displaying the Result:** Shows the rotated image in a separate window.

---

## Example Output
- **Original Image:** Displays the original image loaded from `./assets/dog.jpeg`.
- **Rotated Image:** Image rotated 90° clockwise.

*(Insert images here if available for visual reference.)*

---

## Troubleshooting
- **Image Not Found:** Make sure `dog.jpeg` exists in the `./assets/` folder. Adjust the file path if needed.
- **OpenCV Installation Issues:** Verify with:
  ```bash
  pkg-config --modversion opencv4
  ```
- **Window Not Displaying:** Ensure you have GUI support and check for console errors.
- **Permission Issues:** Make the compiled file executable:
  ```bash
  chmod +x image_rotation
  ```

---

## Conclusion
This exercise demonstrates how to rotate images in OpenCV using affine transformations. Experiment with different angles to see how the rotation affects the image.

---

## Resources
- [OpenCV Affine Transformations Documentation](https://docs.opencv.org/)
- [C++ Reference Guide](https://en.cppreference.com/)


