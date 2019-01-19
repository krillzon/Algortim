#include "pch.h"
#include "Data.h"



Data::Data(){}

// För PrintAll funktionen
void Data::printOutAllValues
(vector <avgDaily *> &printValuesVector, string InOut)
{
	for (int i = 0; i < printValuesVector.size(); i++)
	{
	
		cout << "==================================================================================" << endl;
		cout << "Current position: " << InOut;
		cout << endl;
		cout << "Date: ";
		cout << printValuesVector[i]->get_DateValue() << " - ";
		cout << "Average Temp: ";
		cout << printValuesVector[i]->get_TempValue() << " - ";
		cout << "Average Humidity: ";
		cout << (printValuesVector[i]->get_HumidityValue()) << " - ";
		if (printValuesVector[i]->get_MoldriskValue() > 0) {
			cout << "Moldrisk: " << "(";
			cout << printValuesVector[i]->get_MoldriskValue() << " Moldindex" << ")";
		}
		else {
			cout << "Moldrisk: 0%";
		}
		cout << endl;
	}
}

//För search date funktionen
void Data::printOutSingle(vector <avgDaily *> &printValuesVector, string InOut, long Date)
{

	for (int i = 0; i < printValuesVector.size(); i++)
	{
		if (Date == printValuesVector[i]->get_DateValue())
		{
			cout << "==================================================================================" << endl;
			cout << "Current position: " << InOut;
			cout << endl;
			cout << "Date: ";
			cout << printValuesVector[i]->get_DateValue() << " - ";
			cout << "Average Temp: ";
			cout << printValuesVector[i]->get_TempValue() << " - ";
			cout << "Average Humidity: ";
			cout << (printValuesVector[i]->get_HumidityValue()) << " - ";
			if (printValuesVector[i]->get_MoldriskValue() > 0) {
				cout << "Moldrisk: " << "(";
				cout << printValuesVector[i]->get_MoldriskValue() << " Moldindex" << ")";
			}
			else {
				cout << "Moldrisk: 0%";
			}
			cout << endl;
		}
	}
}

//Print out Meterologic Autumn/Winter
void Data::PrintOutSeasonChange(vector <avgDaily *> &printValuesVector, string seasonChange)
{
	long int NumbersOfDayInRow = 0;
	long int SeasonChangeDate;
	float SeasonChangeTemp;

	if (seasonChange == "Autumn")
	{
		SeasonChangeTemp = 10.f;
	}
	else if (seasonChange == "Winter")
	{
		SeasonChangeTemp = 0;
	}

	for (int i = 0; i < printValuesVector.size(); i++)
	{
		if (printValuesVector[i]->get_TempValue() <= SeasonChangeTemp)
		{
			if (NumbersOfDayInRow == 0)
			{
				SeasonChangeDate = printValuesVector[i]->get_DateValue();

			}
			NumbersOfDayInRow++;
			if (NumbersOfDayInRow == 5)
			{
				cout << "The first date of the Meterologic " << seasonChange << " is " <<"'" << SeasonChangeDate << "'" << endl;
				break;
			}
		}
		else {
			NumbersOfDayInRow = 0;
			SeasonChangeDate = 0;
		}
	}
	if (NumbersOfDayInRow != 5)
	{
		cout << "No Meterologic " << seasonChange << " found" << endl;
	}
}
//Risk för mold, tagen från länk
int Data::riskOfMold
(int Tempeture, int humidity)
{int y = (humidity-(-0.0015*pow(Tempeture, 3)+0.1193*pow(Tempeture, 2)-2.9878*Tempeture+102.96));
return (int)	y;};


