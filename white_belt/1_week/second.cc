#include <iostream>
#include <string>

using namespace std;

int main() {
  string str;
  cin >> str;
  int count = 0;
  for(int i = 0; i < str.size(); ++i) {
    if(str[i] == 'f') {
      if(++count == 2) {
        cout << i;
        return 0;
      }
    }
  }
  if(count == 1) {
    cout << -1;
  }
  else if(count == 0) {
    cout << -2;
  }
}
