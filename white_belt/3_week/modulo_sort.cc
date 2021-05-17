#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> vec(n);
  for(int& i : vec) {
    cin >> i;
  }
  sort(begin(vec), end(vec), [n](int i, int j) { return abs(i) < abs(j);});
  for(int i : vec) {
    cout << i << " ";
  }
}
