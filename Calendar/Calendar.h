#ifndef CALENDAR_H
#define CALENDAR_H
#pragma once
#include "String.h"
#include "Vector.h"
#include "Event.h"
#include <iostream>

class Calendar
{
private:
	Vector<Event> events;
	String date;

	size_t to_hours(size_t stime)
	{
		size_t hours = 0;
		while (stime > 60) {
			hours += 1;
			stime -= 60;
		}
		return hours * 100 + stime;
	}

	void add_day(String& date) {
		int int_date = date.to_int();
		int year = int_date % 10000;
		int month = (int_date / 10000) % 100;
		int day = int_date / 1000000;
		day++;
		if (month == 2) {
			if ((year % 4 == 0 && year % 100 != 0) || (year % 100 == 0 && year % 400 == 0)) {
				if (day == 30) {
					month++;
					day = 1;
				}
			}
			if (day == 29) {
				day = 1;
				month++;
			}
		}
		if ((month < 8 && month % 2 != 0) || (month >= 8 && month % 2 == 0)) {
			if (day == 32) {
				day = 1;
				month++;
			}
		}
		else {
			if (day == 31) {
				day = 1;
				month++;
			}
		}
		if (month == 13) {
			year++;
			month = 1;
		}

		String numDay = toString(day);
		String numMonth = toString(month);
		String numYear = toString(year);
		String newDate = numDay + "." + numMonth + "." + numYear;
		date = newDate;
	}

public:
	Calendar() {}
	Calendar(Vector<Event> _events);

	size_t getEventsSize();
	Event& operator[](size_t position);

	void book(Event event);
	void unbook(Event event);
	void agenda(String date);
	void change(Event event, String option, String newValue);
	void find(String keyWord);
	void holiday(String date);
	void busydays(String from, String to);
	void findslot(String date, size_t hours);
	void findslotwith(String from, size_t duration, Vector<Calendar> calendars);
	void merge(Vector<Calendar> calendars);

	friend std::ostream& operator<<(std::ostream& out, Calendar& c);
	friend std::istream& operator>>(std::istream& in, Calendar& c);
};

#endif