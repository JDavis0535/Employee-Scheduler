#include <iostream>
#include <iomanip>
#include <string>
#include <time.h>

using namespace std;

class Date{
private:
	//Member variables
	friend ostream& operator<<(ostream & os, Date & dt){
		os << dt.month << '/' << dt.day << '/' << dt.year << " " << dt.event;
		
		return os;
	}

	friend istream& operator>>(istream & is, Date & dt){
		is >> dt.month >> dt.day >> dt.year;
		return is;
	}

	int year; //will hold the year value
	int month; //will hold the month value
	string event;
	int day; //will hold the day value
	bool shortDisplay; //will help set the way the date is outputted

public:

	//Default constructor
	Date();

	//constructors
	Date(int y, int m, int d); //constructor sets year,month, and day
	Date(int y, int m); //constructor sets year,month
	Date(int y); //constructor sets year
	Date(const Date & otherDate); //constructor sets date from another date object
	Date(string dateStr); //constructor sets date based on string
	Date(string datestr, string eventStr); //constructor sets date and seven based on strings

	//Overloaded Mutators
	void setDate(int y, int m, int d); //sets the year, month and day
	void setDate(int y, int m); //sets the year, month
	void setDate(int y); //sets the year
	void setDate(Date otherDate); //error when using...removed and worked
	void setDate(string dateStr); //sets the date of a string
	void setDate(string dateStr, string eventStr); //sets the date and event

	//Mutators
	void setYear(int y); //sets the value of y into year
	void setMonth(int m); //sets the value of m into month
	void setEvent(string e); //sets event to e
	void setDay(int d); //sets the value of d into day

	//Accessors
	int getYear(); //returns year
	string getEvent(); //returns event
	int getMonth(); //returns month
	int getDay(); //returns day

	//Mutators
	void setShortDisplay(); //Output will be shortDisplay
	void setLongDisplay(); //Output will be LongDisplay

	bool isShortDisplay(); //returns the value of shortDisplay

	int operator++(int d); // overload ++ operator
	int operator+=(int d); //overload += operator
	bool operator==(Date otherDate); //overload == operator
	bool operator<(Date otherDate); //overload < operator

	string toString(); //will set int date to string date
	string monthString(int month); //will return a string representation of the month integer
};