#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

class ReversibleString {
public:
  ReversibleString() = default;
  ReversibleString(const string &str) : str_(str)  {}
  void Reverse() {
    reverse(begin(str_), end(str_));
  }
  string ToString() const {
    return str_;
  }
private:
  string str_;
};

int main() {
  ReversibleString s("live");
  s.Reverse();
  cout << s.ToString() << endl;

  s.Reverse();
  const ReversibleString& s_ref = s;
  string tmp = s_ref.ToString();
  cout << tmp << endl;

  ReversibleString empty;
  cout << '"' << empty.ToString() << '"' << endl;

  return 0;

}
