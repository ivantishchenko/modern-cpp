#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class SortedStrings {
public:
  void AddString(const string& s) {
    vec_.push_back(s);
  }
  vector<string> GetSortedStrings() {
    sort(begin(vec_), end(vec_));
    return vec_;
  }
private:
  vector<string> vec_;
};

void PrintSortedStrings(SortedStrings& strings) {
  for (const string& s : strings.GetSortedStrings()) {
    cout << s << " ";
  }
  cout << endl;

}

int main() {
  SortedStrings strings;

  strings.AddString("first");
  strings.AddString("third");
  strings.AddString("second");
  PrintSortedStrings(strings);

  strings.AddString("second");
  PrintSortedStrings(strings);

  return 0;

}
