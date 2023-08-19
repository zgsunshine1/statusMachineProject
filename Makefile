CC = g++
CFLAGS = -g -Wall
CLIBS = -lpthread
SRC_DIRS = ./src/
TEST_DIRS = ./test/
GTEST = -Igtest/include -Lgtest/lib -lgtest -lgtest_main

TestSmartPoint:
	$(CC) $(CFLAGS) $(TEST_DIRS)SmartPointTest.c -o TestSmartPoint -I. $(GTEST) $(CLIBS)
TestStateMachine:
	$(CC) $(CFLAGS) $(TEST_DIRS)StateMachineTest.c -o TestStateMachine -I. $(GTEST) $(CLIBS)
.PHONY:
clean:
	rm TestSmartPoint TestStateMachine
