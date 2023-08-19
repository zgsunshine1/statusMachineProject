#include<gtest/gtest.h>
#include "src/StatusMachine.c"
using namespace std;

TEST(testCase,GiveCurrentStatusIdle_WhenExcutePostiveMove_ThenStatusEqualToPositive)
{
    currentStatus = IDLE;
    execute(POSITIVE);
    EXPECT_EQ(currentStatus, POSITIVE);
}
TEST(testCase,GiveCurrentStatusIdle_WhenExcuteNegativeMove_ThenStatusEqualToNegetive)
{
    currentStatus = IDLE;
    execute(NEGATIVE);
    EXPECT_EQ(currentStatus, NEGATIVE);
}
TEST(testCase,GiveCurrentStatusIdle_WhenExcuteIdle_ThenStatusEqualToIdle)
{
    currentStatus = IDLE;
    execute(IDLE);
    EXPECT_EQ(currentStatus, IDLE);
}
TEST(testCase,GiveInvalidStatus_WhenExcutePostiveMove_ThenStatusEqualToInvalid)
{
    currentStatus = INVALID_STATUS;
    execute(POSITIVE);
    EXPECT_EQ(currentStatus, INVALID_STATUS);
}


int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
    return 0;
}
