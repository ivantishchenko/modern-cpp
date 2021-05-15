#include <map>
#include <iostream>

using namespace std;

map<char, long> BuildCharCounter(const string& str) {
  map<char, long> counter;
  for(char c : str) {
    counter[c]++;
  }
  return counter;
}

int main() {
  int n;
  cin >> n;
  while(n--) {
    string a, b;
    cin >> a >> b;
    cout << (BuildCharCounter(a) == BuildCharCounter(b)? "YES" : "NO") << endl;
  }
}
