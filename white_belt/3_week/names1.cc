#include <string>
#include <iostream>
#include <map>

using namespace std;

class Person {
public:
  void ChangeFirstName(int year, const string& first_name) {
    if(first_name_map_.find(year) != end(first_name_map_)) return;
    first_name_map_[year] = first_name;
  }
  void ChangeLastName(int year, const string& last_name) {
    if(last_name_map_.find(year) != end(last_name_map_)) return;
    last_name_map_[year] = last_name;
  }
  string GetFullName(int year) {
    string first_name = TraverseMap(first_name_map_, year);
    string last_name = TraverseMap(last_name_map_, year);
    if(first_name.empty() && last_name.empty()) {
      return "Incognito";
    }
    else if(first_name.empty()) {
      return last_name + " with unknown first name";
    }
    else if(last_name.empty()) {
      return first_name + " with unknown last name";
    }
    else {
      return first_name + " " + last_name;
    }
 }
private:
  string TraverseMap(map<int, string> &m, int year) {
    string name;
    for(const auto& [y, n] : m) {
      if(year >= y) {
        name = n;
      }
      else {
        break;
      }
    }
    return name;
  }
  map<int, string> first_name_map_;
  map<int, string> last_name_map_;
};

int main() {
  Person person;

  person.ChangeFirstName(1965, "Polina");
  person.ChangeLastName(1967, "Sergeeva");
  for (int year : {1900, 1965, 1990}) {
    cout << person.GetFullName(year) << endl;
  }

  person.ChangeFirstName(1970, "Appolinaria");
  for (int year : {1969, 1970}) {
    cout << person.GetFullName(year) << endl;
  }

  person.ChangeLastName(1968, "Volkova");
  for (int year : {1969, 1970}) {
    cout << person.GetFullName(year) << endl; 
  }
  return 0;

}
