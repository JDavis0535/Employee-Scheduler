#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include "Schedule.h"
#include <vector>
#include <string>
#include <algorithm>

Schedule::Schedule(){
	
	mustRemember.clear();
}

Schedule::Schedule(string date_event_pairs){

	string dateStr, eventStr;
	bool   endOfString = false;
	int numStartPos, numEndPos;

	numStartPos = 0;
	numEndPos = date_event_pairs.find_first_of(" ");
	if (numEndPos == string::npos)
	{
		cout << "String not long enough to form schedule" << endl;
		endOfString = true;
	}
	while (!endOfString)// Create multiple Date objects and put them in vector from a string of date-event pairs
	{
		dateStr = date_event_pairs.substr(numStartPos, (numEndPos - numStartPos));
		numStartPos = numEndPos + 1;
		numEndPos = date_event_pairs.find_first_of(";", numStartPos);
		if (numEndPos == string::npos)
		{
			numEndPos = date_event_pairs.length();
			endOfString = true;
		}
		eventStr = date_event_pairs.substr(numStartPos, (numEndPos - numStartPos));
		
		Date newDate(dateStr, eventStr); // One Date constructor changed to take two string parameters – date and event
		mustRemember.push_back(newDate);
		numStartPos = numEndPos + 1;
		numEndPos = date_event_pairs.find_first_of(" ", numStartPos);
	}

}

void Schedule::insertEvents(string date_event_pairs){
	
	Date newObject;

	newObject.setEvent(date_event_pairs);

	mustRemember.push_back(newObject);
	
}

void Schedule::outputSchedule(){

	sort(mustRemember.begin(), mustRemember.end());

	vector <Date>::iterator iter;

	for (iter = mustRemember.begin(); iter < mustRemember.end(); iter ++){
		cout << iter->toString() << " " << iter->getEvent();
		
	}
}

void Schedule::updateSchedule(string event){

}

void Schedule::deleteEvent(string value){
	for (std::vector<Date>::iterator iter = mustRemember.begin(); iter != mustRemember.end(); ++iter)
	{
		if (*iter == value)
		{
			mustRemember.erase(iter);
			break;
		}
	}
}

void Schedule::searchEvent(string event){
	
	Date searchDate(event);

	vector<Date>::iterator searchIter;

	searchIter = find (mustRemember.begin(), mustRemember.end(), event);

	if (searchIter == mustRemember.end()){
		cout << "the event was not found" << endl;
	}

	else
		//process the found event

		cout << "the event was found " << *searchIter << endl;

}

void Schedule::saveSchedule(){
	cout << "Copying your schedule to the selected text file..." << endl;
	ofstream output_file("opSchedule.txt");
	
	for (int i = 0; i < mustRemember.size(); i++)
	{
		output_file << mustRemember[i] << endl;

	}
	
	
	/*ostream_iterator<string> output_iterator(output_file, "\n");
	copy(mustRemember.begin(), mustRemember.end(), output_iterator);
	*/
}