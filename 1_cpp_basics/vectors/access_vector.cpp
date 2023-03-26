#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> num {1, 2, 3, 4, 5}; //Initialised a vector

  cout << "Element at Index 0: " << num.at(0) << endl; //Printing value at vector index 0
  cout << "Element at Index 2: " << num.at(2) << endl; //Printing value at vector index 2
  cout << "Element at Index 4: " << num.at(4); //Printing value at vector index 4

  return 0;
}
