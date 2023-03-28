# Reading and Displaying Images

- <b>Mat</b>: Mat is not a function. It is a data structure, a type of variable. Like int, char, string variable types in C++, Mat is a variable of OpenCV, which creates a matrix data structure to load images inside it. In this program, we wrote 'Mat myImage;'. That means we are declaring a matrix variable named 'myImage'.

- <b>namedWindow()</b>: It allocates some memory and creates a window to show the image. It works like a photo frame. In OpenCV, we have to make the function as 'namedWindow("name of the window",flag)'.
- <b>imread()</b>: This function reads an image from a defined location. This program reads the image from 'C:' drive. To use this function, you have to write it as 'imread("location of the image/name of the image with the extension", flag)'.
- <b>imshow()</b>: This function shows the image in the defined window. To use this function you have to write as 'imshow(name of the window", name of the matrix)'.
- <b>waitKey()</b>: This is a vital function of OpenCV. To process images and executes operations, we must allow the system some time. If we don't do it, we will not

This function waits for a certain period before closing the program. If you use waitKey(10000), it will close the program after 10 seconds. If you write waitKey(0), it will get the desired output. This function will enable us to give the system the required time to operate. wait for the keystroke from the user. When the user clicks any key from the keyboard, the program will stop. This function has to be written as 'waitKey(milliseconds)'.

- <b>destroyWindows()</b>: This function closes all windows. When we create windows, we allocate some memory. <b>destroyWindow()</b> function releases that memory to the system.
