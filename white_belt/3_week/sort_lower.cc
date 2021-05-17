#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <locale>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<string> vec(n);
  for(string& s : vec) {
    cin >> s;
  }

  sort(begin(vec), end(vec), [](const string& s1, const string& s2) {
                               return lexicographical_compare(begin(s1), end(s1),
                                                              begin(s2), end(s2),
                                                              [](char c1, char c2) {return tolower(c1) < tolower(c2);});
  });
  for(const string &s : vec) {
    cout << s << " ";
  }

}
