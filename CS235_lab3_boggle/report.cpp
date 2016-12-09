#include <fstream>
#include <iostream>
#include <set>
#include <string>

using namespace std;

//send output to stdout too?
const bool PRINT = true;

void generate_report(ofstream& f_report, set<string> found) {
	for (set<string>::const_iterator i = found.begin(); i != found.end(); ++i) {
		f_report << *i << endl;
		if (PRINT) cout << *i << endl;
	}
}
