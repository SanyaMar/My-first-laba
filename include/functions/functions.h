#pragma once
#include <string>


namespace funct{

	enum class Transport
	{
		CAR,
		AUTOTRUCK,
		MOTORBIKE
	};

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

		double tax_calculation();
		static Vehicle create_car(std::string model_name, int engine_capacity,double tax_rate_S);
		static Vehicle create_truck(std::string model_name, int engine_capacity,int tonnage, double tax_rate_S);
		static Vehicle create_moto(std::string model_name, int engine_capacity, double tax_rate_S);

		Vehicle();
		
		int get_engine_capacity_V();
		int get_carrying_capacity_T();
		double get_tax_rate_S();
		std::string get_model();
		Transport get_transport();

		void set_tax_rate_S(double new_tax);
	};
	class Garage {
	public:
		static const int CAPACITY = 10;

	
	private:
		Vehicle _garage[CAPACITY];
		int _size;
	public:
		Garage();
		int size()const;
		Vehicle operator[](const int index) const;
		void insert(int index, Vehicle machine);
		void remove(int index);
	};
	int index_max_tax(const Garage& car);
}
