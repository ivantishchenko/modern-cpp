#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main() {
  ifstream in("input.txt");
  string line;
  while(getline(in, line)) {
    cout << line << endl;
  }
}
