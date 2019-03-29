#pragma once
#include "Pole.h"
#include <vector>
#include <iostream>
class CWyspa
{
private:
	int szerokosc;
	int wysokosc;
	std::vector<std::vector<CPole*>> pola;
public:
	CWyspa();
	CWyspa(int _x, int _y);
	~CWyspa();

	void WyswietlWyspe_Wspolrzedne();
	int DajSzerokosc();
	int DajWysokosc();
	std::vector<std::vector<CPole*>> Pola();
	void WyswietlWyspe_Komponenty();
	void WyswietlWyspe_Tablica();
	bool CzyPoleJestNaWyspie(int _x, int _y); //do napisania
	CPole* DajPole(int _x, int _y); // jesli dane poleistnieje zwraca wskaznik do niego jesli nie to zwraca nullptr
	void UsunMarteKomponentyZWyspy();
	bool CZyPoleJestNaWyspieIMoznaNaNieWejsc(int _x, int _y);

};

