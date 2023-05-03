#pragma once
#include <string>
#include <iostream>

namespace funct{

	enum class Transport
	{
		CAR,
		AUTOTRUCK,
		MOTORBIKE
	};
	//using Ptr = Vehicle*;

	class Vehicle {
	private:
		Transport _transport;
		std::string _model;
		int _engine_capacity_V;
		int _carrying_capacity_T;
		double _tax_rate_S;

		Vehicle(Transport _transport, std::string _model, int _engine_capacity_V, int _carrying_capacity_T, double _tax_rate_S);
		Vehicle(Transport _transport, std::string _model, int _engine_capacity_V, double _tax_rate_S);

	public:

		double tax_calculation() const;
		static Vehicle* create_car(std::string model_name, int engine_capacity,double tax_rate_S);
		static Vehicle* create_truck(std::string model_name, int engine_capacity,int tonnage, double tax_rate_S);
		static Vehicle* create_moto(std::string model_name, int engine_capacity, double tax_rate_S);

	//Vehicle();
		
		int get_engine_capacity_V() const;
		int get_carrying_capacity_T() const;
		double get_tax_rate_S()const;
		std::string get_model()const;
		Transport get_transport()const;

		void set_tax_rate_S(double new_tax);
	};
	class Garage {	
	private:
		Vehicle** _garage;
		int _size;
	public:
		Garage();
		Garage(const Garage& gar);
		Garage& operator =(const Garage& rhs);
		int size()const;
		Vehicle* operator[](const int index) const;
		void insert(int index, Vehicle* machine);
		void remove(int index);
		void add(Vehicle* a);
		void swap(Garage& gar);
		~Garage();
	};
	int index_max_tax(const Garage& car);

	std::ostream& operator <<(std::ostream& ost, const Vehicle& trans);
}
