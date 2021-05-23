#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

class Person {
public:
  void ChangeFirstName(int year, const string& first_name) {
    first_name_map_[year] = first_name;
  }
  void ChangeLastName(int year, const string& last_name) {
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
  string GetFullNameWithHistory(int year) {
    vector<string> first_name_vec = TraverseMapHistory(first_name_map_, year);
    vector<string> last_name_vec = TraverseMapHistory(last_name_map_, year);
    if(first_name_vec.empty() && last_name_vec.empty()) {
      return "Incognito";
    }
    else if(first_name_vec.empty()) {
      return GetNameStr(last_name_vec) + " with unknown first name";
    }
    else if(last_name_vec.empty()) {
      return GetNameStr(first_name_vec) + " with unknown last name";
    }
    else {
      return GetNameStr(first_name_vec) + " " + GetNameStr(last_name_vec);
    }
  }
private:
  string GetNameStr(const vector<string>& name_vec) {
    string res = name_vec[0];
    if(name_vec.size() == 1) return res;
    res += " (";
    for(size_t i = 1; i < name_vec.size(); ++i) {
      res += name_vec[i] + ", ";
    }
    res.pop_back();
    res[res.size() - 1] = ')';
    return res;
  }

  vector<string> TraverseMapHistory(const map<int, string> &m, int year) {
    vector<string> name_vec;
    for(const auto& [y, n] : m) {
      if(year >= y && (name_vec.empty() || name_vec.back() != n)) {
        name_vec.push_back(n);
      }
      else {
        break;
      }
    }

    reverse(begin(name_vec), end(name_vec));

    return name_vec;
  }

  string TraverseMap(const map<int, string> &m, int year) {
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
  person.ChangeFirstName(1965, "Appolinaria");

  person.ChangeLastName(1965, "Sergeeva");
  person.ChangeLastName(1965, "Volkova");
  person.ChangeLastName(1965, "Volkova-Sergeeva");

  for (int year : {1964, 1965, 1966}) {
    cout << person.GetFullNameWithHistory(year) << endl;
      
  }

  return 0;

}
