/*
 * sqr.cc
 *
 *  Created on: Jun 13, 2021
 *      Author: ivan
 */
#include <vector>
#include <map>
#include <iostream>

using namespace std;

template<typename Key, typename Val> pair<Key, Val> operator*(const pair<Key, Val> &lhs, const pair<Key, Val> &rhs);
template<typename T> vector<T> operator*(const vector<T>& lhs, const vector<T>& rhs);
template<typename Key, typename Val> map<Key, Val> operator*(const map<Key, Val>& lhs, const map<Key, Val>& rhs);
template <typename T> T Sqr(const T& val);

template<typename Key, typename Val>
pair<Key, Val> operator*(const pair<Key, Val> &lhs, const pair<Key, Val> &rhs) {
	return {Sqr(lhs.first), Sqr(lhs.second)};
}

template<typename T>
vector<T> operator*(const vector<T>& lhs, const vector<T>& rhs) {
	vector<T> res;
	for(const auto& element: lhs) {
		res.push_back(Sqr(element));
	}
	return res;
}

template<typename Key, typename Val>
map<Key, Val> operator*(const map<Key, Val>& lhs, const map<Key, Val>& rhs) {
	map<Key, Val> res;
	for(const auto& [k, v] : lhs) {
		res[k] = Sqr(v);
	}
	return res;
}

template <typename T>
T Sqr(const T& val) {
	return val * val;
}

int main() {
	// Пример вызова функции
	vector<int> v = {1, 2, 3};
	cout << "vector:";
	for (int x : Sqr(v)) {
	  cout << ' ' << x;
	}
	cout << endl;

	map<int, pair<int, int>> map_of_pairs = {
	  {4, {2, 2}},
	  {7, {4, 3}}
	};
	cout << "map of pairs:" << endl;
	for (const auto& x : Sqr(map_of_pairs)) {
	  cout << x.first << ' ' << x.second.first << ' ' << x.second.second << endl;
	}
	return 0;
}
