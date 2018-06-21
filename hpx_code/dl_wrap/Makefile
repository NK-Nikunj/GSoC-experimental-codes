CXXFLAGS = -Wl,-wrap=__libc_start_main -Wl,-wrap=__libc_csu_init

all: test_1 test_2 test_3

test_1: test_1.cpp
	$(CXX) $(CXXFLAGS) -o test_1 test_1.cpp hpx_wrap.o `pkg-config --cflags --libs hpx_application` -lhpx_iostreams -DHPX_APPLICATION_NAME=test_1

test_2: test_2.cpp
	$(CXX) $(CXXFLAGS) -o test_2 test_2.cpp hpx_wrap.o `pkg-config --cflags --libs hpx_application` -lhpx_iostreams -DHPX_APPLICATION_NAME=test_2

test_3: test_3.cpp
	$(CXX) $(CXXFLAGS) -o test_3 test_3.cpp hpx_wrap.o `pkg-config --cflags --libs hpx_application` -lhpx_iostreams -DHPX_APPLICATION_NAME=test_3
