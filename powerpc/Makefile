all: main

main: main.cpp.o wrap_libc.cpp.o
	$(CXX) -Wl,-wrap=__libc_start_main -o main main.cpp.o wrap_libc.cpp.o
	rm main.cpp.o wrap_libc.cpp.o

main.cpp.o: main.cpp
	$(CXX) -c -o main.cpp.o main.cpp

wrap_libc.cpp.o : wrap_libc.cpp
	$(CXX) -c -o wrap_libc.cpp.o wrap_libc.cpp

clean:
	rm main
