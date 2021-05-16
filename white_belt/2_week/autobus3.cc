#include <set>
#include <iostream>
#include <map>

using namespace std;

int main() {
  int q;
  cin >> q;
  map<set<string>, int> bus_map;
  while(q--) {
    int n;
    cin >> n;
    set<string> stops;
    while(n--) {
      string s;
      cin >> s;
      stops.insert(s);
    }

    if(bus_map.find(stops) == end(bus_map)) {
      const int new_size = bus_map.size() + 1;
      bus_map[stops] = new_size;
      cout << "New bus " << new_size << endl;
    }
    else {
      cout << "Already exists for " << bus_map[stops] << endl;
    }
  }
}
