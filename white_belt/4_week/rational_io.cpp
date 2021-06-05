#include <iostream>
#include <numeric>
#include <sstream>

using namespace std;

class Rational {
public:
  Rational() : p(0), q(1) {
    }

    Rational(int numerator, int denominator) {
      int gcd_val = gcd(numerator, denominator);
      p = numerator / gcd_val;
      q = denominator / gcd_val;
      if(p > 0 && q < 0) {
        q = -q;
        p = -p;
      }
      if(p < 0 && q < 0) {
        q = abs(q);
        p = abs(p);
      }
      if(p == 0) {
        q = 1;
      }
    }

    int Numerator() const {
      return p;
    }

    int Denominator() const {
      return q;
    }

    void SetNumerator(int new_p) {
    	p = new_p;
    }

    void SetDenominator(int new_q) {
    	q = new_q;
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
 int lcm_val = lcm(rhs.Denominator(), lhs.Denominator());
 return Rational(rhs.Numerator() * lcm_val / rhs.Denominator() + lhs.Numerator() * lcm_val / lhs.Denominator(), lcm_val);
}

Rational operator-(const Rational& rhs, const Rational& lhs) {
	int lcm_val = lcm(rhs.Denominator(), lhs.Denominator());
	return Rational(rhs.Numerator() * lcm_val / rhs.Denominator() - lhs.Numerator() * lcm_val / lhs.Denominator(), lcm_val);
}

Rational operator*(const Rational& rhs, const Rational& lhs) {
	return Rational(rhs.Numerator() * lhs.Numerator(), rhs.Denominator() * lhs.Denominator());
}

Rational operator/(const Rational& rhs, const Rational& lhs) {
	return Rational(rhs.Numerator() * lhs.Denominator(), rhs.Denominator() * lhs.Numerator());
}

ostream& operator<<(ostream& out, const Rational& r) {
	out << r.Numerator() << "/" << r.Denominator();
	return out;
}

istream& operator>>(istream& stream, Rational& rational) {
  int num = rational.Numerator(), denom = rational.Denominator();
  bool is_invalid_in = false;
  if(!(stream >> num)) {
	  is_invalid_in = true;
  }
  char sep;
  stream >> sep;
  if(!(stream >> denom)) {
	  is_invalid_in = true;
  }
  if(sep == '/' && !is_invalid_in) rational = Rational(num, denom);
  return stream;
}

int main() {
    {
        ostringstream output;
        output << Rational(-6, 8);
        if (output.str() != "-3/4") {
            cout << "Rational(-6, 8) should be written as \"-3/4\"" << endl;
            return 1;
        }
    }

    {
        istringstream input("5/7");
        Rational r;
        input >> r;
        bool equal = r == Rational(5, 7);
        if (!equal) {
            cout << "5/7 is incorrectly read as " << r << endl;
            return 2;
        }
    }

    {
        istringstream input("");
        Rational r;
        bool correct = !(input >> r);
        if (!correct) {
            cout << "Read from empty stream works incorrectly" << endl;
            return 3;
        }
    }

    {
        istringstream input("5/7 10/8");
        Rational r1, r2;
        input >> r1 >> r2;
        bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Multiple values are read incorrectly: " << r1 << " " << r2 << endl;
            return 4;
        }

        input >> r1;
        input >> r2;
        correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Read from empty stream shouldn't change arguments: " << r1 << " " << r2 << endl;
            return 5;
        }
    }

    {
        istringstream input1("1*2"), input2("1/"), input3("/4");
        Rational r1, r2, r3;
        input1 >> r1;
        input2 >> r2;
        input3 >> r3;
        bool correct = r1 == Rational() && r2 == Rational() && r3 == Rational();
        if (!correct) {
            cout << "Reading of incorrectly formatted rationals shouldn't change arguments: "
                 << r1 << " " << r2 << " " << r3 << endl;

            return 6;
        }
    }

    cout << "OK" << endl;
    return 0;
}
