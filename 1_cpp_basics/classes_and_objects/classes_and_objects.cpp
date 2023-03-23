// C++ program to demonstrate function
// declaration outside class

#include <iostream>
using namespace std;
class Sra
{
	public:
	char first_letter;
	int id;
	
	// printname is not defined inside class definition
	void printletter();
	
	// printid is defined inside class definition
	void printid()
	{
		cout <<"SRA id is: "<<id;
	}
};

// Definition of printname using scope resolution operator ::
void Sra::printletter()
{
	cout <<"First letter of my name  is: "<<first_letter;
}
int main() {
	
	Sra obj1;
	obj1.first_letter= 'v';
	obj1.id=24;
	
	// call printname()
	obj1.printletter();
	cout << endl;
	
	// call printid()
	obj1.printid();
	return 0;
}