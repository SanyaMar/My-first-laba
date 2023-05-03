#include <functions/functions.h>
#include <string>
#include <stdexcept>
#include <cassert>

using namespace std;
using namespace funct;

Garage::Garage() {
	_size = 0;
	_garage = nullptr;
}
int Garage::size()const {
	return _size;
}
Garage& Garage::operator=(const Garage& rhs) {
	Garage copy(rhs);
	copy.swap(*this);
	return *this;
}

Vehicle* Garage::operator[](const int index)const {
	if (index < 0 || index >= _size) {
		throw out_of_range("[Garage::operator[]] Index is out of range.");
	}
	return _garage[index];

}

void Garage::insert(int index, Vehicle* machine) {
	if (index >= _size ||index<0) {
		throw out_of_range("[Garage::remove] Index is out of range.");
	}
	auto new_garage = new Vehicle * [_size + 1];
	for (int i = 0;i < index;i++) {
		new_garage[i] = _garage[i];
	}
	new_garage[index] = machine;

	for (int i = index;i < _size;i++) {
		new_garage[i+1] = _garage[i];
	}
	delete[]_garage;
	_garage = new_garage;
	_size++;
}

void Garage::remove(int index) {
	if (index < 0 || index >= _size) {
		throw out_of_range("[Garage::remove] Index is out of range.");
	}
	auto new_garage = new Vehicle * [_size - 1];
	for (int i = 0;i < index;i++) {
		new_garage[i] = _garage[i];
	}
	for (int i = index + 1; i < _size;i++) {
		new_garage[i-1] = _garage[i];
	}
	delete _garage[index];
	delete[]_garage;
	_garage = new_garage;
	_size--;

}

Garage::Garage(const Garage& gar) {
	_garage = new Vehicle* [gar._size];
	_size = gar._size;
	for (int i = 0; i < _size; i++) {
		_garage[i] = gar[i];
	}
}
void Garage::add(Vehicle* a) {
	auto new_garage = new Vehicle * [_size + 1];
	for (int i = 0;i < _size;i++) {
		new_garage[i] = _garage[i];
	}
	new_garage[_size] = a;
	delete[] _garage;
	_garage = new_garage;
	_size++;
}


void Garage::swap(Garage& gar) {
	std::swap(this->_garage, gar._garage);
	std::swap(this->_size, gar._size);
}
Garage::~Garage() {
	for (int i = 0;i < _size; i++) {
		delete _garage[i];
	}
	delete[] _garage;
}

int funct::index_max_tax(const Garage& carpark) {
	double max_tax = 0;
	int ind = -1;
	const auto n = carpark.size();
	for (int i = 0;i <n ;i++) {
		if (carpark[i]->tax_calculation() > max_tax) {
			max_tax = carpark[i]->tax_calculation();
			ind = i;
		}
	}
	return ind;
}
