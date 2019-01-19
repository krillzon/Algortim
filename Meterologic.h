#pragma once
#include "Data.h"


class Meterologic
{
private:

	vector<Data*> inside;
	vector<Data*> outside;

	vector<avgDaily*> averageInside;
	vector<avgDaily*> averageOutside;

	Data PrintMeterologic;

public:
	Meterologic();
	void ShowMeterologic(string choice);




	~Meterologic();
};

