#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <map>
#include <list>

#include "grid.h"

using namespace std;

//from openfiles.cpp
int open_files(int argc, char* argv[], ifstream& f_dict, ifstream& f_board, ofstream& f_report);

//from readfiles.cpp
void read_dictionary(ifstream& f_dict, set<string>& dictionary);
void read_board(ifstream& f_board, grid<string>& board);

//from process.cpp
void process_board(grid<string>& board, set<string>& dictionary, set<string>& found);

//from report.cpp
void generate_report(ofstream& f_report, set<string> found);


int main (int argc, char* argv[]) {

	//test for valid command
	if (argc < 4 && argc != 2) {
		cerr << "Usage:" << endl;
		cerr << "lab3 dictionary_file board_file report_file" << endl;
		cerr << "lab3 test_number" << endl;
	}

	//declare files
	ifstream f_dict;
	ifstream f_board;
	ofstream f_report;

	//open and test files
	int open_error = open_files(argc, argv, f_dict, f_board, f_report);
	if (open_error != 0) {
		return open_error;
	}

	//declare data
	set<string> dictionary;
	grid<string> board;
	set<string> found;

	//read files
	read_dictionary(f_dict, dictionary);
	read_board(f_board, board);

	//close input files
	f_dict.close();
	f_board.close();

	//print dictionary and board
	/*for (typename set<string>::const_iterator i = dictionary.begin(); i != dictionary.end(); ++i) {
		cout << *i << endl;
	}
	cout << endl;
	for (size_t i = 0; i < board.get_dims().second; ++i) {
		for (size_t j = 0; j < board.get_dims().first; ++j) {
			cout << board.get(i,j) << " ";
		}
		cout << endl;
	}
	cout << endl;
	for (size_t i = 0; i < board.get_size(); ++i) {
		cout << board.get(i) << " ";
	}
	cout << endl;*/

	//find words
	process_board(board, dictionary, found);

	//write output
	generate_report(f_report, found);

	//close output
	f_report.close();

	return 0;
}
