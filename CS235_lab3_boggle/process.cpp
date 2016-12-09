#include <string>
#include <set>
#include <utility>
#include <iostream>

#include "grid.h"

using namespace std;

//from util.cpp
bool contains(const set<string>& s, const string& item);
bool is_prefix(const string& prefix, const string& word);


bool check_prefix(const set<string>& dictionary, const string& str) {
	set<string>::const_iterator bound = dictionary.lower_bound(str);
	if (bound == dictionary.end()) {return false;} //it ran off the end of the set. definatly not a prefix
	//string lowerbound = *bound;
	bool p = is_prefix(str, *bound);
	return p;
}


void process_tile(size_t r, size_t c, grid<string>& board, grid<bool>& used, set<string>& dictionary, set<string>& found, string current) {
	//used and current are passed by value so they revert on return
	if (!board.is_valid(r,c)) {return;} //out of range cells don't work
	if (used.get(r,c)) {return;} //skip tiles that have already been used

	current += board.get(r,c); //add this cell to current string
	//cout << current;
	used.set(true, r,c); //have now used this cell

	/*if (contains(dictionary, current)) {
		found.insert(current); //collect string
		//dictionary.erase(dictionary.find(current)); //remove found word from dictionary to speed things up (it won't find it again)
		//cout << "*";
	}*/
	//cout << endl;

	if (check_prefix(dictionary, current)) { //does current start anything in dictionary?
		if (contains(dictionary, current)) {
			found.insert(current);
		}
		/*for (int i = 0; i < 8; ++i) { //loop cell neighbors
			process_tile(board.get_neighbor(i, cell), board, used, dictionary, found, current);
		}*/
		process_tile(r  ,c+1, board, used, dictionary, found, current);
		process_tile(r-1,c+1, board, used, dictionary, found, current);
		process_tile(r-1,c  , board, used, dictionary, found, current);
		process_tile(r-1,c-1, board, used, dictionary, found, current);
		process_tile(r  ,c-1, board, used, dictionary, found, current);
		process_tile(r+1,c-1, board, used, dictionary, found, current);
		process_tile(r+1,c  , board, used, dictionary, found, current);
		process_tile(r+1,c+1, board, used, dictionary, found, current);


	}
	used.set(false, r,c); //have now not used this cell

}


void process_board(grid<string>& board, set<string>& dictionary, set<string>& found) {
	//grid<bool> blank_used(board.get_dims().first, board.get_dims().second); //a grid of which tiles have alreay been used in this path
	grid<bool> used(board.get_dims().first, board.get_dims().second); //a grid of which tiles have alreay been used in this path
	for (size_t i = 0; i < board.get_size(); ++i) { //loop all tiles for starting tile
		//if (board.get(i) == "") {continue;} //skip starting on empty tiles, because that would be the same as starting on all its neighbors twice
		//if (dictionary.empty()) {break;} //if there are no words left in the dictionary, don't look for more
		//used = blank_used;
		//pair<size_t,size_t> cell(board.cell_get_row(i), board.cell_get_col(i));
		process_tile(board.cell_get_row(i), board.cell_get_col(i), board, used, dictionary, found, "");
	}
}
