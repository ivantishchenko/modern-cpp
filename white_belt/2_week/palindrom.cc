#include <iostream>
#include <string>

using namespace std;

bool IsPalindrom(const string& str) {
  for(int i = 0, j = str.size() - 1; i < j; ++i, --j) {
    if(str[i] != str[j]) {
      return false;
    }
  }
  return true;
}

int main() {
  string str;
  cin >> str;
  cout << IsPalindrom(str);
}
