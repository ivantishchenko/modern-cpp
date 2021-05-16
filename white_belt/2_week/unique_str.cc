#include <set>
#include <iostream>
#include <string>

using namespace std;

int main() {
  int n;
  cin >> n;
  set<string> str_set;
  while(n--) {
    string str;
    cin >> str;
    str_set.insert(str);
  }
  cout << str_set.size() << endl;
}
