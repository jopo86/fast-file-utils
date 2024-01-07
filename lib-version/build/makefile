lib:
	g++ -std=c++17 -c ../src/*.cpp
	ar rvs libffu.a ffu.o
	rm *.o

test:
	g++ -std=c++17 -o ffu ../src/*.cpp ../tests/tests.cpp
	./ffu

test-compile:
	g++ -std=c++17 -o ffu ../src/*.cpp ../tests/tests.cpp

test-run:
	./ffu

clean:
	rm *.exe
	rm *.a
