#include <string>
#include <iostream>
#include <locale>
#include <set>

using namespace std;


void lower(string& s) {
	for (size_t i = 0; i < s.size(); i++) {
		s.at(i) = tolower(s.at(i));
	}
}


bool contains(const set<string>& s, const string& item) {
	return (s.find(item) != s.end());
}


bool is_prefix(const string& prefix, const string& word) {
	return (word.find(prefix) == 0);
}
