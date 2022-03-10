#pragma once
#include "String.h"
#include "Vector.h"
#include "Event.h"
#include "Calendar.h"

class MyCalendar
{
private:
	Calendar currCal;
	bool openedFile;
	String currentFile;

public:
	void startSystem();
	void open(String file_name);
	void read();
	void close();
	void save();
	void save_as(String file_name);
	void help();
	void exit();
};