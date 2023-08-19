#include<gtest/gtest.h>
#include "SmartPoint.c"
using namespace std;

TEST(testCase,GiveAllocSize_WhenMemAllocSuccess_ThenRefObjNumEqualToOne)
{
    const size_t allocSize = 512;
    MemoryClass * memObj = (MemoryClass *)memAlloc(allocSize, NULL);
    EXPECT_EQ(memObj->numRefObj, 1);
}
TEST(testCase,GiveMemRef_WhenMemRefSuccess_ThenRefObjNumEqualToTwo)
{
    const size_t allocSize = 512;
    void * memObj = memAlloc(allocSize, NULL);
    memObj = memRef(memObj);
    EXPECT_EQ(((MemoryClass *) memObj)->numRefObj, 1);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
    return 0;
}