// Räkning av genomsnittliga värdena av Temp och Humidity
void Data::AverageCount
(vector <Data *> &vector, std::vector <avgDaily *> &vectorIncludingAverageValue)
{
	long getDateTemp;
	float AverageTempeture;
	int AverageHumidity;
	int div = 0;
	getDateTemp = vector[0]->get_Date();
	AverageTempeture = vector[0]->get_Temp();
	AverageHumidity = vector[0]->get_Humidity(); div++;
	for (int i = 1; i < vector.size(); i++)
	{if (vector[i - 1]->get_Date() == vector[i]->get_Date())
		{AverageTempeture = AverageTempeture + vector[i]->get_Temp();
		AverageHumidity = AverageHumidity + vector[i]->get_Humidity(); div++;}
	else {AverageTempeture = AverageTempeture / div; AverageHumidity = AverageHumidity / div; vectorIncludingAverageValue.push_back(new avgDaily(getDateTemp, AverageTempeture, AverageHumidity)); div = 0;
	getDateTemp = vector[i]->get_Date(); AverageTempeture = vector[i]->get_Temp(); AverageHumidity = vector[i]->get_Humidity(); div++;}}

	AverageTempeture = AverageTempeture / div; AverageHumidity = AverageHumidity / div;
	vectorIncludingAverageValue.push_back(new avgDaily(getDateTemp, AverageTempeture, AverageHumidity));
}

//Print Function
void Data::PrintAll
(vector <Data *> &insideVector, vector <Data *> &outsideVector,
	vector <avgDaily *> &avgDailyInsideVector, vector <avgDaily *> &avgDailyOutsideVector)
{
	fstream textfile("tempdata4.csv");
	if (!textfile.is_open())
	{
		cout << "Could not open file." << endl;
	}
	else {
		while (!textfile.eof()) {
			getline(textfile, dateYear, '-');
			getline(textfile, dateMonth, '-');
			getline(textfile, dateDay, ' ');
			dateYear.append(dateMonth);
			dateYear.append(dateDay);

			getline(textfile, Hours, ':');
			getline(textfile, Minutes, ':');
			getline(textfile, Seconds, ',');
			Hours.append(Minutes);
			Hours.append(Seconds);

			getline(textfile, place, ',');
			getline(textfile, temp, ',');
			getline(textfile, moist);

			
			//Läser av stringen "place" om den matchar med filens namn "Inne"
			if (b_place =(place == "Inne"))
			{insideVector.push_back(new Data(stol(dateYear), stol(Hours), b_place, stof(temp), stoi(moist)));}
			else
			{outsideVector.push_back(new Data(stol(dateYear), stol(Hours), b_place, stof(temp), stoi(moist)));}

		}
		//Average counting
		AverageCount(insideVector, avgDailyInsideVector);
		AverageCount(outsideVector, avgDailyOutsideVector);
		for (int i = 0; i < avgDailyInsideVector.size(); i++) { avgDailyInsideVector[i]->moldCount(riskOfMold(avgDailyInsideVector[i]->get_TempValue(), avgDailyInsideVector[i]->get_HumidityValue())); }
		for (int i = 0; i < avgDailyOutsideVector.size(); i++) { avgDailyOutsideVector[i]->moldCount(riskOfMold(avgDailyOutsideVector[i]->get_TempValue(), avgDailyOutsideVector[i]->get_HumidityValue())); }
		
		//Printar ute eller inne i show all [1]
		string In = "Inne";
		string Out = "Ute";

		printOutAllValues(avgDailyInsideVector, In);
		printOutAllValues(avgDailyOutsideVector, Out);
	}

}
//Search day function
void Data::PrintSingleDay
(vector <Data *> &insideVector, vector <Data *> &outsideVector,
	vector <avgDaily *> &avgDailyInsideVector, vector <avgDaily *> &avgDailyOutsideVector, long Date)
{
	fstream textfile("tempdata4.csv");
	bool b_place;

	if (!textfile.is_open())
	{
		cout << "Could not open file." << endl;
	}
	else {
		while (!textfile.eof()) {
			getline(textfile, dateYear, '-');
			getline(textfile, dateMonth, '-');
			getline(textfile, dateDay, ' ');
			dateYear.append(dateMonth);
			dateYear.append(dateDay);

			getline(textfile, Hours, ':');
			getline(textfile, Minutes, ':');
			getline(textfile, Seconds, ',');
			Hours.append(Minutes);
			Hours.append(Seconds);

			getline(textfile, place, ',');
			getline(textfile, temp, ',');
			getline(textfile, moist);

			//Ändra till Ute eller Inne, använda till sökfunktion????

			if (b_place = (place == "Inne"))
			{
				insideVector.push_back(new Data(stol(dateYear), stol(Hours), b_place, stof(temp), stoi(moist)));
			}
			else
			{
				outsideVector.push_back(new Data(stol(dateYear), stol(Hours), b_place, stof(temp), stoi(moist)));
			}

		}
		AverageCount(insideVector, avgDailyInsideVector);
		AverageCount(outsideVector, avgDailyOutsideVector);
		for (int i = 0; i < avgDailyInsideVector.size(); i++) { avgDailyInsideVector[i]->moldCount(riskOfMold(avgDailyInsideVector[i]->get_TempValue(), avgDailyInsideVector[i]->get_HumidityValue())); }
		for (int i = 0; i < avgDailyOutsideVector.size(); i++) { avgDailyOutsideVector[i]->moldCount(riskOfMold(avgDailyOutsideVector[i]->get_TempValue(), avgDailyOutsideVector[i]->get_HumidityValue())); }

		string In = "Inne";
		string Out = "Ute";

		printOutSingle(avgDailyInsideVector, In, Date);
		printOutSingle(avgDailyOutsideVector, Out, Date);
	}

}

