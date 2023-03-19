#include <gtest/gtest.h>

#include <functions/functions.h>
using namespace std;
using namespace funct;

TEST(GarageTests, FirstGarage) {
	Garage lamba;
	lamba.insert(3, Vehicle::create_car("aventador",65,5.2));
	lamba.insert(1, Vehicle::create_car("gallardo", 54, 2.8));
	lamba.insert(3, Vehicle::create_car("sian", 66, 3.1));
	EXPECT_EQ(index_max_tax(lamba), 0);
}
TEST(GarageTest, FullGarage) {
	Garage ordinary;
	for (int i = 0;i < Garage::CAPACITY;i++) {
		ordinary.insert(1, Vehicle::create_car("gallardo", 54, 2.8));
	}
	ASSERT_ANY_THROW(ordinary.insert(1, Vehicle::create_car("gallardo", 54, 2.8)));
}
TEST(GarageTest, WrongGarage) {
	Garage ordinary;
	ASSERT_ANY_THROW(ordinary.insert(-1, Vehicle::create_car("gallardo", 54, 2.8)));
}
TEST(GarageTests, EmptyGarage) {
	Garage sad;
    EXPECT_EQ(index_max_tax(sad), -1);
}