CXX = g++
CXXFLAGS = -g -std=c++11 -Wall -W -Werror -pedantic

sspapp: SSPapp.o Graph.o MinPriority.o
	$(CXX) -o sspapp SSPapp.o Graph.o MinPriority.o

SSPapp.o: SSPapp.cpp SSPapp.h Graph.h

Graph.o: Graph.cpp Graph.h MinPriority.h

MinPriority.o: MinPriority.cpp MinPriority.h

clean:
	rm -f *.o sspapp
