/*
MIT License

Copyright (c) 2023 Society of Robotics and Automation

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
#include <iostream>
using namespace std;
/* Usage of pointer to an array */
int main()
{
     int a[4][2] = {// Declaring and initialising a 2D array
                    {1, 2},
                    {1, 2},
                    {1, 2},
                    {1, 2}};

     int(*ptr)[2]; // Declaring a 2D pointer
     int i, j;
     for (i = 0; i <= 3; i++)
     {
          ptr = &a[i]; // Stores the address of Array a with index i, in ptr
          cout << "Row" << i << ":";
          for (j = 0; j <= 1; j++)
               cout << "\t" << *(*ptr + j); // Prints the data at pointed by address ptr+j
          cout << endl;
     }
     return 0;
}
