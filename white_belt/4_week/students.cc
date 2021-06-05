#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Student {
  string name;
  string last_name;
  int day;
  int month;
  int year;
};

int main() {
  int N;
  cin >> N;
  vector<Student> vec;
  while(N--) {
    string name, last_name;
    int day, month, year;
    cin >> name >> last_name >> day >> month >> year;
    vec.push_back({name, last_name, day, month, year});
  }
  int M;
  cin >> M;
  while(M--) {
    string cmd;
    int i;
    cin >> cmd >> i;
    --i;

    if((cmd != "name" && cmd != "date") || i >= vec.size() || i < 0) {
      cout << "bad request" << endl;
    }
    else if(cmd == "name") {
      cout << vec[i].name << " " << vec[i].last_name << endl;
    }
    else if(cmd == "date") {
      cout << vec[i].day << "." << vec[i].month << "." << vec[i].year << endl;
    }
  }
}
