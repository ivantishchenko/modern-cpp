#include <string>

using namespace std;

struct Specialization {
  string specialization;
  explicit Specialization(const string& s) : specialization(s) {}
};

struct Course {
  string course;
  explicit Course(const string& c) : course(c) {}
};

struct Week {
  string week;
  explicit Week(const string& w) : week(w) {}
};

struct LectureTitle {
  string specialization;
  string course;
  string week;

  LectureTitle(const Specialization& s, const Course& c, const Week& w) : specialization(s.specialization), course(c.course), week(w.week) {} 
};

int main() {
  
}
