#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<bool> queue;

  while(n--) {
    string op;
    cin >> op;
    if(op == "COME") {
      int i;
      cin >> i;
      queue.resize(queue.size() + i);
    }
    else if(op == "WORRY" || op == "QUIET") {
      int i;
      cin >> i;
      queue[i] = (op == "WORRY");
    }
    else if(op == "WORRY_COUNT") {
      cout << count(begin(queue), end(queue), true) << endl;
    }
  }
}
