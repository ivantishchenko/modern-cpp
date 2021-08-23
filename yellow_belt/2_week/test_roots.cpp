#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
#include <cmath>
#include <random>

using namespace std;

template<class T>
ostream& operator <<(ostream &os, const vector<T> &s) {
	os << "{";
	bool first = true;
	for (const auto &x : s) {
		if (!first) {
			os << ", ";
		}
		first = false;
		os << x;
	}
	return os << "}";
}

template<class T>
ostream& operator <<(ostream &os, const set<T> &s) {
	os << "{";
	bool first = true;
	for (const auto &x : s) {
		if (!first) {
			os << ", ";
		}
		first = false;
		os << x;
	}
	return os << "}";
}

template<class K, class V>
ostream& operator <<(ostream &os, const map<K, V> &m) {
	os << "{";
	bool first = true;
	for (const auto &kv : m) {
		if (!first) {
			os << ", ";
		}
		first = false;
		os << kv.first << ": " << kv.second;
	}
	return os << "}";
}

template<class T, class U>
void AssertEqual(const T &t, const U &u, const string &hint = { }) {
	if (t != u) {
		ostringstream os;
		os << "Assertion failed: " << t << " != " << u;
		if (!hint.empty()) {
			os << " hint: " << hint;
		}
		throw runtime_error(os.str());
	}
}

void Assert(bool b, const string &hint) {
	AssertEqual(b, true, hint);
}

class TestRunner {
public:
	template<class TestFunc>
	void RunTest(TestFunc func, const string &test_name) {
		try {
			func();
			cerr << test_name << " OK" << endl;
		} catch (exception &e) {
			++fail_count;
			cerr << test_name << " fail: " << e.what() << endl;
		} catch (...) {
			++fail_count;
			cerr << "Unknown exception caught" << endl;
		}
	}

	~TestRunner() {
		if (fail_count > 0) {
			cerr << fail_count << " unit tests failed. Terminate" << endl;
			exit(1);
		}
	}

private:
	int fail_count = 0;
};

int GetDistinctRealRootCount(double A, double B, double C) {
	// Вы можете вставлять сюда различные реализации функции,
	// чтобы проверить, что ваши тесты пропускают корректный код
	// и ловят некорректный

	// найдём дискриминант
	double D = B * B - 4 * A * C;

	// если A равно нулю, то уравнение линейное: Bx + C = 0
	if (A == 0) {
		if (B != 0) {
			return 1;
		}

	} else if (D == 0) {  // случай с нулевым дискриминантом
		// корень ровно один
		return 1;

	} else if (D > 0) {  // в случае с положительным дискриминантом корня два
		return 2;
	}

	return 0;
}

void SimpleBlock() {
	Assert(GetDistinctRealRootCount(0, 2, 4) == 1, "A = 0");
	Assert(GetDistinctRealRootCount(2, 5, 2) == 2, "2 roots");
	Assert(GetDistinctRealRootCount(2, 4, 2) == 1, "1 root");
	Assert(GetDistinctRealRootCount(2, 1, 2) == 0, "0 roots");
	Assert(GetDistinctRealRootCount(0, 0, 1) == 0, "Constant");

	int root_count = GetDistinctRealRootCount(2, 5, 2) == 2;
	Assert(root_count >= 0 && root_count <= 2, "2 roots");
}

void TestRootCount() {
	mt19937 gen;
	uniform_real_distribution<> unif(-10, 10);

	for (auto i = 0; i < 100; ++i) {
		const auto a = unif(gen);
		const auto b = unif(gen);
		const auto c = unif(gen);

		const auto count = GetDistinctRealRootCount(a, b, c);

		Assert(count >= 0 && count <= 2,
				"Quadratic equation has only 0, 1 or 2 real roots.");
	}
}

int main() {
	TestRunner tr;
	tr.RunTest(SimpleBlock, "Simple Block");
	//tr.RunTest(TestRootCount, "Root count");
	// добавьте сюда свои тесты
	return 0;
}
