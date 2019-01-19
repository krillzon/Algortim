#pragma once
#include "pch.h"
#include "Data.h"


class Allinfo
{
private:

	vector<Data*> inside;
	vector<Data*> outside;

	vector<avgDaily*> averageInside;
	vector<avgDaily*> averageOutside;

	Data Print;

public:
	Allinfo();
	void showAllInfo();




	~Allinfo();
};

