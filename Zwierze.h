#pragma once
#include "Ruchome.h"
#include "Wyspa.h" 
#include "Roslina.h"
#include <cmath>
#include <algorithm>
#include <iostream>

class CZwierze :
	public CRuchome
{
protected:
	int zycie;
	int max_zycie;
	int tluszcz;
	int max_tluszcz;
	int wspolczynnikzmniejszeniazycia;
	int zakreswidzenia;
	int masa;
	int czaspogonizacelrozmnazanie;
	int maksymalnyczaspogonizacelrozmnazanie;
	int wspolczynnikspalaniatluszczuprzyruchu;
	int wspolczynnikspalaniatluszczuprzyrozmnazaniu;
	int wspolczynnikplodnosci; // jaka jest szansa na to ze !!!jezeli dojdzie do stosunku pojawia sie dzieci -> 1 => 100%, 2=> 50%, 5 => 20%
	std::vector<CPole*> polewidzenia; //wszystkie pola ktore widze
	std::vector<CKomponentEkoSystemu*> widzianekomponenty;  //wszystko co widze w "polu widzenia"
	std::vector<CZwierze*> zwierzetawpoluwidzenia;
	std::vector<CRoslina*> roslinywpoluwidzenia;
	CZwierze* celrozmananie; //zwierze do ktorego chce isc inne aby sie rozmnozyc
public:
	CZwierze();
	CZwierze(CPole* _ustawianapozycja, CWyspa* _ustawianawyspa);
	~CZwierze();

	void UciekajPrzed(CZwierze* _atakujacy); // zwierze ucieka przed wrogiem nie koniecznie musi on atakowac
	int DajWspolczynnikPlodnosci();
	int DajZakresWidzenia();
	int DajZycie();
	void ZmniejszZycie(int _wspolczynnik);
	int DajMax_Tluszcz();
	int DajWspoczynnikZmniejszeniaZycia();
	void ResetujZycie();
	int DajTluszcz(); // funkcja zwraca aktualna wartosc tluszczu 
	void WyswietlKomponent(); // Wyswietla nazwe, zycie i tluszcz
	void WyswietlKomponent_Tablica(); //Wyswietla inicia³y komponentu
	void OdswiezPoleWidzenia(); //odswieza polewidzenia - wpisuje do wektora pola w zasiegu 
	void WyswietlPoleWidzenia(); //wyswietla co jest na polach ktore widze, niekoniecznie to samo widzi zwierze
	void WyswietlKomponentyKtoreWidzisz(); //wyswietla widziane komponenty
	void WyswietlTluszcz(); // wyswietla aktualna wartosc tluszczu
	void UstawCelRozmnazanie(); // przeszukuje wektor zwierzeta w polu widzenia i ustala celrozmnazanie
	void OdswiezCelRozmnazanie(); // odswieza cel rozmnazania jesli zwierze jest martwe ustawia na nullptr - sprawdza czy cel jest martwy jesli jest to nullptr
	CKomponentEkoSystemu* DajCelRozmnazanie(); // zwraca celrozmnazanie
	int DajMase(); // zwraca mase
	void WyznaczKomponentyKtoreWidzisz(); // przeszukuje pole widzenia i wrzuca wszystko do widzianychkomponentow, zwierzat i roslin
	int Odleglosc(CKomponentEkoSystemu* _komponent); // oblicza i zawraca odleglosc od komponentu
	int Odleglosc(CZwierze* _zwierze); // oblicza i zawraca odleglosc od zwierzaka
	int Odleglosc(CPole* _pole); // oblicza i zawraca odleglosc od zwierzaka
	virtual void Zyj() = 0;
	virtual void KoniecRundyOdswiez();
	void DodajTluszcz(int _tluszcz); // bylo wirtual
	void ZmniejszCzasPogoniZaCelRozmnazanie(); // zmniejsza czas pogoni za celrozmnazanie - jeden ruch odejmuje jeden
	void ResetujCzasPogoniZaCelRozmnazanie(); //resetuje czas pogoni za celrozmnazanie - przywraca wartosc domyslna
	int DajCzasPogoniZaCelRozmnazanie(); // zwraca wartosc czasu pogoni - wartosc poczatkowa (domyslna) odjac czas pogoni po kazdym ruchu
	void WyswietlCelRozmnazanie(); // wyswietla cel rozmnazanie
	void UsunCelRozmnaznie(); // ustawia cel rozmnazanie na nullptr
	void UstawTluszcz(int tluszcz); // ustawia tluszcz na zadana wartosc w zakresie od 0 do max_tluszcz
	int DajWspolczynnikSpalaniaTluszczuPrzyRozmnazaniu(); // zwraca wspolczynnik
	void ZmniejszTluszczRuch(); // zmniejsza tluszcz o wspolczynnik tluszczu przy ruchu
	int DajWspolczynnikSpalaniaTluszczuPrzyRuchu(); // zwraca wspolczynnik
	void ZmniejszTluszczRozmanzanie(); // zmniejsza tluszcz o wspolczynnik tluszczu przy rozmnazaniu
};

