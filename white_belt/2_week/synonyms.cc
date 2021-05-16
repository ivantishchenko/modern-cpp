#include <set>
#include <string>
#include <iostream>
#include <utility>
#include <map>
#include <algorithm>

using namespace std;

int main() {
  int q;
  cin >> q;
  map<string, set<string>> synonym_map;

  while(q--) {
    string op;
    cin >> op;
    if(op == "ADD") {
      string a, b;
      cin >> a >> b;
      synonym_map[a].insert(b);
      synonym_map[b].insert(a);
    }
    else if(op == "COUNT") {
      string a;
      cin >> a;
      cout << synonym_map[a].size() << endl;
    }
    else if(op == "CHECK") {
      string a, b;
      cin >> a >> b;
      if(synonym_map[a].find(b) != end(synonym_map[a])) {
        cout << "YES" << endl;
      }
      else {
        cout << "NO" << endl;
      }
    }
  }
}
