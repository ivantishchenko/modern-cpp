#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <numeric>
#include <sstream>
#include <exception>

using namespace std;

class Rational {
public:
  Rational() : p(0), q(1) {
    }

    Rational(int numerator, int denominator) {

    	if(denominator == 0) {
    		throw invalid_argument("Division by zero");
    	}

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

	if(rhs.Denominator() * lhs.Numerator() == 0) {
		throw domain_error("Division by zero");
	}

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
    try {
        Rational r(1, 0);
        cout << "Doesn't throw in case of zero denominator" << endl;
        return 1;
    } catch (invalid_argument&) {
    }

    try {
        auto x = Rational(1, 2) / Rational(0, 1);
        cout << "Doesn't throw in case of division by zero" << endl;
        return 2;
    } catch (domain_error&) {
    }

    cout << "OK" << endl;
    return 0;
}
