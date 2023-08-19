TestSmartPoint:
	g++ SmartPointTest.c -o TestSmartPoint -I. -Igtest/include -Lgtest/lib -lgtest -lgtest_main -lpthread
TestStateMachine:
	g++ StateMachineTest.c -o TestStateMachine -I. -Igtest/include -Lgtest/lib -lgtest -lgtest_main -lpthread
.PHONY:
clean:
	rm TestSmartPoint TestStateMachine
