#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> digits;
  while(n > 0) {
    digits.push_back(n % 2);
    n /= 2;
  }
  for(auto it = rbegin(digits); it != rend(digits); ++it) {
    cout << *it;
  } 
}
