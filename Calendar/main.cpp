#include <iostream>
#include "String.h"
#include "Vector.h"
#include "Event.h"
#include "Calendar.h"
#include "MyCalendar.h"

int main()
{
	MyCalendar tst;
	//tst.open("test.txt");
	tst.startSystem();

	/*Event ev;
	Vector<Event> evs;
	for (int i = 0; i < 5; i++) {
		std::cin >> ev;
		evs.push_back(ev);
	}

	Calendar cal(evs);
	Vector<Event> evs1;
	for (int i = 0; i < 5; i++) {
		std::cin >> ev;
		evs1.push_back(ev);
	}
	Calendar cal1(evs1);
	Vector<Event> evs2;
	for (int i = 0; i < 5; i++) {
		std::cin >> ev;
		evs2.push_back(ev);
	}
	Calendar cal2(evs2);
	Vector<Calendar> calendars;
	//Event ev = Event("12.04.2021", "12:30", "15:30", "tst", "tst");
	/*Event ev;
	Vector<Event> evs;
	for (int i = 0; i < 2; i++) {
		std::cin >> ev;
		evs.push_back(ev);
	}*/

	//tst.startSystem();
}