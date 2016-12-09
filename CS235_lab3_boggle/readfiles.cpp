#include <fstream>
#include <set>
#include <string>
#include <vector>
#include <cmath>

#include "grid.h"

using namespace std;

const size_t MIN_WORD_LENGTH = 3;

//from util.cpp
void lower(string& s);


void read_dictionary(ifstream& f_dict, set<string>& dictionary) {
	string word;
	while (f_dict >> word) {
		if (word.size() < MIN_WORD_LENGTH) {continue;} //skip too short words
		lower(word);
		dictionary.insert(word);
	}
}


void read_board(ifstream& f_board, grid<string>& board) {
	//read file
	string tile;
	vector<string> readin;
	while (f_board >> tile) {
		lower(tile);
		readin.push_back(tile);
	}

	//calc and set board size
	size_t board_size = ceil(sqrt(readin.size()));
	board.set_size(board_size, board_size);

	//load board into grid
	for (size_t i = 0; i < readin.size(); ++i) {
		board.set(readin.at(i), i);
	}
}
