#pragma once
#include "Pole.h" //
//#include "Gra.h" //
//#include "Wyspa.h"
#include <string>
class CPole;
class CWyspa;
class CGra;
class CKomponentEkoSystemu
{
protected:
	std::string nazwa;
	std::string inicialy;
	CPole* aktualnapozycja;
	CPole* poprzedniapozycja;
	CWyspa* wyspanaktorejjestem;
	CGra* gra;
	bool martwy;
public:
	CKomponentEkoSystemu();
	CKomponentEkoSystemu(CPole* _ustawianapozycja, CWyspa* _ustawianawyspa);
	virtual ~CKomponentEkoSystemu();

	void UstawMartwy();
	bool CzyKomponentJestMartwy();
	void UstawPozycje(CPole* _ustawianepole); // zamien na konstruktor ??
	void DajPozycje();
	CPole* DajPole();
	CPole* DajPoprzedniaPozycje();
	CGra* DajGre();
	std::string DajNazwe();
	CWyspa* DajWyspe();
	virtual void WyswietlKomponent() = 0;
	virtual void WyswietlKomponent_Tablica() = 0;
	void virtual Zyj() = 0; 
	void virtual Inicjalizacja();
	void virtual KoniecRundyOdswiezanie();
	void virtual WyswietlTluszcz();
};

