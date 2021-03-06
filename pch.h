
#ifndef PCH_H
#define PCH_H

#include <iostream>
#include <Windows.h>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
using namespace std;

// TODO: add headers that you want to pre-compile here
#endif //PCH_H



//SÖKFUNKTION
//Använde mig av linjär sökning på alla sökfunktioner. Den är inte mest effektiv,
//men den är lätt att skriva. Det värsta fallet med linjär sökning är komplexiteten O(n)
//Tidskoplexiteten är inte speciellt bra med linjär sökning.
//Det sämsta fallet förekommer i den linjära sökalgoritmen när objektet är det sista elementet i matrisen eller inte alls finns.
//Binär sökning är bättre då den hoppar till mitten och sen utgår därifrån.

//DATATYPER
//Jag använde enbart primitiva datatyper.

//SORERINGSFUNKTION


//METEROLOGISKA REGLER FÖR VINTER OCH HÖST
//För att en meterologisk "Seasonchange" ska inträffa för Höst så måste
//temperaturen vara under 10 grader fem dagar i rad. Det inträffade i vår data.

//För att en meterologisk "Seasonchange" ska inträffa för Vintern så måste
//temperaturen vara under 0 grader 5 dagar i rad. Det inträffade Ej i vår data.

//DATAANALYS
//Jag analyserade datan när jag skulle se ifall det fanns en meterologisk vinter eller höst
// i den datan som vi fick, för att lättare kunna dra slutsatser.




//void merge(avgDaily** mergearray, int low, int middle, int high, sortvalue SortType)
//{
//	int fromLeft = low;
//	int fromRight = middle + 1;
//
//	int ti = 0;
//
//	avgDaily** temp = new avgDaily*[high - low + 1];
//
//	while (fromLeft <= middle && fromRight <= high)
//	{
//		if (mergearray[fromLeft]->compare(mergearray[fromRight], SortType ))
//		{
//			temp[ti] = mergearray[fromLeft];
//			fromLeft++;
//			ti++;
//		}
//		else {
//			temp[ti] = mergearray[fromRight];
//			
//			fromRight++;
//			ti++;
//		}
//	}
//	while (fromRight <= high)
//	{
//		temp[ti] = mergearray[fromRight];
//
//		fromRight++;
//		ti++;
//	}
//
//	while (fromLeft <= middle)
//	{
//		temp[ti] = mergearray[fromLeft];
//		fromLeft++;
//		ti++;
//	}
//
//	for (int i = low; i <= high; i++)
//	{
//		mergearray[i] = temp[i - low];
//	}
//
//}
//	
//
//void mergesort(avgDaily** mergearray, int low, int high, sortvalue SortType)
//{
//	
//	if (low < high) {
//		int middle = (high - low) / 2;
//		
//		mergesort(mergearray, low, middle, SortType);
//		mergesort(mergearray, middle + 1, high, SortType);
//
//		merge(mergearray, low, middle, high, SortType);
//
//	}
//}

