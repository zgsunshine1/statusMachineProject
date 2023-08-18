TestSmartPoint:
	g++ SmartPointTest.c -o TestSmartPoint -I. -Igtest/include -Lgtest/lib -lgtest -lgtest_main -lpthread
.PHONY:
clean:
	rm TestSmartPoint
