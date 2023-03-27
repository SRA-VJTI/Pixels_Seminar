#include <iostream>
#include <vector>
using namespace std;

int main()
{

  // initializer list
  vector<int> vector1 = {1, 2, 3, 4, 5};

  // uniform initialization
  vector<int> vector2{6, 7, 8, 9, 10};

  // method 3
  vector<int> vector3(5, 12);
  // Here 5 is the size of vector and 12 is the value.

  cout << "vector1 = ";

  // ranged loop
  for (const int &i : vector1)
  {
    cout << i << "  ";
  }

  cout << "\nvector2 = ";

  // ranged loop
  for (const int &i : vector2)
  {
    cout << i << "  ";
  }

  cout << "\nvector3 = ";

  // ranged loop
  for (int i : vector3)
  {
    cout << i << "  ";
  }
  cout << endl;
  return 0;
}
