#include <iostream>
#include "String.h"
#include "Alloc.h"
using namespace std;
int main()
{
	Alloc alloc;
	String firstString("First");
	String secondString("Second");
	String thirdString(firstString);
	String fourthString("Fourth");
	String fifthString = String();
}
viod test_operator()
{ 
	cout << "+: " << firstString + secondString << endl;
	cout << "+=: " << (firstString += secondString) << endl;
}
	cout << "indexOf(String): " << firstString.indexOf(secondString) << endl;
	cout << "indexOf(char): " << firstString.indexOf('t') << endl;
	cout << "LT: " << (secondString < firstString) << endl;
	cout << "GT: " << (secondString > firstString) << endl;
	cout << "LE: " << (secondString <= firstString) << endl;
	cout << "GE: " << (secondString >= firstString) << endl;
	cout << "<<: " << fifthString << endl;
	cout << "<<: " << fourthString << endl;
	cout << "==: " << (secondString == firstString) << endl;
	cout << "indexOf(String): " << fourthString.indexOf(fifthString) << endl;
	cout << "size(): " << fifthString.size() << endl;
	cout << "size(): " << fourthString.size() << endl;
	cout << "[]: " << firstString[0] << endl;
	cout << "[]: " << firstString[firstString.size() - 1] << endl;
	cout << "[]: " << secondString[0] << endl;
	cout << "[]: " << secondString[secondString.size() - 1] << endl;
	//cout << "[]:" < fifthstring[0] < endl;
	cout << "!=: " << (thirdString != thirdString) << endl;
	cout << "Enter a test string: ";
	cin >> firstString;
	cout << firstString << endl;
	cout << (firstString < secondString) << endl;
	cout << (firstString <= thirdString) << endl;
	cout << (firstString > fourthString) << endl;
	cout << (firstString >= fifthString) << endl;
	firstString.~String();
	secondString.~String();
	thirdString.~String();
	fourthString.~String();
	fifthString.~String();
	alloc.report_allocations();
	return 0;
}