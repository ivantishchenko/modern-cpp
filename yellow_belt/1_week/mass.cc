#include <iostream>

using namespace std;

int main() {
  int n;
  uint64_t r;
  cin >> n >> r;
  uint64_t res = 0;
  while(n--) {
    uint64_t w, h, d;
    cin >> w >> h >> d;
    res += w * h * d * r;
  }

  cout << res;
}
