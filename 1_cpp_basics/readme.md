#                    **Basics Of C++**

## **Table Of Contents :**

* [Type Casting](#type-casting)
* [Namespace](#namespace)
* [Enumeration](#enumeration)
* [Arrays](#arrays)
  * [Initializing Arrays](#initializing-arrays)
  * [ Array Accessing](#array-accessing)
  * [Multidimensional Arrays](#multidimensional-arrays)
  * [Printing a 2D array](#printing-a-2d-array)
* [Pointers](#pointers)
* [Pointers And Array](#pointers-and-array)
* [Passing 2D Array To A Function](#passing-2d-array-to-a-function)
* [Vectors](#vectors)
* [OpenCV Mat](#opencv-mat)


## **Type Casting:**
 Type casting refers to the conversion of one data type to another in a program. Typecasting can be done in two ways: automatically by the compiler and manually by the programmer or user. Type Casting is also known as Type Conversion.
 
 1.**Implicit Type Conversion** also known as ‘automatic type conversion’.
Done by the compiler on its own, without any external trigger from the user.
```C++
// An example of implicit conversion

#include <iostream>
using namespace std;

int main()
{
	int x = 10; // integer x
	char y = 'a'; // character c

	// y implicitly converted to int. ASCII
	// value of 'a' is 97
	x = x + y;

	// x is implicitly converted to float
	float z = x + 1.0;

	cout << "x = " << x << endl
		<< "y = " << y << endl
		<< "z = " << z << endl;

	return 0;
}
```
2. **Explicit Type Conversion:** This process is also called type casting and it is user-defined. Here the user can typecast the result to make it of a particular data type.

**Synatx:**

**`(type)expression`**

```C++
// C++ program to demonstrate
// explicit type casting

#include <iostream>
using namespace std;

int main()
{
	float x = 1.2;

	// Explicit conversion from double to int
	int sum = (int)x + 1;

	cout << "Sum = " << sum;

	return 0;
}
```
**Output:**
**`Sum = 2`**

## **Namespace:**
Namespace provide the space where we can define or declare identifier i.e. variable,  method, classes.Using namespace, you can define the space or context in which identifiers are defined i.e. variable, method, classes. In essence, a namespace defines a scope.

Example, you might be writing some code that has a function called xyz() and there is another library available which is also having same function xyz(). Now the compiler has no way of knowing which version of xyz() function you are referring to within your code.
A namespace is designed to overcome this difficulty and is used as additional information to differentiate similar functions, classes, variables etc. with the same name available in different libraries. 

A namespace definition begins with the keyword namespace followed by the namespace name as follows:
```C++
namespace  namespace_name 
{
    // code declarations i.e. variable  (int a;)
    method (void add();)
    classes ( class student{};)
}
```

```C++
#include <iostream>
using namespace std;
// first name space
namespace first_space
{
void func()
{
	cout << "Inside first_space" << endl;
}
}

// second name space
namespace second_space
{
void func()
{
	cout << "Inside second_space" << endl;
}
}
using namespace first_space;
int main ()
{
// This calls function from first name space.
func();
return 0;
}
```
**Output:**

**`Inside first_space`**

## **Enumeration:**

Enum, which is also known as enumeration, is a user-defined data type that enables you to create a new data type that has a fixed range of possible values, and the variable can select one value from the set of values.nums or enumerations are generally used when you expect the variable to select one value from the possible set of values. It increases the abstraction and enables you to focus more on values rather than worrying about how to store them.

**Synatx:**
```C++
enum name_of_enum
{Element_1,
 Element_2,
 Element_3,
 Element_4};
```
```C++
#include <iostream>
using namespace std;

enum seasons { spring = 34, summer = 4, autumn = 9, winter = 32};

int main() {

    seasons s;

    s = summer;
    cout << "Summer = " << s << endl;

    return 0;
}
```

**Output:**

**`Summer = 4`**

In the above code we first made an enum datatype `seasons` ,having elements `spring,summer,autumn and winter` and assigned them values of 34,4,9,32 respectively.Then we made a variable `s` of data type `seasons` i.e enum and assigned it the value of `summer`i.e value of summer(4) is stored in `s` variable.  

## **Arrays :**
 An array is a collection of elements of the same type placed in contiguous memory locations that can be individually referenced by using an index to a unique identifier.

Five values of type int can be declared as an array without having to declare five different variables (each with its own identifier).

For example, a five element integer array foo may be logically represented as;

![array](https://i.imgur.com/TAHEqe6.jpg)

where each blank panel represents an element of the array. In this case, these are values of type int. These elements are numbered from 0 to 4, with 0 being the first while 4 being the last; In C++, the index of the first array element is always zero.

 A typical declaration for an array in C++ is:
 
 ```C++
 type name [elements];
``` 
 where type is a valid type (such as int, float ...), name is a valid identifier and the elements field (which is always enclosed in square brackets []), specifies the size of the array. 

Thus, the foo array, with five elements of type int, can be declared as:

```C++
**`int foo [5]`**;
```

## **Initializing Arrays :**
The elements in an array can be explicitly initialized to specific values when it is declared, by enclosing those initial values in braces {}. The number of values between braces {} shall not be greater than the number of elements in the array. For example:
```C++
int foo [5] = { 16, 2, 77, 40, 12071 };
```
 This statement declares an array that can be represented like this:
![array](https://i.imgur.com/TOGDgk5.jpg)

 ## **Array Accessing :**
**The syntax is:**
   
**`name[index]`** 
  
   For example, the following statement stores the value 75 in the third element of foo:

foo [2] = 75;
```C++
int foo[5];         // declaration of a new array`**

 foo[2] = 75;        // access to an element of the array.`**
```

- ## **Multidimensional Arrays :**

A two-dimensional array in C++ is the simplest form of a multi-dimensional array. It can be visualized as an array of arrays. The image below depicts a two-dimensional array:

![array](https://i.imgur.com/U2rhDGD.png)

**We can  initialize a 2D array in the following way.**
```C++
int arr[4][2] = {
{1234, 56},
 {1212, 33},
 {1434, 80},
 {1312, 78}
} ;
```

**We can also initialize in following way :**

```C++
int arr[4][2] = {1234, 56, 1212, 33, 1434, 80, 1312, 78};
```
## **Printing a 2D Array:**

```C++
#include<iostream>
using namespace std; 
int main( ) 
{  
	int arr[4][2] = {
		{ 10, 11 },
		{ 20, 21 },
		{ 30, 31 },
		{ 40, 41 }
		} ;
		
	int i,j;
	
	cout<<"Printing a 2D Array:\n";
	for(i=0;i<4;i++)
	{
		for(j=0;j<2;j++)
		{
			cout<<"\t"<<arr[i][j];
		}
		cout<<endl;
	}
    return 0;
} 
```

In the above code

   1.  We firstly initialize a 2D array, arr[4][2] with certain values,
    
 2. After that, we try to print the respective array using two for loops
    
3. the outer for loop iterates over the rows, while the inner one iterates over the columns of the 2D array.

4. So, for each iteration of the outer loop, i increases and takes us to the next 1D array. Also, the inner loop traverses over the whole 1D array at a time.

5.  And accordingly, we print the individual element arr[ i ][ j ].

- ## **Pointers :**

A pointer is a variable that stores the memory address of an object. Pointers are used extensively in both C and C++ for three main purposes:

1. To allocate new objects on the heap.
    
2. To pass functions to other functions.
    
3. To iterate over elements in arrays or other data structures.

 **The syntax is:**
```C++
  datatype *var_name; 
  ```
   
  

``` C++
    #include <iostream>  
    using namespace std;  
    int main()  
    {  
    int number=30;    
    int ∗p;      
    p=&number;//stores the address of number variable    
    cout<<"Address of number variable is:"<<&number<<endl;    
    cout<<"Address of p variable is:"<<p<<endl;    
    cout<<"Value of p variable is:"<<*p<<endl;    
       return 0;  
    }  
   
 ```
   
 **The output of above code is :**

 ![image](https://i.imgur.com/kCnRVPq.png)
 
 In the above code:
 1. We first created a integer **`number`** and assigned it the value 30 .
 2. Then created a pointer **`p`** using(*) operator of type **`int`**.
 3. The address of **`number`** is assigned to the **`p`** pointer with the help of  **`&(reference) operator`**.
 4. We can get the value stored at address of **`number`** we use **`*(Dereference) operator`**.

  ##  **Pointers And Array :**

 Not only can a pointer store the address of a single variable, it can also store the address of cells of an array.The name of an array is considered às a pointer, i.e., the name of an array contains the address of an element. C++ considers the array name as the address of the first element

 Here is an example of pointer to a 2D array:

 ``` C++
 #include<iostream>
using namespace std;
/* Usage of pointer to an array */ 
int main( ) 
{  
      int  a[4][2] = {
           {1, 2},
           {1, 2},
           {1, 2},
           {1, 2}
           } ;
           
      int (*ptr)[2] ;
      int  i, j;
      for (i = 0 ; i <= 3 ; i++)
      {
      		ptr=&a[i];
      		cout<<"Row"<<i<<":";
            for (j = 0; j <= 1; j++)
                cout<<"\t"<<*(*ptr+j);
            cout<<endl;
      } 
    return 0;  
}
```
The output is:

![outout](https://i.imgur.com/aA7IBsy.png)

Here,

1. In the above code, we try to print a 2D array using pointers,
2. As we earlier did, at first we initialize the 2D array, s[5][2]. And also a pointer (*p)[2], where p is a pointer which stores the address of an array with 2 elements,
3. As we already said, we can break down a 2D array as an array of arrays. So in this case, s is actually an array with 5 elements, which further are actually arrays with 2 elements for each row.
4. We use a for loop to traverse over these 5 elements of the array, s. For each iteration, we assign p with the address of s[i],
5. Further, the inner for loop prints out the individual elements of the array s[i] using the pointer p. Here, (*p + j) gives us the address of the individual element s[i][j], so using *(*p+j) we can access the corresponding value.

## **Passing 2D Array To A Function :**

C++ does not allow to pass an entire array as an argument to a function. However, You can pass a pointer to an array by specifying the array's name without an index. There are three ways to pass a 2D array to a function :

**1. Specify the size of columns of 2D array**

**`void processArr(int a[][10]) {`**
**` // Do something`**
**`}`**

**2. Pass array containing pointers**

**`void processArr(int *a[10]) {`**
   **`// Do Something`**
**`}`**

**3. Pass a pointer to a pointer**

**`void processArr(int **a) {`**
   **`// Do Something`**
**`}`**

**Example :**

```C++
#include<iostream>
using namespace std;   
 
void display(int (*ptr)[4], int  row, int  col)
{
	int  i, j ;
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
    		cout<<"\t"<<*(*(ptr + i)+j); 
		cout<<"\n";
	}  
    cout<<"\n";
} 
 
void print(int  ptr[][4], int row, int col)
{
    int  i, j; 
    for(i=0;i<row;i++)
    {   
	 for(j=0;j<col;j++)
   	    	cout<<"\t"<<ptr[i][j];
   	 cout<<"\n";
	}
   cout<<"\n";
}
 
int main() 
{
  int  a[3][4] = { 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21} ; 
 
  display (a, 3, 4);
  print (a, 3, 4);
  return 0;
}
```

Here,

1. In the display( ) function we have defined q to be a pointer to an array of 4 integers through the declaration int (*ptr)[4],
2. ptr holds the base address of the zeroth 1-D array
3. This address is then assigned to ptr, an int pointer, and then using this pointer all elements of the zeroth 1D array are accessed.
4. Next time through the loop when i takes a value 1, the expression ptr+i fetches the address of the first 1-D array. This is because ptr is a pointer to the zeroth 1-D array and adding 1 to it would give us the address of the next 1-D array. This address is once again assigned to q and using it all elements of the next 1-D array are accessed
5. In the second function print(), the declaration of ptr looks like this: int ptr[][4] ,
6. This is same as int (*ptr )[4], where ptr is a pointer to an array of 4 integers. The only advantage is that we can now use the more familiar expression ptr[i][j] to access array elements. We could have used the same expression in display() as well but for better understanding of the use of pointers, we use pointers to access each element.

## **Vectors :**

In C++, vectors are used to store elements of similar data types. However, unlike arrays, the size of a vector can grow dynamically.

That is, we can change the size of the vector during the execution of a program as per our requirements.Vectors are part of the C++ Standard Template Library. To use vectors, we need to include the vector header file in our program.

**Syntax is :**

**`vector<object_type> v1; `**

**1. We can initialise vectors with different methods. They are shown** **in code below:**

```C++
#include <iostream>
#include <vector>
using namespace std;

int main() {

  // initializer list
  vector<int> vector1 = {1, 2, 3, 4, 5};

  // uniform initialization
  vector<int> vector2{6, 7, 8, 9, 10};

  // method 3
  vector<int> vector3(5, 12);
  // Here 5 is the size of vector and 12 is the value.

  cout << "vector1 = ";

  // ranged loop
  for (const int& i : vector1) {
    cout << i << "  ";
  }

  cout << "\nvector2 = ";

  // ranged loop
  for (const int& i : vector2) {
    cout << i << "  ";
  }

  cout << "\nvector3 = ";

  // ranged loop
  for (int i : vector3) {
    cout << i << "  ";
  }

  return 0;
}
```
**Output :**

![output](https://i.imgur.com/nqsiMAI.png)

**2. Add Elements to a Vector :**
```C++
#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> num {1, 2, 3, 4, 5};

  cout << "Initial Vector: ";

  for (const int& i : num) {
    cout << i << "  ";
  }
  
  // add the integers 6 and 7 to the vector
  num.push_back(6);
  num.push_back(7);

  cout << "\nUpdated Vector: ";

  for (const int& i : num) {
    cout << i << "  ";
  }

  return 0;
}
```
Here, we have initialized an int vector num with the elements {1, 2, 3, 4, 5}. Here, the **`push_back()`** function adds elements 6 and 7 to the vector.

**Output :**
![output](https://i.imgur.com/zrPaav5.png)

**3. Access Elements of a Vector :**

```C++
#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> num {1, 2, 3, 4, 5};

  cout << "Element at Index 0: " << num.at(0) << endl;
  cout << "Element at Index 2: " << num.at(2) << endl;
  cout << "Element at Index 4: " << num.at(4);

  return 0;
}
```

We use the index number to access the vector elements. Here, we use the **`at()`** function to access the element from the specified index.

**Output :**

![output](https://i.imgur.com/bOxhXIl.png)


 ## **OpenCV MAT**

The images captured using cameras, scanners etc. capture the numerical values at each points of the image which are nothing but the values of the pixels at those points and in order to store and handle the images in the form of a matrix and to manage the memory associated with the images, we make use of class called Mat in OpenCV and by making use of Mat class in OpenCV, the memory management happens automatically and the memory allocated for a Mat class object can be reused and this class is available in the package opencv2/core.hpp in the OpenCV C++ library.

1. **Constructing an OpenCV Mat Object from C++ Array**

``` C++
include <cstring>
#include <iostream>
#include <string.h>
#include <vector>

#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>

using std::cout;
using std::endl;

int main() {

    // Construct from and array
    uint8_t greyArr[11][11] = {
        { 0, 25, 50, 75, 100, 125, 150, 175, 200, 225, 255 },
        { 0, 25, 50, 75, 100, 125, 150, 175, 200, 225, 255 },
        { 0, 25, 50, 75, 100, 125, 150, 175, 200, 225, 255 },
        { 0, 25, 50, 75, 100, 125, 150, 175, 200, 225, 255 },
        { 0, 25, 50, 75, 100, 125, 150, 175, 200, 225, 255 },
        { 0, 25, 50, 75, 100, 125, 150, 175, 200, 225, 255 },
        { 0, 25, 50, 75, 100, 125, 150, 175, 200, 225, 255 },
        { 0, 25, 50, 75, 100, 125, 150, 175, 200, 225, 255 },
        { 0, 25, 50, 75, 100, 125, 150, 175, 200, 225, 255 },
        { 0, 25, 50, 75, 100, 125, 150, 175, 200, 225, 255 },
        { 0, 25, 50, 75, 100, 125, 150, 175, 200, 225, 255 }
    };

    cv::Mat greyImg = cv::Mat(11, 11, CV_8U, &greyArr);
    std::string greyArrWindow = "Grey Array Image";
    cv::namedWindow(greyArrWindow, cv::WINDOW_AUTOSIZE);
    cv::imshow(greyArrWindow, greyImg);

    cv::waitKey(0);
    cv::destroyAllWindows();

    return 0;
}
```

Above is an example of creating a Mat object from a standard C++ two dimensional (ie, nested) array of unsigned 8 bit integers representing grey scale color intensities from black (0) to white (255). In this example we have specified the dimensions, in rows and columns, of the Mat object being constructed as well as the data type of CV_8U indicating a single channel 8 bit unsigned integer, also defined as a uchar in OpenCV. We then used the HighGUI library to display the Mat object populated with a gradient of intensities of grey pixels within a named window.

**Output :**

![image](https://i.imgur.com/2rP7TPs.png)

2. **OpenCV program in C++ to create a matrix using Mat function and** **display the matrix as the output on the screen.**

```C++
//including all the necessary headers
#include "opencv2/core.hpp"
#include <iostream>
#include <opencv2/opencv.hpp>
//defining the namespace std and cv
using namespace std;
using namespace cv;
void main()
{
//creating a matrix using mat function and displaying the matrix as the output on the screen
Mat Mvalue(4, 4, CV_8UC3, Scalar(1, 0, 1));
cout<<"The resulting matrix is:\n";
cout << "Mvalue = " << endl << " " << Mvalue << endl << endl;
}
```
Here we have used `cout` instead of `imshow` and hence we get a matrix as an output on terminal.

**Output :**

![image](https://i.imgur.com/iENpEyD.png)

3. **Constructing an OpenCV Mat Object from C++ Vector :**

Pixel data residing in the standard C++ vector can also be used to construct an OpenCV Mat object in a manner very similar to what is shown above in the array example. The major difference being you must call the data() method of the vector class like so.

```C++
#include <algorithm>
#include <cstring>
#include <iostream>
#include <string.h>
#include <vector>

#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>

using std::cout;
using std::endl;

int main() {

	// ... omitting the previous examples for brevity

    std::vector<uint8_t> vec = {
        0,   0,   0,   0,   0,   0,
        25,  25,  25,  25,  25,  25,
        50,  50,  50,  50,  50,  50,
        75,  75,  75,  75,  75,  75,
        100, 100, 100, 100, 100, 100,
        125, 125, 125, 125, 125, 125,
        150, 150, 150, 150, 150, 150,
        175, 175, 175, 175, 175, 175,
        200, 200, 200, 200, 200, 200,
        225, 225, 225, 225, 225, 225,
        255, 255, 255, 255, 255, 255
    };
    cv::Mat greyImgFromVec(11, 6, CV_8U, vec.data());
    std::string greyImgFromVecWindow = "Grey Image From Vec";
    cv::namedWindow(greyImgFromVecWindow);
    cv::imshow(greyImgFromVecWindow, greyImgFromVec);

    cv::waitKey(0);
    cv::destroyAllWindows();

    return 0;
}
```
**Output :**

![image](https://i.imgur.com/tijRwaX.png)

4. **Copying vector Data Into an OpenCV Mat Object :**

The method of copying vector data into a Mat object is done in a similar fashion as seen in the array example utilizing the memcpy function. However, to demonstrate yet another way of constructing a Mat object we will utilize the Size class from OpenCV to specify the dimensions of the Mat object being constructed but, do note the order of dimensions are switched when using the Size object whereby the number of columns is supplied first then followed by the rows which differs from the rows then columns order of the previously shown Mat constructors

```C++
#include <algorithm>
#include <cstring>
#include <iostream>
#include <string.h>
#include <vector>

#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>

using std::cout;
using std::endl;

int main() {
	// ... omitting above examples for brevity

    std::vector<uint8_t> vec = {
        0,   0,   0,   0,   0,   0,
        25,  25,  25,  25,  25,  25,
        50,  50,  50,  50,  50,  50,
        75,  75,  75,  75,  75,  75,
        100, 100, 100, 100, 100, 100,
        125, 125, 125, 125, 125, 125,
        150, 150, 150, 150, 150, 150,
        175, 175, 175, 175, 175, 175,
        200, 200, 200, 200, 200, 200,
        225, 225, 225, 225, 225, 225,
        255, 255, 255, 255, 255, 255
    };
    // ... omitting example for brevity

    // again, the memcpy function can be used to copy a vector's data into
    // a Mat object similar to what was shown with the array example previously.
    cv::Mat greyImgForVecCopy = cv::Mat(cv::Size(6, 11), CV_8U);
    std::memcpy(greyImgForVecCopy.data, vec.data(), vec.size() * sizeof(uint8_t));

    std::fill(std::begin(vec), std::end(vec), 100);

    std::string greyImgFromVecCopyWindow = "Grey Image Vec Copy";
    cv::namedWindow(greyImgFromVecCopyWindow);
    cv::imshow(greyImgFromVecCopyWindow, greyImgForVecCopy);

    cv::waitKey(0);
    cv::destroyAllWindows();

    return 0;
}
```
**Output :**

![image](https://i.imgur.com/tijRwaX.png)




   









