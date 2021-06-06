#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<long> temp_vec(n);

  long avg = 0;
  for(long& i : temp_vec) {
    cin >> i;
    avg += i;
  }

  avg /= n;

  vector<size_t> res_vec;
  for(size_t i = 0; i < temp_vec.size(); ++i) {
    if(temp_vec[i] > avg) {
      res_vec.push_back(i);
    }
  }

  cout << res_vec.size() << endl;
  for(size_t i : res_vec) {
    cout << i << " ";
  }
}
