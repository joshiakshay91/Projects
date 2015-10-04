CXX = g++
CXXFLAGS = -c -g -std=c++11 
LDFLAGS = -lrt

PROG = SuffA
HDRS = SuffixArray.h
SRCS = SuffixArray.cpp main.cpp
OBJS = $(SRCS:.cpp=.o)

$(PROG) : $(OBJS)
	$(CXX) $(LDFLAGS) $(OBJS) -o $(PROG)

Suffi.o : main.cpp SuffixArray.cpp SuffixArray.h
	$(CXX) $(CXXFLAGS) SuffixArray.cpp

clean :
	rm -f core $(PROG) *.o
