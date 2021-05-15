#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> vec(n);
  int avg = 0;
  for(int& i : vec) {
    cin >> i;
    avg += i;
  }

  avg /= n;

  vector<int> idx_vec;
  for(size_t i = 0; i < vec.size(); ++i) {
    if(vec[i] > avg) {
      idx_vec.push_back(i);
    }
  }

cout << idx_vec.size() << endl;
  for(int i : idx_vec) {
    cout << i << " ";
  }
}
