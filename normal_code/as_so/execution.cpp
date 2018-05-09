// This file will be linked with the sharable object to make our custom
// main as the main entry point.
#include <iostream>

// This is no loger the entry point of the program
int main() 
{
	std::cout << "This is now called by our version of main" << std::endl;

	// Redundant / Optional
	return 0;
}