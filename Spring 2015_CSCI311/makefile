CC = g++
CFLAGS = -c -g -std=c++11 -Wall -W -Werror -pedantic
LDFLAGS = 

MSTapp: MSTapp.o Graph.o MinPriority.o
	$(CC) $(LDFLAGS) MSTapp.o Graph.o MinPriority.o -o MST

MSTapp.o: MSTapp.cpp Graph.h
	$(CC) $(CFLAGS) MSTapp.cpp

Graph.o: Graph.cpp Graph.h
	$(CC) $(CFLAGS) Graph.cpp

MinPriority.o: MinPriority.cpp MinPriority.h
	$(CC) $(CFLAGS) MinPriority.cpp
    
clean:
	rm *o MST
