#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int a, b;
  cin >> a >> b;

  if(b == a) {
    cout << a;
    return 0;
  }
  else if(b > a) {
    std::swap(a, b);
  }

  while(b != 0) {
    int r =  a % b;
    a = b;
    b = r;
  }

  cout << a;
}
