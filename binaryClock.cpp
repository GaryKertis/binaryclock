#include <iostream>
#include <ctime>
#include <iomanip>
#include <time.h>
#include <bitset>

using namespace std;

void binary(int number) {
	int remainder;
	int result;
	if(number <= 1) {
		cout << number << endl;
		return;
	}

	remainder = number%2;
	binary(number >> 1);    
	cout << remainder << endl;
}

string getBinary(int number) {
	string result = bitset<4>(number).to_string();
	return result;
}

string * getDigit(int number) {

 	static string arr[2];
	int index = 0;

	do {

    	int digit = number % 10;
    	arr[index] = getBinary(digit);
    	number /= 10;
    	index++;
	} while (number > 0);

	return arr;
}

void outPut(string *number) {
	string first = *(number+1);
	string second = *(number+0);
	cout << first << " " << second;
}

int main()
{
	time_t result = time(nullptr);
	int hour = localtime(&result)->tm_hour;
	int min = localtime(&result)->tm_min;
	int sec = localtime(&result)->tm_sec;

	outPut(getDigit(hour));
	cout << " : ";
	outPut(getDigit(min));
	cout << " : ";
	outPut(getDigit(sec));
	cout << endl;

	return 0;
}

