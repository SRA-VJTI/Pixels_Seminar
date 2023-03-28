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
