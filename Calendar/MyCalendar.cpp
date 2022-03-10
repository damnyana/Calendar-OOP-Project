#include "MyCalendar.h"
#include <fstream>
#include <iostream>

void MyCalendar::startSystem()
{
	std::cout << "Welcome to your personal callendar!" << std::endl;
	char commandTxt[256];

	do
	{
		std::cout << "> ";

		std::cin.getline(commandTxt, 256);

		Vector<String> command = String(commandTxt).split(' ');

		if (strcmp(command[0].c_str(), "open") == 0) {
			open(command[1]);
		}
		else if (strcmp(command[0].c_str(), "close" )== 0) {
			close();
		}
		else if (strcmp(command[0].c_str(), "save") == 0) {
			save();
		}
		else if(strcmp(command[0].c_str(), "saveas") == 0){
			save_as(command[1]);
		}
		else if(strcmp(command[0].c_str(), "help") == 0)
		{
			help();
		}
		else if (strcmp(command[0].c_str(), "exit") == 0) {
			std::cout << "Bye! :)" << std::endl;
				break;
		}
		else if (strcmp(command[0].c_str(), "book") == 0)
		{
			Event ev;

				ev = Event(command[1], command[2], command[3], command[4], command[5]);
			currCal.book(ev);
		}
		else if (strcmp(command[0].c_str(), "unbook") == 0)
		{
			currCal.unbook(Event(command[1], command[2], command[3], "", ""));
		}
		else if (strcmp(command[0].c_str(), "agenda") == 0)
		{
			currCal.agenda(command[1]);
		}
		else if (strcmp(command[0].c_str(), "change") == 0)
		{
			Event ev(command[1], command[2], "23:59", "", "");
			currCal.change(ev, command[3], command[4]);
		}
		else if (strcmp(command[0].c_str(), "find") == 0)
		{
			currCal.find(command[1]);
		}
		else if (strcmp(command[0].c_str(), "holiday") == 0)
		{
			currCal.holiday(command[1]);
		}
		else if (strcmp(command[0].c_str(), "busydays") == 0)
		{
			currCal.busydays(command[1], command[2]);
		}
		else if (strcmp(command[0].c_str(), "findslot") == 0)
		{
			currCal.findslot(command[1], command[2].to_int());
		}
		else if (strcmp(command[0].c_str(), "findslotwith") == 0)
		{
			Vector<Calendar> calendars;

			for (size_t i = 3; i < command.getSize(); i++)
			{
				Calendar calendar;

				std::ifstream calendar_file;

				calendar_file.open(command[i].c_str());
				calendar_file >> calendar;
				calendar_file.close();
				calendars.push_back(calendar);
			}
			currCal.findslotwith(command[1], command[2].to_int(), calendars);
		}
		else if (strcmp(command[0].c_str(), "merge") == 0)
		{
			Vector<Calendar> calendars;
			for (int i = 1; i < command.getSize(); i++) {
				Calendar cal;
				std::ifstream cal_file;
				cal_file.open(command[i].c_str());
				cal_file >> cal;
				cal_file.close();
				calendars.push_back(cal);
			}
			currCal.merge(calendars);
		}
		else {
			std::cout << "Invalid command!" << std::endl;
		}
	}
	while (strcmp(commandTxt, "exit") != 0);
}

void MyCalendar::open(String file_name)
{
	std::cin >> currCal;
	std::ofstream file(file_name.c_str(), std::ios::out);
	file << currCal;

	if (file.fail()) {
		std::cout << "Error while opening this file" << std::endl;
		return;
	}
}

void MyCalendar::read()
{
	std::ifstream iFile(currentFile.c_str(), std::ios::in);

	if (iFile.fail()) {
		std::cout << "Error while opening this file" << std::endl;
		return;
	}
	Calendar buffer;
	iFile >> buffer;
	currCal = buffer;

}



void MyCalendar::close()
{
	std::cout << "Successfully closed " << currentFile << std::endl;
	currentFile = "";
	openedFile = false;
}

void MyCalendar::save()
{
	save_as(currentFile.c_str());
}

void MyCalendar::save_as(String file_name)
{

	std::cout << "Successfully saved " << file_name << "!" << std::endl;
	currentFile = "";
}

void MyCalendar::help()
{
	std::cout << "The following commands are supported :" << std::endl
		<< "open <file>		opens <file>" << std::endl
		<< "close			closes currently opened file" << std::endl
		<< "save			saves the currently open file" << std::endl
		<< "saveas <file>	saves the currently open file in <file>" << std::endl
		<< "help 			prints this information" << std::endl
		<< "exit			exit the programm" << std::endl;
	std::cout << "==============================================================================" << std::endl
		<< "book <date> <starttime> <endtime> <name> <note>		books an appointment" << std::endl
		<< "unbook <date> <starttime> <endtime>					unbooks an appointment" << std::endl
		<< "agenda <date>										shows all appointments for the day" << std::endl
		<< "change	<date> <starttime> <option> <newvalue>		gives the option a new value" << std::endl
		<< "                                                    <option> can be date, starttime, endtime, name or note" << std::endl
		<< "find <string>										finds all appointments with <string> as keyword" << std::endl
		<< "holiday	<date>										set the date as non-work day" << std::endl
		<< "busydays <from>	<to>								shows all busy days (from date to date)" << std::endl
		<< "finslot <fromdate> <hours>							finds a free time for an appointment by date and hours duration" << std::endl
		<< "findslotwith <fromdate> <hours> <calendar>			-------" << std::endl
		<< "merge <calendar>									merge the given <calendar> with yours" << std::endl;
}

void MyCalendar::exit()
{
	std::cout << "Bye! :)" << std::endl;
}
