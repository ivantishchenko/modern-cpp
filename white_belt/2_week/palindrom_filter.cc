#include <vector>
#include <string>
#include <iostream>

using namespace std;

bool IsPalindrom(const string& str){
  for(int i = 0, j = str.size() - 1; i < j; ++i, --j) {
    if(str[i] != str[j]) {
      return false;
    }
  }
  return true;
}

vector<string> PalindromFilter(const vector<string>& vec_str, int minLen) {
  vector<string> res;
  for(const string& str : vec_str) {
    if(str.size() >= minLen && IsPalindrom(str)) {
      res.push_back(str);
    }
  }
  return res;
}

int main() {
  int n;
  cin >> n;
  string str;
  vector<string> vec_str;
  while(getline(cin, str)) {
    vec_str.push_back(str);
  }

  cout << endl;

  for(const string& str : PalindromFilter(vec_str, n)) {
    cout << str << endl;
  }
}
