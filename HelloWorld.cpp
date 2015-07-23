#include <iostream>
#include <ctime>
#include <iomanip>
#include <time.h>

void binary(int number) {
	int remainder;
	int result;
	if(number <= 1) {
		std::cout << number << std::endl;
		return;
	}

	remainder = number%2;
	binary(number >> 1);    
	std::cout << remainder << std::endl;
}

void getDigit(int number) {
		do {
    	int digit = number % 10;
    	putchar('0' + digit);
    	number /= 10;
	} while (number > 0);
}

int main()
{
	std::time_t result = std::time(nullptr);
	int hour = std::localtime(&result)->tm_hour;
	int min = std::localtime(&result)->tm_min;
	int sec = std::localtime(&result)->tm_sec;

	getDigit(hour);

	std::cout << min << std::endl;
	std::cout << sec << std::endl;
	return 0;
}

