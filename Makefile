CC = g++
CFLAGS = -g -Wall
CLIBS = -lpthread
SRC_DIRS = ./src/
TEST_DIRS = ./test/
DIR_BIN = ./bin/
GTEST = -Igtest/include -Lgtest/lib -lgtest -lgtest_main

TestSmartPoint:
	$(CC) $(CFLAGS) $(TEST_DIRS)SmartPointTest.c -o $(DIR_BIN)TestSmartPoint -I. $(GTEST) $(CLIBS)
TestStateMachine:
	$(CC) $(CFLAGS) $(TEST_DIRS)StateMachineTest.c -o $(DIR_BIN)TestStateMachine -I. $(GTEST) $(CLIBS)
.PHONY:
clean:
	rm $(DIR_BIN)*
