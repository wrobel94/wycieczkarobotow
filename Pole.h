#pragma once
#include "KomponentEkoSystemu.h"
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
class CWyspa;
class CKomponentEkoSystemu;
class CPole
{
private:
	int x;
	int y;
	int maksymalnapojemnoscpola;
	std::vector<CKomponentEkoSystemu*> komponentynapolu;
	CWyspa* wyspa;
public:
	CPole();
	CPole(int _x, int _y, CWyspa* _wyspa);
	~CPole();

	void WyswietlWspolrzedne();
	void DodajKomponentDoPola(CKomponentEkoSystemu* _wskaznikdokomponentu); //Komponent jako argunemnt ?
	int IloscKomponentowNaPolu();
	void WyswietlKomponentyNaPolu();
	void WyswietlKomponentyNaPolu_Tablica();
	CPole* DajPole();
	bool CzyMoznaWejscNaPole(CPole* _pole);
	int OdlegloscOdPola(CPole* _pole1, CPole* _pole2);
	CWyspa* DajWyspe();
	std::vector<CKomponentEkoSystemu*> DajKomponentyNaPolu();
	void UsunKomponentZPola(CKomponentEkoSystemu* _komponent); // usuwa komponent z komponentynapolu
	void UsunKomponentZGry(CKomponentEkoSystemu* _komponent);
	void UsunMartweKomponentyZPola();
	void DodajKomponentNaPole(CKomponentEkoSystemu* _komponent); // dodaje komponent do komponentynapolu --DZIADOWO BEZ SPRAWDZANIA
	int DajX();
	int DajY();

};

