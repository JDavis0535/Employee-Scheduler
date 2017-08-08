#include "Schedule.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>
#include <fstream>


using namespace std;

int main()
{
	ifstream infile;

	infile.open("Schedule.txt");

	vector <string> names;
	vector <Schedule> Schedules;

	Schedule *theSchedule;
	Schedule test("18/19/2014 testing the schedule ");
	Schedule newSchedule;
	string nameString;
	string ScheduleString;
	string Savethename;
	string oneSched;
	string employeeName;
	string event2;
	string answer;
	string date;

	getline(infile, nameString, ':');
	infile.ignore();

	getline(infile, ScheduleString);

	while (!infile.eof()){
		names.push_back(nameString);
		Savethename = nameString;
		getline(infile, nameString, ':');
		while ( nameString == Savethename){
			infile.ignore();
			getline(infile, oneSched);
			//adds the first event with the new event for the same person...seperates with colon
			ScheduleString = ScheduleString + ";" + oneSched;

			getline(infile, nameString, ':');

		}
		//Schedule *theSchedule;
		//Schedule string is the data event pairs
		theSchedule = new Schedule(ScheduleString); 

		//
		Schedules.push_back(*theSchedule); 

		ScheduleString = " "; //clears Schedule string

	}

	char choice;
	do{
	cout << setw(8) << "MENU" << endl;
	cout << left << "a. Insert" << endl;
	cout << left << "b. Update" << endl;
	cout << left << "c. Search" << endl;
	cout << left << "d. Delete" << endl;
	cout << left << "e. Output" << endl;
	cout << left << "f. Quit" << endl;
	cout << left << "What would you like to do?" << endl;
	cout << left << "Choice:";

	cin >> choice;

	switch (choice){
	case 'a':
		
		cout << "You've chosing to insert a schedule..." << endl;
		cout << "What is the name of the employee you wish to insert? " << endl;
		cin.ignore();
		getline(cin, employeeName);
		if (std::find(names.begin(), names.end(), employeeName) != names.end()){
	
			cout << "This employee is already in the file " << endl;
			cout << "Returning to menu..." << endl;
			break;
			}
			else
			//use name and event
			cout << "This employee was not in the file..." << endl;
			cout << "Write the date followed by a space and the event" << endl;
			cin.ignore();
			getline(cin, event2);
			newSchedule.insertEvents(event2);
			Schedules.push_back(newSchedule);
			names.push_back(employeeName);

		break;

	case 'b':
		//update
		cout << "Updating the schedule..." << endl;
	
		break;
	case 'c':
		//search
		cout << "would you like to find the event by date or name?" << endl;
		cin >> answer;
		if (answer == "name"){
			cout << "Write the event you would like to find" << endl;
			cin.ignore();
			getline(cin, event2);
		}

		if (answer == "date"){
			cout << "Write the date of the events you would like to find" << endl;
			cin >> date;
		
		}
		break;
	case 'd':
		//delete
		cout << "input the date followed by a space and the event" << endl;
		cin.ignore();
		getline(cin, event2);
		cout << "Deleting event" << event2 << endl;

	

		break;
	case 'e':
		//output
		newSchedule.outputSchedule();
		break;
	case 'f':
		//save
		cout << "Saving to file..." << endl;
		test.saveSchedule();
		break;

	default:
		cout << "Invalid Selection. Please try Again." << endl;
	}//switch
	
	}while (!(choice == 'f'));

	return 0;
}