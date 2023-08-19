#include<gtest/gtest.h>
#include "src/SmartPoint.c"
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
    void * memRefObj = memRef(memObj);
    EXPECT_EQ(((MemoryClass *) memRefObj)->numRefObj, 2);
}

TEST(testCase,GiveMemObj_WhenMemRefFailed_ThenMemObjEqualToNull)
{
    void * memObj = NULL;
    void * memRefObj = memRef(memObj);
    EXPECT_EQ(memRefObj, (void *)NULL);
}

TEST(testCase,GiveAllocedMem_WhenMemReleaseSuccess_ThenCheckNumRefObjEqualOne)
{
    const size_t allocSize = 512;
    void * memObj = memAlloc(allocSize, NULL);
    void * memRefObj = memRef(memObj);
    void * memDerefObj = memDeref(memRefObj);
    EXPECT_EQ(((MemoryClass *) memDerefObj)->numRefObj, 1);
}
TEST(testCase,GiveAllocedMem_WhenMemDeRefSuccess_ThenmemDerefObjEqualToNULL)
{
    const size_t allocSize = 512;
    void * memObj = memAlloc(allocSize, NULL);
    EXPECT_EQ(((MemoryClass *) memObj)->numRefObj, 1);
    void * memDerefObj = memDeref(memObj);
    EXPECT_EQ(memDerefObj, (void *)NULL);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
    return 0;
}
