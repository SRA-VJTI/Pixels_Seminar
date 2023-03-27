// Example of Function Template

#include <iostream>
using namespace std;
template <class T>
T add(T &a, T &b) // Declaring a Functional template
{
  T result = a + b;
  return result;
}
int main()
{
  int i = 2;
  int j = 3;
  float m = 2.3;
  float n = 1.2;
  cout << "Addition of i and j is :" << add(i, j); // Calling the template for integer data type
  cout << '\n';
  cout << "Addition of m and n is :" << add(m, n); // Calling the template for float data type
  return 0;
}
