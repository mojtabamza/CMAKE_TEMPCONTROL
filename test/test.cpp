
#include <gtest/gtest.h>
#include "../tempclass.cpp"


struct TF : public testing::Test {
    TemperatureControlSystem* room;
    void SetUp() { cout << "Setup" << endl; room = new TemperatureControlSystem(); }
    void TearDown() { cout << "Teardown" << endl; delete room; }
};

TEST_F(TF, SetTemperatureTest) {
    room->setMinMaxTemp(18.0, 25.0);
    EXPECT_EQ(room->getMaxTemp(), 25.0);
    EXPECT_EQ(room->getMinTemp(), 18.0);
    room->setMinMaxTemp(12.4, 28.7);
    EXPECT_EQ(room->getMaxTemp(), 28.7);
    EXPECT_EQ(room->getMinTemp(), 12.4);
}

TEST_F(TF, SetTemperatureTest_InvalidValues) {
    //negative value is invalid in this system
    EXPECT_EQ(room->setMinMaxTemp(-1, 25.0), INVALID);
    EXPECT_EQ(room->setMinMaxTemp(-10, -25.0), INVALID);

    //minimum can not be greater than maximum
    EXPECT_EQ(room->setMinMaxTemp(26, 17), INVALID);
}
TEST_F(TF, OprerationTest) {
    room->setMinMaxTemp(18.0, 25.0); //set min and max temp to [18.0 , 25.0]
    room->setCurrentTemp(12); //to simulate the current temp is 12
    EXPECT_EQ(room->controlTask(), HEATER_ON);//in temp = 12 sys is expected to run HEATER
    room->setCurrentTemp(18.5);
    EXPECT_EQ(room->controlTask(), NORMAL_CONDITION);//in temp = 18.5 sys is expected to do NOTHING
    room->setCurrentTemp(26);
    EXPECT_EQ(room->controlTask(), COOLER_ON); //in temp = 26 sys is expected to run COOLER
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}