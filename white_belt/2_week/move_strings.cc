#include <iostream>
#include <vector>
#include <string>

using namespace std;

void MoveStrings(vector<string>& source, vector<string>& destination) {
  destination.insert(end(destination), begin(source), end(source));
  source.clear();
}

int main() {
  vector<string> source = {"a", "b", "c"};
  vector<string> destination = {"z"};
  MoveStrings(source, destination);
  for(auto str : destination) {
    cout << str << " ";
  }
}
