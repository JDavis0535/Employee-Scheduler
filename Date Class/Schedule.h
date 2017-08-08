#include <iostream>
#include <iomanip>
#include <string>
#include "Dateh.h"
#include <vector>


using namespace std;

class Schedule{

private:
	
	vector<Date> mustRemember;

public:

	Schedule();
	Schedule(string date_event_pairs);

	void insertEvents(string date_event_pairs);
	void updateSchedule(string event);
	void deleteEvent(string value);
	void searchEvent(string event);
	void outputSchedule();
	void saveSchedule();
	void extractor(string date_event_pairs);


};