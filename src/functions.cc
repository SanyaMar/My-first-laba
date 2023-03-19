#include <functions/functions.h>
#include <string>
#include <stdexcept>
#include <cassert>

using namespace std;
using namespace funct;

Vehicle::Vehicle(Transport _transport,string _model, int _engine_capacity_V, int _carrying_capacity_T, double _tax_rate_S) {
	this->_transport = _transport;
	this->_model = _model;
	this->_engine_capacity_V = _engine_capacity_V;
	this->_carrying_capacity_T = _carrying_capacity_T;
	this->_tax_rate_S = _tax_rate_S;
}

Vehicle::Vehicle(Transport _transport, string _model, int _engine_capacity_V, double _tax_rate_S) {
	this->_transport = _transport;
	this->_model = _model;
	this->_engine_capacity_V = _engine_capacity_V;
	this->_tax_rate_S = _tax_rate_S;
}

Vehicle::Vehicle() :_transport(Transport::CAR),_model("Wasik"), _engine_capacity_V(55),_tax_rate_S(1.5) {}


Vehicle Vehicle::create_car(string model_name, int engine_capacity, double tax_rate_S) {
	if ( (engine_capacity <= 0) || (tax_rate_S <= 0)) {
		throw invalid_argument("[Vehicle::create_car] Invalid argument.");
	}
	return Vehicle(Transport::CAR, model_name, engine_capacity, tax_rate_S);
}

Vehicle Vehicle::create_moto(string model_name, int engine_capacity, double tax_rate_S) {
	if ( (engine_capacity <= 0) || (tax_rate_S <= 0)) {
		throw invalid_argument("[Vehicle::create_moto] Invalid argument.");
	}
	return Vehicle(Transport::MOTORBIKE, model_name, engine_capacity, tax_rate_S);
}

Vehicle Vehicle::create_truck(std::string model_name, int engine_capacity, int tonnage, double tax_rate_S) {
	if ((tonnage <= 0) || (engine_capacity <= 0) || (tax_rate_S <= 0)) {
		throw invalid_argument("[Vehicle::create_truck] Invalid argument.");
	}
	return Vehicle(Transport::AUTOTRUCK, model_name, engine_capacity, tonnage, tax_rate_S);
}

int Vehicle::get_engine_capacity_V() {
	return _engine_capacity_V;
}

double Vehicle::get_tax_rate_S() {
	return _tax_rate_S;
}

int Vehicle::get_carrying_capacity_T() {
	return _carrying_capacity_T;
}

string Vehicle::get_model() {
	return _model;
}

Transport Vehicle::get_transport() {
	return _transport;
}
void Vehicle::set_tax_rate_S(double new_tax) {
	_tax_rate_S = new_tax;
}

double Vehicle::tax_calculation() {
	switch (_transport){
	case Transport::CAR:
		return _tax_rate_S * _engine_capacity_V;
	case Transport::AUTOTRUCK:
		return (_carrying_capacity_T / 2 + 1) * _engine_capacity_V * _tax_rate_S;
	case Transport::MOTORBIKE:
		return 0.3* _engine_capacity_V * _tax_rate_S;
	default:
		throw runtime_error("[funct::tax_calculation] Invalid function type.");
	}
}
