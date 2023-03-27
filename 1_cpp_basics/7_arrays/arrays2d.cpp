#include <iostream>
using namespace std;
int main()
{
	int arr[4][2] = {// An array with 4 rows and 2 columns is made and initialized
					 {10, 11},
					 {20, 21},
					 {30, 31},
					 {40, 41}};

	int i, j; // Two variables for looping

	cout << "Printing a 2D Array:\n";
	for (i = 0; i < 4; i++) // traversing through row
	{
		for (j = 0; j < 2; j++) // traversing through column
		{
			cout << "\t" << arr[i][j];
		}
		cout << endl;
	}
	return 0;
}
