#include <cmath>
#include <iostream>

using namespace std;

int main() {
  float a, b, c;
  cin >> a >> b >> c;
  float d = b * b - 4.f * a * c;
  if(a == 0) {
    if(b != 0) {
      cout << -c / b;
    }
  }
  else if(d == 0) {
    cout << -b / (2 * a);
  }
  else if(d > 0) {
    cout << (-b + sqrt(d)) / (2.f * a) << ' ' << (-b - sqrt(d)) / (2.f * a);
  }
}
