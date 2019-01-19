#pragma once
#include "Data.h"


class OneDay
{
private:

	vector<Data*> inside;
	vector<Data*> outside;

	vector<avgDaily*> averageInside;
	vector<avgDaily*> averageOutside;

	Data PrintOneDay;

public:
	OneDay();
	void ShowOneDay(long choice);




	~OneDay();
};
