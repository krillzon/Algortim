#pragma once
#pragma once
#include "pch.h"


class avgDaily
{
private:

	float AverageTemp;
	long int AvgDate;
	int AverageHumidity;
	float AverageMold;

	string dateYear;
	string dateMonth;
	string dateDay;
	string place;
	string temp;
	string moist;
	string Hours, Minutes, Seconds;

public:

	void printSortAlgorithm();

	avgDaily(long int date, float temp, int humidity): AvgDate(date), AverageTemp(temp), AverageHumidity(humidity) {};

	void moldCount(float a)
	{this->AverageMold = a;}

	float get_TempValue()
	{return this->AverageTemp;}

	int get_HumidityValue()
	{return this->AverageTemp;}

	long int get_DateValue()
	{return this->AvgDate;}

	float get_MoldriskValue()
	{return this->AverageMold;}
	
	// If avdcou.cpp is removed, you cant make a destructor
	~avgDaily();

};


class Data
{
private:

	//std::string date, time, place, temp, moist;
	long int Date;
	float Temp;
	int Humidity;
	bool Place;


public:
	Data();

	bool b_place;
	string dateYear;
	string dateMonth;
	string dateDay;
	string place;
	string temp;
	string moist;
	string Hours, Minutes, Seconds;
	//Functions
	void printOutAllValues(vector <avgDaily *> &, string InOut);
	void printOutSingle(vector <avgDaily *> &, string InOut, long Date);
	void PrintOutSeasonChange(vector <avgDaily *> &, string seasonChange);
	int riskOfMold(int temp, int Humidity);
	void AverageCount(vector <Data *> &, vector <avgDaily *> &);


	void PrintAll(vector <Data *> &, vector <Data *> &, vector <avgDaily *> &, vector <avgDaily *> &);
	
	//void printOutChange(vector <avgDaily *> &, string seasonChange);
	void PrintSingleDay(vector <Data *> &, vector <Data *> &, vector <avgDaily *> &, vector <avgDaily *> &, long Date);
	void printSeasonChange(vector <Data *> &, vector <avgDaily *> &, string seasonChange);
	

	long get_Date()
	{return this->Date;}

	bool get_Place()
	{return this->Place;}

	float get_Temp()
	{return this->Temp;}
	
	int get_Humidity()
	{return this->Humidity;}
	//konstruktor för data
	Data(long date, long int time, bool place, float temp, int Humidity): Date(date), Place(place), Temp(temp), Humidity(Humidity) {};


	~Data();
};


