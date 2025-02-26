# DRAWING SHAPES ON IMAGES

There are many reasons for drawing shapes on images such as for selecting the Region of Interest in computer vision applications, for making annotations, etc. Such shapes can be drawn by using the OpenCV library functions as well.

The first step is to initialise a black image with all pixel values set to 0 and pre-set dimensions.

After that, a line is created using for loops.

---

This guide walks you through drawing basic shapes and text on images using OpenCV with C++. Follow the steps below to compile and run the code to visualize how different drawing functions work.

---

## Directory Structure
Navigate to the project folder containing the source code:

```bash
cd 4_cv_basics/2_playing_with_images/1_drawing_on_images
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

Upon running, a window will display an image with various shapes and text drawn on it. Modify the code to experiment with different colors, shapes, thicknesses, and positions.

---

## Expected Output after running the above code 

<img width="720" alt="image" src="https://github.com/user-attachments/assets/861a2927-712f-4585-aa23-b96fe9119b71" />


---

## Troubleshooting
- **OpenCV Not Found:** Verify your OpenCV installation and run:
  ```bash
  pkg-config --modversion opencv4
  ```
- **Permission Denied:** Make the file executable:
  ```bash
  chmod +x drawing
  ```
- **Window Not Opening:** Check for errors in the console and ensure your system supports GUI display with OpenCV.

---

## Conclusion
This exercise demonstrates how to draw shapes and text on images using OpenCV. Experiment with the code to understand how different drawing functions behave and customize the output as per your requirements.

---

## Resources
- [OpenCV Drawing Functions Documentation](https://docs.opencv.org/)
- [C++ Reference](https://en.cppreference.com/)
