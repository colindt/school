#pragma once

#include <string>
#include <vector>
#include <utility>
#include <string>
#include <sstream>
#include <stdexcept>


template <typename T>
class grid {
 private:
	std::vector<std::vector<T> > data;
	size_t width;
	size_t height;

 public:
	//constructor
	grid<T>(size_t width, size_t height) : width(width), height(height) {set_size(width, height);}
	grid<T>() : width(0), height(0) {}

	//sets the given cell to the given value
	void set(T value, size_t row, size_t col);
	void set(T value, std::pair<size_t,size_t> cell);
	void set(T value, size_t cell);

	//returns the value of the given cell
	T get(size_t row, size_t col) const;
	T get(std::pair<size_t,size_t> cell) const;
	T get(size_t cell) const;

	//for get and set, if only one index is given, cells are numbered like this:
	// 0 1 2
	// 3 4 5
	// 6 7 8
	//etc.

	//translate single index to row and col
	size_t cell_get_row(int cell) const;
	size_t cell_get_col(int cell) const;

	//resizes the grid
	void set_size(size_t w, size_t h);

	//returns the dimentions of the grid
	std::pair<size_t,size_t> get_dims() const;

	//returns the total size of the grid
	size_t get_size() const;

	//determines if the given cell number is within the bounds of the grid
	bool is_valid(size_t row, size_t col) const;
	bool is_valid(std::pair<size_t,size_t> cell) const;

	//gets a neighboring cell to the given one. n is the neighbor number.
	//neighbors are numbered like this:
	// 3 2 1
	// 4   0
	// 5 6 7
	// (assuming rows are top to bottom and columns are left to right)
	std::pair<size_t,size_t> get_neighbor(int n, size_t row, size_t col) const;
	std::pair<size_t,size_t> get_neighbor(int n, std::pair<size_t,size_t> cell) const;

};




template <typename T>
void grid<T>::set(T value, size_t row, size_t col) {
	data.at(row).at(col) = value;
}
template <typename T>
void grid<T>::set(T value, std::pair<size_t,size_t> cell) {
	set(value, cell.first, cell.second);
}
template <typename T>
void grid<T>::set(T value, size_t cell) {
	set(value, cell / width, cell % width); //yes, that's integer division. Yes, that matters.
}


template <typename T>
T grid<T>::get(size_t row, size_t col) const {
	return data.at(row).at(col);
}
template <typename T>
T grid<T>::get(std::pair<size_t,size_t> cell) const {
	return get(cell.first, cell.second);
}
template <typename T>
T grid<T>::get(size_t cell) const {
	return get(cell / width, cell % width); //again, integer divison. Important.
}


template <typename T>
size_t grid<T>::cell_get_row(int cell) const {
	return cell / width; // integer divison
}

template <typename T>
size_t grid<T>::cell_get_col(int cell) const {
	return cell % width;
}


template <typename T>
void grid<T>::set_size(size_t w, size_t h) {
	width = w;
	height = h;
	data.resize(h); //set new width
	for (size_t i = 0; i < data.size(); ++i) {//loop rows
		data.at(i).resize(w); //set new width
	}
}


template <typename T>
std::pair<size_t,size_t> grid<T>::get_dims() const {
	return std::pair<size_t,size_t>(width, height);
}


template <typename T>
size_t grid<T>::get_size() const {
	return width * height;
}


template <typename T>
bool grid<T>::is_valid(size_t row, size_t col) const {
	return (row < height && col < width);
}
template <typename T>
bool grid<T>::is_valid(std::pair<size_t,size_t> cell) const {
	return is_valid(cell.first, cell.second);
}


template <typename T>
std::pair<size_t,size_t> grid<T>::get_neighbor(int n, size_t row, size_t col) const {
	switch (n) {
		case 0: return std::pair<size_t,size_t>(row  , col+1); break;
		case 1: return std::pair<size_t,size_t>(row-1, col+1); break;
		case 2: return std::pair<size_t,size_t>(row-1, col  ); break;
		case 3: return std::pair<size_t,size_t>(row-1, col-1); break;
		case 4: return std::pair<size_t,size_t>(row  , col-1); break;
		case 5: return std::pair<size_t,size_t>(row+1, col-1); break;
		case 6: return std::pair<size_t,size_t>(row+1, col  ); break;
		case 7: return std::pair<size_t,size_t>(row+1, col+1); break;
		default:
			std::stringstream err;
			err << n << " is not a vaild neighbor. Use only 0-7.";
			throw (std::domain_error(err.str()));
	}
}
template <typename T>
std::pair<size_t,size_t> grid<T>::get_neighbor(int n, std::pair<size_t,size_t> cell) const {
	return get_neighbor(n, cell.first, cell.second);
}
