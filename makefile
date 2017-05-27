CXX:= clang++
FLAGS:=-std=c++11


test: test.o
	$(CXX) $(FLAGS) -lpthread test.o -o test

test.o: test.cpp
	$(CXX) $(FLAGS) -c test.cpp 

clean:
	rm test *.o 
