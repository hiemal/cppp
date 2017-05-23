CXX:= clang++
FLAGS:=-std=c++11


cppp: cppp.o main.o
	$(CXX) $(FLAGS) -lpthread cppp.o main.o -o test

main.o: main.cpp
	$(CXX) $(FLAGS) -c main.cpp 

cppp.o: cppp.cpp
	$(CXX) $(FLAGS) -c cppp.cpp 

clean:
	rm test *.o 
