#include "Dateh.h"
#include <iostream>
#include <string>
#include <time.h>
#include <iomanip>
#include <ctime>

using namespace std;

Date::Date(){ //default constructor of the date class. Sets to today's date
	shortDisplay = true; //sets the output to shortDisplay
	time_t curtime = time(0);
	struct tm *time_in_parts = new tm;
	localtime_s(time_in_parts , &curtime);
	int currentyear = time_in_parts->tm_year + 1900;
	int currentmonth = time_in_parts->tm_mon + 1;
	int currentday = time_in_parts->tm_mday;
	year = currentyear;
	month = currentmonth;
	day = currentday;
}

Date::Date(int y, int m, int d){
	shortDisplay = true;
	setDate(y, m, d);
}

Date::Date(int y, int m){
	shortDisplay = true;
	day = 1;
	setDate(y, m);
}

Date::Date(int y){
	month = 1;
	day = 1;
	shortDisplay = true;
	setDate(y);
}

Date::Date(const Date &otherDate){
	shortDisplay = true;

	year = otherDate.year;
	day = otherDate.day;
	month = otherDate.month;
}

Date::Date(string dateStr){
	setDate(dateStr);
}

Date::Date(string dateStr, string eventStr){
	setDate(dateStr);
	setEvent(eventStr);
}

void Date::setDate(int y, int m, int d){
	setYear(y);
	setMonth(m);
	setDay(d);
}

void Date::setDate(int y, int m){
	setYear(y);
	setMonth(m);
}

void Date::setDate(int y){
	setYear(y);
}

void Date::setDate(string dateStr){
	int dateStrlen = dateStr.length();
	int found = dateStr.find('/');

	if (found != string::npos){
		string monthStr = dateStr.substr(0, 2);
		string dayStr = dateStr.substr(3, 2);
		string yearStr = dateStr.substr(6, 4);
		month = atoi(monthStr.c_str());
		day = atoi(dayStr.c_str());
		year = atoi(yearStr.c_str());
		event = getEvent();
	}
	else
		;


}

void Date::setYear(int y){
	if (y < 1900){
		cout << "Invald year, Please reenter a different date" << endl;
	}
	year = y;
}

void Date::setEvent(string e){

	event = e;
}

void Date::setMonth(int m){
	if (m < 1 || m>12){
		cout << "Invalid month, please reenter a different date" << endl;
	}
	month = m;
}

void Date::setDay(int d){
	int days_in_month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	
	if (d < 1){
		cout << "Invalid day, please reenter a different date" << endl;
	}
	day = d;
}

int Date::getYear(){
	return year;
}

int Date::getDay(){
	return day;
}

int Date::getMonth(){
	return month;
}

string Date::getEvent(){
	return event;
}

void Date::setShortDisplay(){
	shortDisplay = true;
}

void Date::setLongDisplay(){
	shortDisplay = false;
}

bool Date::isShortDisplay(){
	return shortDisplay;
}

int Date::operator++(int d){
	int days_in_month[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	if (d == days_in_month[month - 1]){
		d = 1;
		month++;

		if (month == 13){
			month = 1;
			year++;
		}
	}
	else
		d++;
	day = d;
	return day;
}

int Date::operator+=(int d){
	int days_in_month[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	day += d;

	while (day > days_in_month[month]){
		day = day - days_in_month[month];
		month++;
		if (month > 12){
			year++;
			month = 1;
		}
	}

	return day;
}

bool Date::operator==(Date otherDate){
	bool equal;

	if (day == otherDate.day && month == otherDate.month && year == otherDate.year){
		equal = true;
	}

	else
		equal = false;
	return equal;
}

bool Date::operator<(Date otherDate){
	bool checkDate = false;

	if (year < otherDate.year) {
		checkDate = true;
		return checkDate;
	}

	if (year < otherDate.year && month < otherDate.month){
		checkDate = true;
		return checkDate;
	}

	if (year < otherDate.year && month < otherDate.month && day < otherDate.day){
		checkDate = true;
		return checkDate;
	}

	else
		return checkDate;
}

string Date::toString(){
	/*The short form will give the month first, followed by a slash, then the day, another slash, and
	then finally the year.Always use two digits for both the month and the day, and four digits
	for the year; e.g.“10 / 28 / 2008” or “04 / 01 / 1999”.*/

	string finalString;
	
	string slash1 = "/";
	string slash2 = "/";
	string blank = " ";
	string comma = ",";
	if (shortDisplay == true){
		string monthString = to_string(month);
		string dayString = to_string(day);
		string yearString = to_string(year);
	
		finalString = monthString + slash1 + dayString + slash2 + yearString;
	}

	if (shortDisplay == false){
		string monthTest = monthString(month);
		string dayString2 = to_string(day);
		string yearString = to_string(year);

		finalString = monthTest + blank + dayString2 + comma + blank + yearString;
	}
	return finalString;
}

string Date::monthString(int month){
	string monthz[12] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };

	string theMonth = monthz[month];

	if (month < 1 || month > 12){
		cout << "invalid month" << endl;
	}

	return theMonth;

	//{ "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", 'November', "December" };
}