#include <iostream>

using namespace std;

int Factorial(int i) {
  if(i <= 1) {
    return 1;
  }
  return i * Factorial(i - 1);
}

int FactorialIter(int i) {
  int res = 1;
  for(int j = i; j >= 1; --j) {
    res *= j;
  }
  return res;
}

int main() {
  int n;
  cin >> n;
  cout << Factorial(n);
}
