#include <map>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int q;
  cin >> q;
  map<vector<string>, int> bus_map;
  while(q--) {
    int n;
    cin >> n;
    vector<string> stops(n);
    for(string& s : stops) {
      cin >> s;
    }
    if(bus_map.find(stops) != end(bus_map)) {
      cout << "Already exists for " << bus_map[stops] << endl;
    }
    else {
      const int new_id = bus_map.size() + 1;
      bus_map[stops] = new_id;
      cout << "New bus " << bus_map[stops] << endl;
    }
  }
}
