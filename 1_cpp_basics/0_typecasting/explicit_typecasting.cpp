// C++ program to demonstrate
// explicit type casting

#include <iostream>
using namespace std;

int main()
{
	float x = 1.2;

	// Explicit conversion from double to int
	int sum = (int)x + 1;

	cout << "Sum = " << sum << endl;

	return 0;
}
