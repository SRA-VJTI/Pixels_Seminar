#include <iostream>
using namespace std;

void display(int (*ptr)[4], int row, int col) // Call by Address
{
	int i, j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
			cout << "\t" << *(*(ptr + i) + j); // Array is printed with help of pointer arithmetic
		cout << "\n";
	}
	cout << "\n";
}

void print(int ptr[][4], int row, int col) // Call by value
{
	int i, j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
			cout << "\t" << ptr[i][j];
		cout << "\n";
	}
	cout << "\n";
}

int main()
{
	int a[3][4] = {10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21};

	display(a, 3, 4);
	print(a, 3, 4);
	return 0;
}
