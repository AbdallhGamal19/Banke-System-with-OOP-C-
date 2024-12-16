#pragma once
#include "clsDate.h";
#include <string>
#include <sstream> // For stringstream
class clsInputValidate
{
public:
	static int IsNumberBetween(int number ,int from , int to) {
		return (number >= from && number <= to);
	}
	static int IsNumberBetween(float number, float from, float to) {
		return number > from && number < to;
	}
	static int IsNumberBetween(double number, double from, double to) {
		return number > from && number < to;
	}
	static bool IsDateBetween(clsDate date, clsDate fromDate, clsDate toDate) {

		if ((clsDate::IsDate1AfterDate2(date, fromDate) || clsDate::IsDate1EqualDate2(date, fromDate)) &&
			(clsDate::IsDate1BeforeDate2(date, toDate) || clsDate::IsDate1EqualDate2(date, toDate))) {
			return true;
		}
		if ((clsDate::IsDate1AfterDate2(date, toDate) || clsDate::IsDate1EqualDate2(date, toDate)) &&
			(clsDate::IsDate1BeforeDate2(date, fromDate) || clsDate::IsDate1EqualDate2(date, fromDate))) {
			return true;
		}
		
		return false;
	}
	static bool isValidDate(clsDate date) {
		return clsDate::IsValidDate(date);
	}
	//static bool IsInteger(const string& input) {
	//	stringstream ss(input);
	//	int number;
	//	// Try to parse the input as an integer
	//	return (ss >> number) && (ss.eof());
	//}
	//read int only number 
	//static string  ReadIntNumber(string message) {
	//	
	//	string number;
	//	cout << "Enter a Integer Number\n";
	//	cin >> number;
	//	while (!IsInteger(number))
	//	{
	//		cin.fail();
	//		cout << message << endl;
	//		// Clear the error state
	//		cin.clear();
	//		// Ignore the rest of the input
	//		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	//		cin >> number;
	//	}
	//	
	//	return number;
	//}
	//read int or float and convert float to int
	static  bool IsInteger() {
		while (cin.fail())
		{
			// Clear the error state
			cin.clear();
			// Ignore the rest of the input
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			return true;
		}
	}
	static int  ReadIntNumber(string message) {

		int number;
		cout << "Enter a Integer Number\n";
		cin >> number;
		while (cin.fail())
		{
			cout << message << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin >> number;
		}

		return number;
	}

	static short ReadShortNumber(string ErrorMessage = "Invalid Number, Enter again\n")
	{
		short Number;
		while (!(cin >> Number)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage;
		}
		return Number;
	}

	static short ReadShortNumberBetween(short From, short To, string ErrorMessage = "Number is not within range, Enter again:\n")
	{
		short Number = ReadShortNumber();
		cout << Number<<endl;
		while (!IsNumberBetween(Number, From, To))
		{
			cout << ErrorMessage;
			Number = ReadShortNumber();
		}
		return Number;
	}
	static int ReadIntNumberBetween(int from , int to , string message) {
		
		int number;
		cout << "Enter number between " << from << " to " << to << " !";
		cin >> number;
		while (IsInteger())
		{
			cout << message << endl;
			cin >> number;
		}
		if (IsNumberBetween(number,from,to)) {
			return number;
		}
		else {
			
			return ReadIntNumberBetween(from, to, message);
		}
	;
	}
	static double  ReadDoubleNumber() {

		double number;
		cin >> number;
		while (cin.fail())
		{

			// Clear the error state
			cin.clear();
			// Ignore the rest of the input
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin >> number;
		}

		return number;
	}
	static double ReadDoubleNumberBetween(double from, double to, string message) {

		double number;
		cout << "Enter number between " << from << " to " << to << " !";
		cin >> number;
		while (IsInteger())
		{
			cout << message << endl;
			cin >> number;
		}
		if (IsNumberBetween(number, from, to)) {
			return number;
		}
		else {

			return ReadDoubleNumberBetween(from, to, message);
		}
	}
	static float  ReadFloatNumber(string message="") {

		float number;

		cin >> number;
		while (cin.fail())
		{

			cout << message << endl;
			// Clear the error state
			cin.clear();
			// Ignore the rest of the input
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin >> number;
		}

		return number;
	}
	static double ReadFloatNumberBetween(float from, float to, string message) {

		float number;
		cout << "Enter number between " << from << " to " << to << " !";
		cin >> number;
		while (IsInteger())
		{
			cout << message << endl;
			cin >> number;
		}
		if (IsNumberBetween(number, from, to)) {
			return number;
		}
		else {

			return ReadDoubleNumberBetween(from, to, message);
		}
	}
	static string ReadString()
	{
		string  S1 = "";
		// Usage of std::ws will extract allthe whitespace character
		getline(cin >> ws, S1);
		return S1;
	}
};

