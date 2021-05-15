#include <vector>
#include <string>
#include <iostream>
#include <array>
#include <iterator>
#include <algorithm>

using namespace std;

const int N = 12;
const array<size_t, N> DAY_COUNT = {
    31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};

int main() {
  int q;
  cin >> q;
  int month = 0;
  vector<vector<string>> tasks_vec(DAY_COUNT[month]);
  while(q--) {
    string op;
    cin >> op;
    if(op == "ADD") {
      int day;
      string task;
      cin >> day >> task;
      tasks_vec[day - 1].push_back(task);
    }
    else if(op == "DUMP") {
      int day;
      cin >> day;
      cout << tasks_vec[day - 1].size() << " ";
      for(const string& task : tasks_vec[day - 1]) {
        cout << task << " ";
      }
      cout << endl;
    }
    else if(op == "NEXT") {
      const size_t prev_count = DAY_COUNT[month];
      month = (month + 1) % N;
      const size_t new_count = DAY_COUNT[month];
      if(new_count < prev_count) {
    	  vector<string>& last_day_tasks = tasks_vec[new_count - 1];
    	  for(size_t i = new_count; i < prev_count; ++i) {
    		  last_day_tasks.insert(
    	          end(last_day_tasks),
				  begin(tasks_vec[i]),
				  end(tasks_vec[i])
    		  );
    	  }
      }
      tasks_vec.resize(new_count);
    }
//    else if(op == "NEXT") {
//      month++;
//      month %= N;
//      vector<vector<string>> new_tasks(day_count[month]);
//
//      for(size_t i = 0; i < min(new_tasks.size(), tasks_vec.size()); ++i) {
//      	new_tasks[i] = tasks_vec[i];
//      }
//
//      if(tasks_vec.size() > new_tasks.size()) {
//        for(size_t i = new_tasks.size(); i < tasks_vec.size(); ++i) {
//        	new_tasks[new_tasks.size() - 1].insert(end(new_tasks[new_tasks.size() - 1]), begin(tasks_vec[i]), end(tasks_vec[i]));
//        }
//      }
//
//      tasks_vec = new_tasks;
//    }
  }
}
