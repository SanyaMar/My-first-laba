#include <functions/functions.h>
#include <string>
#include <stdexcept>
#include <cassert>

using namespace std;
using namespace funct;

Garage::Garage() {
	_size = 0;
}
int Garage::size()const {
	return _size;
}
Vehicle Garage::operator[](const int index)const {
	if (index < 0 || index >= _size) {
		throw out_of_range("[Garage::operator[]] Index is out of range.");
	}
	return _garage[index];
}
void Garage::insert(int index, Vehicle machine) {
	if (index < 0 || index >= CAPACITY || CAPACITY==_size) {
		throw out_of_range("[Garage::insert] Index is out of range.");
	}
	if (index <= _size) {
		for (int i = _size;i > index;i--) {
			_garage[i] = _garage[i - 1];
		}
		_garage[index] = machine;
		_size++;
	}
	else {
		_garage[_size] = machine;
		_size++;
	}
}
void Garage::remove(int index) {
	if (index < 0 || index >= _size) {
		throw out_of_range("[Garage::remove] Index is out of range.");
	}
	for (int i = index;i < _size;i++) {
		_garage[i] = _garage[i + 1];
	}
	_size--;
}
int funct::index_max_tax(const Garage& carpark) {
	double max_tax = 0;
	int ind = -1;
	for (int i = 0;i < carpark.size();i++) {
		if (carpark[i].tax_calculation() > max_tax) {
			max_tax = carpark[i].tax_calculation();
			ind = i;
		}
	}
	return ind;
}