//Meterologic season change
void Data::printSeasonChange
(vector <Data *> &outsideVector, vector <avgDaily *> &avgDailyOutsideVector, string seasonChange)
{

	fstream textfile("tempdata4.csv");
	bool b_place;

	if (!textfile.is_open())
	{
		cout << "Could not open file." << endl;
	}
	else {
		while (!textfile.eof()) {
			getline(textfile, dateYear, '-');
			getline(textfile, dateMonth, '-');
			getline(textfile, dateDay, ' ');
			dateYear.append(dateMonth);
			dateYear.append(dateDay);

			getline(textfile, Hours, ':');
			getline(textfile, Minutes, ':');
			getline(textfile, Seconds, ',');
			Hours.append(Minutes);
			Hours.append(Seconds);

			getline(textfile, place, ',');
			getline(textfile, temp, ',');
			getline(textfile, moist);


			if (b_place = (place == "Inne")){}
			else
			{
				outsideVector.push_back(new Data(stol(dateYear), stol(Hours), b_place, stof(temp), stoi(moist)));
			}

		}
		
		AverageCount(outsideVector, avgDailyOutsideVector);
		for (int i = 0; i < avgDailyOutsideVector.size(); i++) { avgDailyOutsideVector[i]->moldCount(riskOfMold(avgDailyOutsideVector[i]->get_TempValue(), avgDailyOutsideVector[i]->get_HumidityValue())); }
		string In = "Inne";
		string Out = "Ute";
		PrintOutSeasonChange(avgDailyOutsideVector, seasonChange);

	}

}


void avgDaily::printSortAlgorithm()
{
	printSortAlgorithm();
	cout << "Temperature:" << this->AverageTemp << endl;
	cout << "Humidity, " << this->AverageHumidity << "%" << endl;
}


Data::~Data() {}

























































































































/*
Villes




void Data::infromfile(std::vector <Data *> &inBaseVector, std::vector <Data *> &outBaseVector,
	std::vector <Dailyaverage *> &inAveVector, std::vector <Dailyaverage *> &outAveVector)
{
string s_year, s_month, s_day, s_time, s_room, s_temp, s_moist;
ifstream textfile("tempdata2.csv"); //ifstream::binary);
//bool texteof = false;
bool b_room;
bool running = true;
if (textfile.is_open())
{
	while (!textfile.eof())
	{
		getline(textfile, s_year, '-');
		getline(textfile, s_month, '-');
		getline(textfile, s_day, ' ');
		getline(textfile, s_time, ';');
		getline(textfile, s_room, ';');
		getline(textfile, s_temp, ';');
		getline(textfile, s_moist);
		b_room = (s_room == "Inside");

		inBaseVector.push_back(new Data(stoi(s_year), stoi(s_month), stoi(s_day), s_time, b_room, stoi(s_moist), stof(s_temp)));
	}
}
else
{
	cout << "43234324." << endl;
}

cout << "--------inside---------" << endl;

for (int i = 0; i < inBaseVector.size(); i++)
{
	if (inBaseVector[i]->get_room() == true)
	{
		inBaseVector[i]->print();
	}

}
cout << "----------Outside-----------" << endl;

for (int i = 0; i < content.size(); i++)
{
	if (content[i]->get_room() == false)
	{
		content[i]->print();
	}
};
}
*/