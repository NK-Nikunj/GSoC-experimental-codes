CXXFLAGS = -Wl,-wrap=__libc_start_main -Wl,-wrap=__libc_csu_init

all: dynamic

dynamic: test.cpp
	$(CXX) $(CXXFLAGS) -o dynamic test.cpp hpx_wrap.o `pkg-config --cflags --libs hpx_application`
