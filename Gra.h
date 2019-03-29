#pragma once
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Wyspa.h"
#include "KomponentEkoSystemu.h" // nie konieczny
#include "Wilk.h"
#include "Dzik.h"
#include "Owca.h"
#include "Niedzwiedz.h"
#include "Wiewiorka.h"
#include "Trawa.h"
#include "Orzech.h"
#include "Marchewka.h"
#include <Windows.h>
class CGra
{
private:
	CWyspa* wyspa;
	std::vector<CKomponentEkoSystemu*> komponenty;
	//std::vector<CZwierze*> zwierzeta;
public:
	CGra();
	~CGra();



	void InicjalizacjaKomponentowLosowa();
	void InicjalizacjaKomponentuNaPolu(int _x, int _y, CKomponentEkoSystemu* _komponent);
	void InicjalizacjaKomponentuNaPolu(CPole* _pole, CKomponentEkoSystemu* _komponent);
	void DodajLosowaRosliny();
	void update();
	void StworzGreProbna();
	CKomponentEkoSystemu* DajKomponent(int _x, int _y); // zwraca pierwszy komponent na polu
	CKomponentEkoSystemu* StworzLosowyKomponent(int _x, int _y);
	CKomponentEkoSystemu* StworzLosoweZwierze(int _x, int _y);
	CKomponentEkoSystemu* StworzOwce(int _x, int _y);
	CKomponentEkoSystemu* StworzWiewiorke(int _x, int _y);
	CKomponentEkoSystemu* StworzDzika(int _x, int _y);
	CKomponentEkoSystemu* StworzNiedzwiedzia(int _x, int _y);
	CKomponentEkoSystemu* StworzWilka(int _x, int _y);
	//CKomponentEkoSystemu* StworzWilkaRozmnazanie(int _x, int _y);
	CKomponentEkoSystemu* StworzLosowaRosline(int _x, int _y);
	void StworzWilkaRozmnazanie(CPole* _pole);
	void StworzWiewiorkeRozmnazanie(CPole* _pole);
	void StworzDzikaRozmnazanie(CPole* _pole);
	void StworzOwceRozmnazanie(CPole* _pole);
	void StworzNiedzwiedziaRozmnazanie(CPole* _pole);
	CGra* DajGre();
	void UsunMartweKomponentyZGry();
	//	bool SprawdzCzyTrawa(CKomponentEkoSystemu* _komponent);// czy na danym polu znajduje sie trawa
	//void WyswietlKomponenty(); // wyswietla wszystkie stworzone komponenty w liscie, bez pol na jakich sie znajduja
	CWyspa* ZwrocWyspe();
	void Update(); //wyswietlanie wszystkiego na koniec kolejki
	void Inicjalizacja();
	void KoniecRundyOdswiezanie();
	void OdswiezWektor();
	void UpdateWyswietl(); //wyswietla po interakcji kazdego komponentu
	void UpdateBezTabeli();
};