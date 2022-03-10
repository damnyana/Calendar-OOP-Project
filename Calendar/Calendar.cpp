#include "Calendar.h"

Calendar::Calendar(Vector<Event> _events)
{
	events = _events;
}

size_t Calendar::getEventsSize()
{
	return events.getSize();
}

Event& Calendar::operator[](size_t position)
{
	return events[position];
}

void Calendar::book(Event event)
{
	if (!(events.is_member(event)))
	{
		events.push_back(event);
	}
	else std::cout << "There is already un event!" << std::endl;
}

void Calendar::unbook(Event event)
{
	if (events.is_member(event))
	{
		events.remove(event);
	}
	else std::cout << "There is no such event!" << std::endl;
}

void Calendar::agenda(String date)
{
	for (size_t i = 0; i < events.getSize(); i++)
	{
		if (events[i].getDate() == date)
		{
			std::cout << events[i];
		}
	}
}

void Calendar::change(Event event, String option, String newValue)
{
	unbook(event);
	if (option == "date") {
		book(Event(newValue, event.getStartTime(), event.getEndTime(), event.getName(), event.getNote()));
	}
	else if (option == "starttime") {
		book(Event(event.getDate(), newValue, event.getEndTime(), event.getName(), event.getNote()));
	}
	else if (option == "enddate") {
		book(Event(event.getDate(), event.getStartTime(), newValue, event.getName(), event.getNote()));
	}
	else if (option == "name") {
		book(Event(event.getDate(), event.getStartTime(), event.getEndTime(), newValue, event.getNote()));
	}
	else if (option == "note") {
		book(Event(event.getDate(), event.getStartTime(), event.getEndTime(), event.getName(), newValue));
	}
}

void Calendar::find(String keyWord)
{
	for (size_t i = 0; i < events.getSize(); i++) {
		if (events[i].getName().contains(keyWord) || events[i].getNote().contains(keyWord)) {
			std::cout << events[i];
		}
	}
}

void Calendar::holiday(String date)
{
	Event holiday = Event(date, "00:00", "23:59", "Holiday", "Free day!");
	book(holiday);
}

void Calendar::busydays(String from, String to)
{
	Vector<Event> busy_days;
	for (int i = 0; i < events.getSize(); i++) {
		if (events[i].getDate().to_int() >= from.to_int() && events[i].getDate().to_int() <= to.to_int()) {
			if (events[i].getName() != "Holiday") {
				busy_days.push_back(events[i]);
			}
		}
	}

	//??
}

void Calendar::findslot(String date, size_t hours)
{
	String curr = date;
	for (size_t i = 0;; i++)
	{
		int sTime = 800;
		if (i != 0) add_day(curr);
		while (sTime < 1700 && sTime + hours * 100 < 1700)
		{
			int eTime = sTime + hours * 100;
			if (hours > eTime - sTime) return;
			String sTime_check = toString(sTime);
			String eTime_check = toString(eTime);
			String start_time = "", end_time = "";
			if (sTime_check.length() == 3)
			{
				start_time = '0' + toString(sTime / 100) + ":" + toString(sTime % 100);
			}
			else start_time = toString(sTime / 100) + ":" + toString(sTime % 100);
			if (eTime_check.length() == 3)
			{
				end_time = '0' + toString(eTime / 100) + ":" + toString(eTime % 100);
			}
			else end_time = toString(eTime / 100) + ":" + toString(eTime % 100);

			Event test(curr, toString(sTime), toString(sTime), "test", "test");

			if (events.is_member(test))
			{
				sTime += 1;
				continue;
			}
			else
			{
				std::cout << "Found slot: " << curr << " " << start_time << " " << end_time << std::endl;
				return;
			}
		}
	}
}

void Calendar::findslotwith(String from, size_t duration, Vector<Calendar> calendars)
{
}


void Calendar::merge(Vector<Calendar> calendars)
{
	for (int i = 0; i < calendars.getSize(); i++) 
	{
		for (int j = 0; j < calendars[i].getEventsSize(); j++) 
		{
			events.push_back(calendars[i][j]);
		}
	}
}

std::ostream& operator<<(std::ostream& out, Calendar& c)
{
	for (size_t i = 0; i < c.getEventsSize(); i++) {
		out << c[i];
	}
	return out;
}

std::istream& operator>>(std::istream& in, Calendar& c)
{
	Vector<Event> eventsVec;
	Event event;

	while (in >> event) {
		eventsVec.push_back(event);
	}

	c = Calendar(eventsVec);
	return in;
}
