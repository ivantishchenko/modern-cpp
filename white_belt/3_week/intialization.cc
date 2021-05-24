class Incognizable {
public:
  Incognizable() = default;
  Incognizable(int i) : a(i) {}
  Incognizable(int i, int j) : a(i), b(j) {}
private:
  int a;
  int b;
};

int main() {
  Incognizable a;
  Incognizable b = {};
  Incognizable c = {0};
  Incognizable d = {0, 1};
  return 0;
}
