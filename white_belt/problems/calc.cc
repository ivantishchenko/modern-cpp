#include <iostream>

using namespace std;

int main() {
  float n, a, b, x, y;
  cin >> n >> a >> b >> x >> y;
  float final_price = n;
  if(n > a) {
    final_price = n * (1.f - x / 100.f);
  }
  if(n > b) {
    final_price = n * (1.f  - y / 100.f);
  }
  cout << final_price;
}
