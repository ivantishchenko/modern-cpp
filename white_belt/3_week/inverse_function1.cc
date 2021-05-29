#include <vector>
#include <algorithm>

using namespace std;

class FunctionPart {
public:
  FunctionPart(char new_op, double new_val) : op(new_op), val(new_val) {};
  double Apply(double source) const {
    if(op == '+') {
      return source + val;
    }
    else {
      return source - val;
    }
  }
  void Invert() {
    if(op == '+') {
      op = '-';
    }
    else {
      op = '+';
    }
  }
private:
  char op;
  double val;
};

class Function {
public:
  void AddPart(const char op, double val) {
    parts.push_back({op, val});
  }
  double Apply(double val) const {
    for(const FunctionPart& part : parts) {
      val = part.Apply(val);
    }
    return val;
  }
  void Invert() {
    for(FunctionPart& part : parts) {
      part.Invert();
    }
    reverse(begin(parts), end(parts));
  }
private:
  vector<FunctionPart> parts;
};
