#include <iostream>
#include <vector>
using namespace std;

int main() {
  //decleration of int vector
  vector<int> vec = {1, 2, 3, 4, 5};
  int vecSize = vec.size(); // returns length of vector

  cout << "Vector: ";

  for (auto & element : vec) 
  {
    cout << element << " ";
  }
  return 0;
}