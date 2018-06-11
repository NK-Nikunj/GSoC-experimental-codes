CXXFLAGS = -Wl,-wrap=__libc_start_main

all: static dynamic

static: test.o wrap_libc.o
	$(CXX) $(CXXFLAGS) -static -o static test.o wrap_libc.o

dynamic: test.o wrap_libc.o
	$(CXX) $(CXXFLAGS) -o dynamic test.o wrap_libc.o

test.o: test.cpp
	$(CXX) -c -o test.o test.cpp
