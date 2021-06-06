// Реализуйте функции и методы классов и при необходимости добавьте свои
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <exception>
#include <iomanip>

using namespace std;

class Date {
public:
  Date(int new_year, int new_month, int new_day) {
    year = new_year;
    if (new_month > 12 || new_month < 1) {
      throw logic_error("Month value is invalid: " + to_string(new_month));
    }
    month = new_month;
    if (new_day > 31 || new_day < 1) {
      throw logic_error("Day value is invalid: " + to_string(new_day));
    }
    day = new_day;
  }

  int GetYear() const {
    return year;
  }
  int GetMonth() const {
    return month;
  }
  int GetDay() const {
    return day;
  }

private:
  int year;
  int month;
  int day;
};

ostream& operator<<(ostream& out, const Date& date) {
    out << setfill('0') << setw(4) << date.GetYear()
    	<< '-' << setw(2) << date.GetMonth()
		<< '-' << setw(2) << date.GetDay();
    return out;
}

bool operator<(const Date& lhs, const Date& rhs) {
	return lhs.GetYear() * 365 + lhs.GetMonth() * 31 + lhs.GetDay()
		 < rhs.GetYear() * 365 + rhs.GetMonth() * 31 + rhs.GetDay();
}

class Database {
public:
  void AddEvent(const Date& date, const string& event) {
	  events_map_[date].insert(event);
  }

  bool DeleteEvent(const Date& date, const string& event) {
	  if(events_map_.find(date) == end(events_map_) ||
		 events_map_.at(date).find(event) == end(events_map_.at(date))) {
		  cout << "Event not found" << endl;
		  return false;
	  }
	  events_map_.at(date).erase(event);
	  cout << "Deleted successfully" << endl;
	  return true;
  }

  int DeleteDate(const Date& date) {
	  int deleted_count = 0;
	  if(events_map_.find(date) != end(events_map_)) {
		  deleted_count = events_map_.at(date).size();
		  events_map_.erase(date);
	  }
	  cout << "Deleted " << deleted_count << " events" << endl;
	  return deleted_count;
  }

  set<string> Find(const Date& date) const {
      if(events_map_.find(date) == end(events_map_)) {
          return {};
      }
	  for(const string& e : events_map_.at(date)) {
		  cout << e << endl;
	  }
	  return events_map_.at(date);
  }

  void Print() const {
	  for(const auto& [date, events] : events_map_) {
		  for(const string& e: events) {
			  cout << date << ' ' << e << endl;
		  }
	  }
  }

private:
  map<Date, set<string>> events_map_;
};

Date ParseDate(const string& date) {
  istringstream date_stream(date);
  bool ok = true;

  int year;
  ok = ok && (date_stream >> year);
  ok = ok && (date_stream.peek() == '-');
  date_stream.ignore(1);

  int month;
  ok = ok && (date_stream >> month);
  ok = ok && (date_stream.peek() == '-');
  date_stream.ignore(1);

  int day;
  ok = ok && (date_stream >> day);
  ok = ok && date_stream.eof();

  if (!ok) {
    throw logic_error("Wrong date format: " + date);
  }
  return Date(year, month, day);
}

int main() {
  Database db;
  string command;
  while (getline(cin, command)) {
	if(command.empty()) continue;

	istringstream ss(command);
	string op, date_str, event_str;
	ss >> op >> date_str >> event_str;

	try {
		if(op == "Add") {
			db.AddEvent(ParseDate(date_str), event_str);
		}
		else if(op == "Del") {
			Date d = ParseDate(date_str);
			event_str.empty() ? db.DeleteDate(d) : db.DeleteEvent(d, event_str);
		}
		else if(op == "Find") {
			db.Find(ParseDate(date_str));
		}
		else if(op == "Print") {
			db.Print();
		}
		else {
			cout << "Unknown command: " << command << endl;
		}
	}
	catch(const exception& e) {
		cout << e.what() << endl;
	}
  }
  return 0;
}
