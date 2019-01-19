#include "pch.h"
#include "Meterologic.h"

Meterologic::Meterologic() {}

void Meterologic::ShowMeterologic(string seasonChoice) 
{PrintMeterologic.printSeasonChange(outside, averageOutside, seasonChoice);};

Meterologic::~Meterologic() {}