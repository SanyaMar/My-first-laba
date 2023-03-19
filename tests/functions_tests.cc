#include <gtest/gtest.h>

#include <functions/functions.h>
using namespace std;
using namespace funct;

TEST(FunctionsTests, TaxCalculationTest) {
    Vehicle car = Vehicle::create_car("ferra", 20,0.6);
    EXPECT_DOUBLE_EQ(car.tax_calculation(), 12);
    
    Vehicle autotruck = Vehicle::create_truck("kamaz", 50, 100,0.7);
    EXPECT_DOUBLE_EQ(autotruck.tax_calculation(), 1785);
  
    Vehicle motorbike = Vehicle::create_moto("yamaha", 44, 0.8);
    EXPECT_DOUBLE_EQ(motorbike.tax_calculation(), 10.56);
}
TEST(FunctionsTests, ConstructorTest) {
    Vehicle empty;
    EXPECT_EQ(empty.get_transport(), Transport::CAR);
}
TEST(FunctionsTests, SetsTest) {
    Vehicle motorbike = Vehicle::create_moto("yamaha", 65, 3.5);
    motorbike.set_tax_rate_S(8.8);
    EXPECT_DOUBLE_EQ(motorbike.get_tax_rate_S(),8.8);
}
TEST(FunctionsTests, InvalidArgument){
    ASSERT_ANY_THROW(Vehicle::create_truck("Kamaz", 40, -10, 3.6));
}
