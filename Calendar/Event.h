#pragma once
#include "String.h"
#include <iostream>
#include <exception>

class Event
{
private:
	String date;
	String start_time;
	String end_time;
	String name;
	String note;

	void check_time(String time) {
		if (time.length() != 5 || time[2] != ':') {
			throw std::length_error("wrong format");
		}
		if (time.to_int() < 0 || time.to_int() > 2359) {
			throw std::invalid_argument("time must be from 00:00 to 23:59");
		}
		for (int i = 0; i < time.length(); i++) {
			if (i == 2) continue;
			if (time[i] < '0' || time[i] > '9') {
				throw std::invalid_argument("wrong input");
			}
		}
		if (time.to_int() % 100 > 59) {
			throw std::invalid_argument("wrong input");
		}
		if (time.to_int() / 100 > 23) {
			throw std::invalid_argument("wrong input");
		}
	}

	void check_date(String date) {
		Vector<String> split_date = date.split('.');
		if (date.length() != 10 || split_date[0].length() != 2 || split_date[1].length() != 2 || split_date[2].length() != 4) {
			throw std::length_error("wrong format");
		}
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < split_date[i].length(); j++) {
				if (split_date[i][j] < '0' || split_date[i][j] > '9') {
					throw std::invalid_argument("wrong input");
				}
			}
		}
		if (split_date[1].to_int() > 12) {
			throw std::invalid_argument("wrong input");
		}
		else {
			if (split_date[1].to_int() == 2) {
				if ((split_date[2].to_int() % 4 == 0 && split_date[0].to_int() % 100 != 0) || (split_date[0].to_int() % 100 == 0 && split_date[0].to_int() % 400 == 0)) {
					if (split_date[0].to_int() > 29) {
						throw std::invalid_argument("wrong input");
					}
				}
				else if (split_date[0].to_int() > 28) {
					throw std::invalid_argument("wrong input");
				}
			}
			if (split_date[1].to_int() < 7 && split_date[1].to_int() % 2 == 0) {
				if (split_date[0].to_int() > 31) {
					throw std::invalid_argument("wrong input");
				}
			}
			if (split_date[1].to_int() >= 7 && split_date[1].to_int() % 2 != 0) {
				if (split_date[0].to_int() > 30) {
					throw std::invalid_argument("wrong input");
				}
			}
		}
	}

public:
	Event();
	Event(String _date, String sTime, String eTime, String _name, String _note);
	Event& operator=(const Event& other);

	bool operator==(const Event&);

	String getDate() const;
	String getStartTime() const;
	String getEndTime() const;
	String getName() const;
	String getNote() const;

	bool hasTime(int sTime, int eTime, int hours); //ckecks if there is enough time by given start time and end time

	friend std::ostream& operator<<(std::ostream& out, const Event& e);
	friend std::istream& operator>>(std::istream& in, Event& e); //da dopisha za name i note
};

