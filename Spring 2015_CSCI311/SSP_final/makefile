CXX = g++
CXXFLAGS = -g -std=c++11 -Wall -W -Werror -pedantic

ssp: sspapp.o graph.o minpriority.o
	$(CXX) -o ssp sspapp.o graph.o minpriority.o

sspapp.o: sspapp.cpp sspapp.h

graph.o: graph.cpp graph.h

minpriority.o: minpriority.cpp minpriority.h

clean:
	rm -f *.o ssp
