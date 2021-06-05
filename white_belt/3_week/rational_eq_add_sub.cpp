#include <iostream>
#include <numeric>

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

int main() {
    {
        Rational r1(4, 6);
        Rational r2(2, 3);
        bool equal = r1 == r2;
        if (!equal) {
            cout << "4/6 != 2/3" << endl;
            return 1;
        }
    }

    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a + b;
        bool equal = c == Rational(2, 1);
        if (!equal) {
            cout << "2/3 + 4/3 != 2" << endl;
            return 2;
        }
    }

    {
        Rational a(5, 7);
        Rational b(2, 9);
        Rational c = a - b;
        bool equal = c == Rational(31, 63);
        if (!equal) {
            cout << "5/7 - 2/9 != 31/63" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
    return 0;
}
