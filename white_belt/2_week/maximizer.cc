#include <iostream>

using namespace std;

void UpdateIfGreater(int a, int& b) {
  if(a > b) {
    b = a;
  }
}

int main() {
  int a, b;
  cin >> a >> b;
  UpdateIfGreater(a, b);
  cout << a << " " << b;
}
