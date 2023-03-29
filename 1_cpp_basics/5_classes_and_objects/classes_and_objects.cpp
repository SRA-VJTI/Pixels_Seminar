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
// C++ program to demonstrate function
// declaration outside class

#include <iostream>
using namespace std;
class Sra
{
public:
	char first_letter;
	int id;

	// printletter is not defined inside class definition
	void printletter();

	// printid is defined inside class definition
	void printid()
	{
		cout << "SRA id is: " << id;
	}
};

// Definition of printletter using scope resolution operator ::
void Sra::printletter()
{
	cout << "First letter of my name  is: " << first_letter;
}
int main()
{

	Sra obj1;
	obj1.first_letter = 'v';
	obj1.id = 24;

	// call printletter()
	obj1.printletter();
	cout << endl;

	// call printid()
	obj1.printid();
	return 0;
}
