#include "Event.h"

Event::Event()
{
	
}

Event::Event(String _date, String sTime, String eTime, String _name, String _note)
{
	check_date(_date);
	check_time(sTime);
	check_time(eTime);

	if (sTime.to_int() > eTime.to_int()) {
		throw std::invalid_argument("wrong input");
	}

	date = _date;
	start_time = sTime;
	end_time = eTime;
	name = _name;
	note = _note;

}

Event& Event::operator=(const Event& other)
{
	date = other.date;
	start_time = other.start_time;
	end_time = other.end_time;
	name = other.name;
	note = other.note;

	return *this;
}

bool Event::operator==(const Event& other)
{
	return date == other.date && start_time == other.start_time &&
		end_time == other.end_time;
}

String Event::getDate() const
{
	return this->date;
}

String Event::getStartTime() const
{
	return this->start_time;
}

String Event::getEndTime() const
{
	return this->end_time;
}

String Event::getName() const
{
	return this->name;
}

String Event::getNote() const
{
	return this->note;
}

bool Event::hasTime(int sTime, int eTime, int hours)
{
	return hours <= eTime - sTime;
}

std::ostream& operator<<(std::ostream& out, const Event& e)
{
	out << e.date << " " << e.start_time << " " << e.end_time
		<< " " << e.name.count() << " " << e.name << " " << e.note.count()
		<< " " << e.note << "\n";

	return out;
}

std::istream& operator>>(std::istream& in, Event& e)
{
	in >> e.date >> e.start_time >> e.end_time;
	e.name = "";
	e.note = "";
	String s;
	int num;
	in >> num;
	for (int i = 0; i < num; i++) {
		in >> s;
		e.name = e.name + s;
		if (i != num - 1) e.name = e.name + " ";
	}
	in >> num;
	for (int i = 0; i < num; i++) {
		in >> s;
		e.note = e.note + s;
		if (i != num - 1) e.name = e.note + " ";
	}

	return in;
}
