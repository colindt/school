#include <iostream>
#include <fstream>

using namespace std;

bool verify_files(const ifstream& f_dict, const ifstream& f_board, const ofstream& f_report, const char* s_students, const char* s_grades, const char* s_report) {
	bool valid = true;

	if (!f_dict) {
		cerr << "Could not open " << s_students << " for reading." << endl;
		valid = false;
	}
	if (!f_board) {
		cerr << "Could not open " << s_grades << " for reading." << endl;
		valid = false;
	}
	if (!f_report) {
		cerr << "Could not open " << s_report << " for writing." << endl;
		valid = false;
	}

	return valid;
}


int open_files(int argc, char* argv[], ifstream& f_dict, ifstream& f_board, ofstream& f_report) {
	if (argc == 4) { //files given individually
		f_dict.open(argv[1]);
		f_board.open(argv[2]);
		f_report.open(argv[3]);

		if (!verify_files(f_dict, f_board, f_report, argv[1], argv[2], argv[3])) {
			return 1;
		}
	}
	else if (argc == 2) { //test number given
		string num(argv[1]);

		// C++ strings of the names of the files
		string s_dict("in"+num+"a.txt");
		string s_board("in"+num+"b.txt");
		string s_report("out"+num+".txt");

		// convert those to C strings
		const char* cs_dict = s_dict.c_str();
		const char* cs_board = s_board.c_str();
		const char* cs_report = s_report.c_str();

		// open the files
		f_dict.open(cs_dict);
		f_board.open(cs_board);
		f_report.open(cs_report);

		//test the files
		if (!verify_files(f_dict, f_board, f_report, cs_dict, cs_board, cs_report)) {
			return 2;
		}
	}

	return 0;
}
