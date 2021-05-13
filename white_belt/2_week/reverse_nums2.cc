#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> Reversed(const vector<int>& v) {
  vector<int> res = v;
  reverse(begin(res), end(res));
  return res;
}

int main() {
  
}
