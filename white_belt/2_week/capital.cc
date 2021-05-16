#include <iostream>
#include <map>

using namespace std;

int main() {
  int n;
  cin >> n;

  map<string, string> capital_map;

  while(n--) {
    string op;
    cin >> op;
    if(op == "CHANGE_CAPITAL") {
      string country, capital;
      cin >> country >> capital;
      if(capital_map.find(country) == end(capital_map)) {
        cout << "Introduce new country " << country << " with capital " << capital << endl;
        capital_map[country] = capital;
      }
      else {
        string old_capital = capital_map.at(country);
        if(capital == old_capital) {
          cout << "Country " << country << " hasn't changed its capital" << endl;
        }
        else {
          cout << "Country " << country << " has changed its capital from " << old_capital << " to " << capital << endl;
          capital_map[country] = capital;
        }
      }
    }
    else if(op == "RENAME") {
      string old_country, new_country;
      cin >> old_country >> new_country;
      if(old_country == new_country
         || capital_map.find(old_country) == end(capital_map)
         || capital_map.find(new_country) != end(capital_map)) {
        cout << "Incorrect rename, skip" << endl;
      }
      else {
        string capital = capital_map.at(old_country);
        capital_map[new_country] = capital;
        capital_map.erase(old_country);
        cout << "Country " << old_country << " with capital " << capital << " has been renamed to " << new_country << endl;
      }
    }
    else if(op == "ABOUT") {
      string country;
      cin >> country;
      if(capital_map.find(country) == end(capital_map)) {
        cout << "Country " << country << " doesn't exist" << endl;
      }
      else {
        cout << "Country " << country << " has capital " << capital_map[country] << endl;
      }
    }
    else if(op == "DUMP") {
      if(capital_map.empty()) {
        cout << "There are no countries in the world" << endl;
      }
      else {
        for(const auto& [country, capital] : capital_map) {
          cout << country << "/" << capital << " ";
        }
        cout << endl;
      }
    }
  }
}
