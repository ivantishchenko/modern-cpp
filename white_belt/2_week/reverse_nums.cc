#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void Reverse(vector<int>& v) {
  reverse(begin(v), end(v));
}

int main() {
  vector<int> numbers = {1, 5, 3, 4, 2};
  Reverse(numbers);
  for(int i : numbers) {
    cout << i << " ";
  }
}
