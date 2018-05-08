// This will include all the hooking code necessary to call our version
// of main instead of compiler's main
#include "hooking_part.h"
#include <iostream>

// This is no loger the entry point of the program
int main() 
{
	std::cout << "This is now called by our version of main" << std::endl;

	// Redundant / Optional
	return 0;
}