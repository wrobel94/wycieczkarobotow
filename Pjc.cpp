// PJC.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include "stdafx.h"
#include "Gra.h"
#include <cstdlib>

int main()
{
	srand(time_t(NULL));
	CGra gra;
	gra.StworzGreProbna();
	gra.InicjalizacjaKomponentowLosowa(); //stawia randomowe rosliny -- mozna zmieniac
	gra.Inicjalizacja();
	for (int i = 0; i < 200; i++)
	{
		gra.UpdateWyswietl();
	}
	return 0;
}

