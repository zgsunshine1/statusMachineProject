#include<gtest/gtest.h>
#include "Status.h"
using namespace std;

TEST(testCase,GiveCurrentStatusIdle_WhenExcutePostiveMove_ThenCheckFinalStatus)
{
    currentStatus = IDLE;
    execute(POSITIVE);
}
TEST(testCase,GiveCurrentStatusIdle_WhenExcuteNegativeMove_ThenCheckFinalStatus)
{
    currentStatus = IDLE;
    execute(NEGATIVE);
}
int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
    return 0;
}
