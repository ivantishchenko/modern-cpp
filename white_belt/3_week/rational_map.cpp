#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

#include <iostream>
#include <numeric>
#include <sstream>

using namespace std;

class Rational {
public:
  Rational() : p(0), q(1) {
    }

    Rational(int numerator, int denominator) {
      const int gcd_val = gcd(numerator, denominator);
      p = numerator / gcd_val;
      q = denominator / gcd_val;
      if(q < 0) {
        q = -q;
        p = -p;
      }
    }

    int Numerator() const {
      return p;
    }

    int Denominator() const {
      return q;
    }

private:
  int p;
  int q;
};

// Реализуйте для класса Rational операторы ==, + и -
bool operator==(const Rational& rhs, const Rational& lhs) {
	return rhs.Numerator() == lhs.Numerator() && rhs.Denominator() == lhs.Denominator();
}

Rational operator+(const Rational& rhs, const Rational& lhs) {
  return {
	  lhs.Numerator() * rhs.Denominator() + rhs.Numerator() * lhs.Denominator(),
	  lhs.Denominator() * rhs.Denominator()
  };
}

Rational operator-(const Rational& lhs, const Rational& rhs) {
  return {
      lhs.Numerator() * rhs.Denominator() - rhs.Numerator() * lhs.Denominator(),
      lhs.Denominator() * rhs.Denominator()
  };
}

Rational operator * (const Rational& lhs, const Rational& rhs) {
  return {
      lhs.Numerator() * rhs.Numerator(),
      lhs.Denominator() * rhs.Denominator()
  };
}

Rational operator/(const Rational& rhs, const Rational& lhs) {
	return {
		rhs.Numerator() * lhs.Denominator(),
		rhs.Denominator() * lhs.Numerator()
	};
}

ostream& operator<<(ostream& out, const Rational& r) {
	out << r.Numerator() << "/" << r.Denominator();
	return out;
}

istream& operator>>(istream& is, Rational& r) {
  int n, d;
  char c;

  if (is) {
      is >> n >> c >> d;
      if (is) {
          if (c == '/') {
              r = Rational(n, d);
          }
          else {
        	  //...
        	  //istringstream s{"5*9"};
        	  //Rational r;
        	  //
        	  //if (!(s >> r)) {
        	  //  // Ожидаемо, мы должны попасть сюда из-за некорректного разделителя у 5*9...
        	  //} else {
        	  //  // ...но мы попадем сюда, если не будем использовать особый метод setstate и
        	  //  // флаг ios_base::failbit
        	  //}
        	  //...
              is.setstate(ios_base::failbit);
          }
      }
  }

  return is;
}

bool operator<(const Rational& rhs, const Rational& lhs) {
	return rhs.Numerator() / (float) rhs.Denominator() < lhs.Numerator() / (float) lhs.Denominator();
}

int main() {
    {
        const set<Rational> rs = {{1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2}};
        if (rs.size() != 3) {
            cout << "Wrong amount of items in the set" << endl;
            return 1;
        }

        vector<Rational> v;
        for (auto x : rs) {
            v.push_back(x);
        }
        if (v != vector<Rational>{{1, 25}, {1, 2}, {3, 4}}) {
            cout << "Rationals comparison works incorrectly" << endl;
            return 2;
        }
    }

    {
        map<Rational, int> count;
        ++count[{1, 2}];
        ++count[{1, 2}];

        ++count[{2, 3}];

        if (count.size() != 2) {
            cout << "Wrong amount of items in the map" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
    return 0;
}
