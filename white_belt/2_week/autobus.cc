#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
  int q;
  cin >> q;

  map<string, vector<string>> bus_map, stop_map;

  while(q--) {
    string op;
    cin >> op;
    if(op == "NEW_BUS") {
      string bus;
      int stop_count;
      cin >> bus >> stop_count;
      vector<string>& stop_vec = bus_map[bus];
      stop_vec.resize(stop_count);
      for(string& s : stop_vec) {
        cin >> s;
        stop_map[s].push_back(bus);
      }
    }
    else if(op == "BUSES_FOR_STOP") {
      string stop;
      cin >> stop;
      if(stop_map.find(stop) == end(stop_map)) {
        cout << "No stop" << endl;
      }
      else {
        for(const string& b : stop_map[stop]) {
          cout << b << " ";
        }
        cout << endl;
      }
    }
    else if(op == "STOPS_FOR_BUS") {
      string bus;
      cin >> bus;

      if(bus_map.find(bus) == end(bus_map)) {
        cout << "No bus" << endl;
        continue;
      }

      vector<string>& stops = bus_map[bus];
      for(const string& s : stops) {
        cout << "Stop " << s << ": ";
        if(stop_map[s].size() == 1) {
          cout << "no interchange" << endl;
          continue;
        }
        for(const string& b: stop_map[s]) {
          if(bus != b) {
            cout << b << " ";
          }
        }
        cout << endl;
      }
    }
    else if(op == "ALL_BUSES") {
      if(bus_map.empty()) {
        cout << "No buses" << endl;
        continue;
      }

      for(const auto& [bus, stop_vec] : bus_map) {
        cout << "Bus " << bus << ": ";
        for(const string& s : stop_vec) {
          cout << s << " "; 
        }
        cout << endl;
      }
    }
  }
}
