#include <iomanip>
#include <fstream>
#include <iostream>

using namespace std;

int main() {
  ifstream in("input.txt");
  float num;
  while(in >> num) {
    cout << setprecision(3) << fixed << num << endl;
  }
}
