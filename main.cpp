#include "pch.h"
#include "Data.h"
#include "Allinfo.h"
#include "showOneDay.h"
#include "Meterologic.h"
//TODO: move search to seperate class
//TODO: make a switch funciton
//TODO: make the start application function in main
//TODO: make a new cpp and header file for the Inside and Outside search function from application.cpp


void HumidityMergeSort
(avgDaily** mid, int FromLeft, int FromLeftHigh, int FromRightHigh)
{
	int size = FromRightHigh - FromLeft + 1;
	avgDaily** temp = new avgDaily*[size];
	int fromRight = FromLeftHigh + 1;
	int LeftSide = FromLeft;
	int RightSide = fromRight;

	int i = 0;
	

	while (LeftSide <= FromLeftHigh && RightSide <= FromRightHigh)
	{
		if (mid[LeftSide]->get_HumidityValue() < mid[RightSide]->get_HumidityValue())
		{
			temp[i] = mid[LeftSide];
			LeftSide++;
			i++;
		}
		else
		{
			temp[i] = mid[RightSide];
			RightSide++;
			i++;
		}
	}

	while (LeftSide <= FromLeftHigh)
	{
		temp[i] = mid[LeftSide];
		LeftSide++;
		i++;
	}
	while (RightSide <= FromRightHigh)
	{
		temp[i] = mid[RightSide];
		RightSide++;
		i++;
	}

	for (int j = FromLeft; j <= FromRightHigh; j++)
	{
		mid[j] = temp[j - FromLeft];
	}
}

void SortHumidityValue
(avgDaily** medium, int low, int high)
{
	int middleValue;
	if (low < high)
	{
		middleValue = (high + low) / 2;

		SortHumidityValue(medium, low, middleValue);

		SortHumidityValue(medium, middleValue + 1, high);

		HumidityMergeSort(medium, low, middleValue, high);
	}
}

int main()
{
	Data data;
	avgDaily** SortingArray;
	vector<Data*> inside;
	vector<Data*> outside;

	vector<avgDaily*> averageInside;
	vector<avgDaily*> averageOutside;
	bool running = true;
	int choice;
	do
	{
		cout << "====Main Menu====" << endl;
		cout << "[1] Show ALL" << endl;
		cout << "[2]: Meterologic Autumn/Winter" << endl;
		cout << "[3]: Search a specific date" << endl;
		cout << "[4]: Sort Humidity" << endl;

		cout << "[9]: Exit\n" << endl;
		cin >> choice;
		switch (choice)
		{
			case 1:
			{
				cout << "You have chosen option 1. You will now be presented all the average values from the file..." << endl;
				Allinfo run;
				run.showAllInfo();
				break;
			}
			case 2:
			{
				string choice;
				cout << "Would you like to see the date of 'Autumn' or 'Winter'?" << endl;
				cin >> choice;
				Meterologic run;
				run.ShowMeterologic(choice);
				break;
				
			}
			case 3:
			{
				long Date;
				cout << "You have chosen option 2." << endl;
				cout << "Please enter date, yyyymmdd" << endl;
				cin >> Date;
				while (!(cin >> Date)) {
					cout << "You must enter a valid Date 'yyymmdd'" << endl;
					cin.clear();
					cin.ignore(100, '\n');
				}OneDay run;
				run.ShowOneDay(Date);
				break;
				
			}
			case 4:		
			{
				SortingArray = new avgDaily*[averageInside.size()];
				for (int i = 0; i < averageInside.size(); i++)
				{
					SortingArray[i] = averageInside[i];
				}
				SortHumidityValue(SortingArray, 0, averageInside.size() - 1);
				for (int i = 0; i < averageInside.size(); i++)
				{
					SortingArray[i]->printSortAlgorithm();
				}
				break;
			}
			case 9:
			{
				cout << "Would you like to quit? \n Enter a number " << endl;
				cin >> choice;
				while (!(cin >> choice)) {
					cout << "You must enter a number" << endl;
					cin.clear();
					cin.ignore(100, '\n');
				}running = false;
			}
		}
	} while (running);
}
