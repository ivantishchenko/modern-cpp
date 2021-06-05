#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

int main() {
  fstream in("input.txt");
  float M, N;
  in >> M >> N;
  cout << setfill(' ');
  for(int i = 0; i < M; ++i) {
    for(int j = 0; j < N; ++j) {
      int num;
      in >> num;
      cout << setw(10) << num;
      if(j != N - 1) {
        in.ignore(1);
        cout << " ";
      }
    }
    if(i != M - 1) {
      cout << endl;
    }
  }
}
