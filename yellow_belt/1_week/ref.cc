/*
 * ref.cc
 *
 *  Created on: Jun 13, 2021
 *      Author: ivan
 */

#include <map>
#include <string>
#include <iostream>
#include <exception>

using namespace std;


template <typename Key, typename Val>
Val& GetRefStrict(map<Key, Val>& m, const Key& k) {
	if(m.find(k) == end(m)) {
		throw runtime_error("Key doesn't exist");
	}
	return m.at(k);
}

int main() {
	map<int, string> m = {{0, "value"}};
	string& item = GetRefStrict(m, 0);
	item = "newvalue";
	cout << m[0] << endl; // выведет newvalue
	return 0;
}
