#include "stdafx.h"
#include "Gra.h"


CGra::CGra()
{
	wyspa = new CWyspa(10, 15);
}


CGra::~CGra()
{
	delete wyspa;
	std::cout << "Destruktor CGra" << std::endl;
}


void CGra::StworzGreProbna()
{
	wyspa->Pola()[0][0]->DodajKomponentDoPola(StworzWilka(0, 0));
	wyspa->Pola()[2][2]->DodajKomponentDoPola(StworzWilka(2, 2));
	wyspa->Pola()[1][0]->DodajKomponentDoPola(StworzWilka(1, 0));
	wyspa->Pola()[3][2]->DodajKomponentDoPola(StworzWilka(3, 2));
	wyspa->Pola()[0][9]->DodajKomponentDoPola(StworzWilka(0, 9));
	wyspa->Pola()[4][9]->DodajKomponentDoPola(StworzWilka(4, 9));
	wyspa->Pola()[12][0]->DodajKomponentDoPola(StworzNiedzwiedzia(12, 0));
	wyspa->Pola()[14][3]->DodajKomponentDoPola(StworzNiedzwiedzia(14, 3));
	wyspa->Pola()[8][2]->DodajKomponentDoPola(StworzNiedzwiedzia(8, 2));
	wyspa->Pola()[5][5]->DodajKomponentDoPola(StworzWiewiorke(5, 5));
	wyspa->Pola()[8][6]->DodajKomponentDoPola(StworzWiewiorke(8, 6));
	wyspa->Pola()[1][3]->DodajKomponentDoPola(StworzWiewiorke(1, 3));
	wyspa->Pola()[1][8]->DodajKomponentDoPola(StworzWiewiorke(1, 8));
	wyspa->Pola()[1][2]->DodajKomponentDoPola(StworzWiewiorke(1, 2));
	wyspa->Pola()[7][0]->DodajKomponentDoPola(StworzOwce(7, 0));
	wyspa->Pola()[8][0]->DodajKomponentDoPola(StworzOwce(8, 0));
	wyspa->Pola()[7][3]->DodajKomponentDoPola(StworzOwce(7, 3));
	wyspa->Pola()[3][8]->DodajKomponentDoPola(StworzOwce(3, 8));
	wyspa->Pola()[9][2]->DodajKomponentDoPola(StworzOwce(9, 2));
	wyspa->Pola()[3][4]->DodajKomponentDoPola(StworzDzika(3, 4));
	wyspa->Pola()[4][3]->DodajKomponentDoPola(StworzDzika(4, 3));
	wyspa->Pola()[10][2]->DodajKomponentDoPola(StworzDzika(10, 2));
	wyspa->Pola()[8][2]->DodajKomponentDoPola(StworzDzika(8, 2));
	wyspa->Pola()[14][8]->DodajKomponentDoPola(StworzNiedzwiedzia(14, 8));
	wyspa->Pola()[12][9]->DodajKomponentDoPola(StworzNiedzwiedzia(12, 9));
}

void CGra::InicjalizacjaKomponentowLosowa()
{
	int wylosowanaliczba;
	for (int i = 0; i < wyspa->DajWysokosc(); i++)
	{
		for (int j = 0; j < wyspa->DajSzerokosc(); j++)
		{
			wylosowanaliczba = (std::rand() % 5);
			if (wylosowanaliczba == 0)
			{
				if (wyspa->Pola()[i][j]->IloscKomponentowNaPolu() == 0)
				{
					wyspa->Pola()[i][j]->DodajKomponentDoPola(StworzLosowyKomponent(i, j));
				}
			}
		}
	}
}

void CGra::DodajLosowaRosliny()
{
	int wylosowanaliczba;
	for (int i = 0; i < wyspa->DajWysokosc(); i++)
	{
		for (int j = 0; j < wyspa->DajSzerokosc(); j++)
		{
			wylosowanaliczba = (std::rand() % 20);
			if (wylosowanaliczba == 0)
			{
				if (wyspa->Pola()[i][j]->IloscKomponentowNaPolu() == 0)
				{
					wyspa->Pola()[i][j]->DodajKomponentDoPola(StworzLosowaRosline(i, j));
				}
			}
		}
	}
}



void CGra::InicjalizacjaKomponentuNaPolu(int _x, int _y, CKomponentEkoSystemu* _komponent)
{
	wyspa->Pola()[_x][_y]->DodajKomponentDoPola(_komponent);
}

void CGra::InicjalizacjaKomponentuNaPolu(CPole* _pole, CKomponentEkoSystemu* _komponent)
{
	wyspa->Pola()[_pole->DajX()][_pole->DajY()]->DodajKomponentDoPola(_komponent);
}

void CGra::update()
{
	wyspa->WyswietlWyspe_Wspolrzedne();
}


CKomponentEkoSystemu* CGra::StworzLosowyKomponent(int _x, int _y)
{
	CKomponentEkoSystemu* wskaznik = nullptr;
	int wylosowanaliczba1 = (std::rand() % 100); //czy zwierze czy roslina
	int wylosowanaliczba2; //ktore z wybranych
	if (wylosowanaliczba1 < 0) // procent jaki ma byc zwierzat
	{
		wylosowanaliczba2 = std::rand() % 2;
		switch (wylosowanaliczba2)
		{
		case 0:
			wskaznik = new CDzik(wyspa->Pola()[_x][_y], wyspa, this);
			break;
		case 1:
			wskaznik = new CWilk(wyspa->Pola()[_x][_y], wyspa, this);
			break;
		case 2:
			wskaznik = new COwca(wyspa->Pola()[_x][_y], wyspa, this);
			break;
		case 3:
			wskaznik = new CWiewiorka(wyspa->Pola()[_x][_y], wyspa, this);
			break;
		case 4:
			wskaznik = new CNiedzwiedz(wyspa->Pola()[_x][_y], wyspa, this);
			break;
		default:
			break;
		}
	}
	else
	{
		wylosowanaliczba2 = std::rand() % 3;
		switch (wylosowanaliczba2)
		{
		case 0:
			wskaznik = new CTrawa(wyspa->Pola()[_x][_y], wyspa, this);
			break;
		case 1:
			wskaznik = new COrzech(wyspa->Pola()[_x][_y], wyspa, this);
			break;
		case 2:
			wskaznik = new CMarchewka(wyspa->Pola()[_x][_y], wyspa, this);
			break;
		default:
			break;
		}
	}
	komponenty.push_back(wskaznik);
	return wskaznik;
}


CWyspa* CGra::ZwrocWyspe()
{
	return wyspa;
}


CKomponentEkoSystemu* CGra::StworzLosoweZwierze(int _x, int _y)
{
	CKomponentEkoSystemu* wskaznik = nullptr;
	int wylosowanaliczba;
	wylosowanaliczba = std::rand() % 1; // zmienic bo wstawia tylko wilki
	switch (wylosowanaliczba)
	{
	case 0:
		wskaznik = new CWilk(wyspa->Pola()[_x][_y], wyspa, this);
		break;
	case 1:
		wskaznik = new CNiedzwiedz(wyspa->Pola()[_x][_y], wyspa, this);
		break;
	case 2:
		wskaznik = new CDzik(wyspa->Pola()[_x][_y], wyspa, this);
		break;
	case 3:
		wskaznik = new COwca(wyspa->Pola()[_x][_y], wyspa, this);
		break;
	case 4:
		wskaznik = new CWiewiorka(wyspa->Pola()[_x][_y], wyspa, this);
		break;
	default:
		break;
	}
	InicjalizacjaKomponentuNaPolu(_x, _y, wskaznik);
	return wskaznik;
}


CKomponentEkoSystemu* CGra::StworzLosowaRosline(int _x, int _y)
{
	CKomponentEkoSystemu* wskaznik = nullptr;
	int wylosowanaliczba;
	wylosowanaliczba = std::rand() % 3;
	switch (wylosowanaliczba)
	{
	case 0:
		wskaznik = new CTrawa(wyspa->Pola()[_x][_y], wyspa, this);
		break;
	case 1:
		wskaznik = new COrzech(wyspa->Pola()[_x][_y], wyspa, this);
		break;
	case 2:
		wskaznik = new CMarchewka(wyspa->Pola()[_x][_y], wyspa, this);
		break;
	default:
		break;
	}
	komponenty.push_back(wskaznik);
	//InicjalizacjaKomponentuNaPolu(_x, _y, wskaznik);
	return wskaznik;
}

CKomponentEkoSystemu* CGra::StworzOwce(int _x, int _y)
{
	CKomponentEkoSystemu* wskaznik;
	wskaznik = new COwca(wyspa->Pola()[_x][_y], wyspa, this);
	komponenty.push_back(wskaznik);
	//InicjalizacjaKomponentuNaPolu(_x, _y, wskaznik);
	return wskaznik;
}

CKomponentEkoSystemu* CGra::StworzWilka(int _x, int _y)
{
	CKomponentEkoSystemu* wskaznik;
	wskaznik = new CWilk(wyspa->Pola()[_x][_y], wyspa, this);
	komponenty.push_back(wskaznik);
	//InicjalizacjaKomponentuNaPolu(_x, _y, wskaznik);
	return wskaznik;
}

CKomponentEkoSystemu* CGra::StworzNiedzwiedzia(int _x, int _y)
{
	CKomponentEkoSystemu* wskaznik;
	wskaznik = new CNiedzwiedz(wyspa->Pola()[_x][_y], wyspa, this);
	komponenty.push_back(wskaznik);
	//InicjalizacjaKomponentuNaPolu(_x, _y, wskaznik);
	return wskaznik;
}

CKomponentEkoSystemu* CGra::StworzWiewiorke(int _x, int _y)
{
	CKomponentEkoSystemu* wskaznik;
	wskaznik = new CWiewiorka(wyspa->Pola()[_x][_y], wyspa, this);
	komponenty.push_back(wskaznik);
	//InicjalizacjaKomponentuNaPolu(_x, _y, wskaznik);
	return wskaznik;
}

CKomponentEkoSystemu* CGra::StworzDzika(int _x, int _y)
{
	CKomponentEkoSystemu* wskaznik;
	wskaznik = new CDzik(wyspa->Pola()[_x][_y], wyspa, this);
	komponenty.push_back(wskaznik);
	//InicjalizacjaKomponentuNaPolu(_x, _y, wskaznik);
	return wskaznik;
}

CKomponentEkoSystemu* CGra::DajKomponent(int _x, int _y) 
{
	if (wyspa->Pola()[_x][_y]->DajKomponentyNaPolu().size() != 0)
	{
		return wyspa->Pola()[_x][_y]->DajKomponentyNaPolu()[0];
	}
	return nullptr;
}


/*CKomponentEkoSystemu* CGra::StworzWilkaRozmnazanie(int _x, int _y)
{
	CKomponentEkoSystemu* wskaznik;
	wskaznik = new CWilk(wyspa->Pola()[_x][_y], wyspa, this);
	komponenty.push_back(wskaznik);
	InicjalizacjaKomponentuNaPolu(_x, _y, wskaznik);
	return wskaznik;
}*/

void CGra::StworzWilkaRozmnazanie(CPole* _pole)
{
	if (_pole == nullptr)
	{
		//std::cout << "Nie mozna stworzyc wilka bo pole jest zle";
	}
	else
	{
		CKomponentEkoSystemu* wskaznik;
		wskaznik = new CWilk(wyspa->Pola()[_pole->DajX()][_pole->DajY()], wyspa, this);
		komponenty.push_back(wskaznik);
		InicjalizacjaKomponentuNaPolu(_pole->DajX(), _pole->DajY(), wskaznik);
	}
}
void CGra::StworzOwceRozmnazanie(CPole* _pole)
{
	if (_pole == nullptr)
	{
		//std::cout << "Nie mozna stworzyc wilka bo pole jest zle";
	}
	else
	{
		CKomponentEkoSystemu* wskaznik;
		wskaznik = new COwca(wyspa->Pola()[_pole->DajX()][_pole->DajY()], wyspa, this);
		komponenty.push_back(wskaznik);
		InicjalizacjaKomponentuNaPolu(_pole->DajX(), _pole->DajY(), wskaznik);
	}
}

void CGra::StworzDzikaRozmnazanie(CPole* _pole)
{
	if (_pole == nullptr)
	{
		//std::cout << "Nie mozna stworzyc wilka bo pole jest zle";
	}
	else
	{
		CKomponentEkoSystemu* wskaznik;
		wskaznik = new CDzik(wyspa->Pola()[_pole->DajX()][_pole->DajY()], wyspa, this);
		komponenty.push_back(wskaznik);
		InicjalizacjaKomponentuNaPolu(_pole->DajX(), _pole->DajY(), wskaznik);
	}
}

void CGra::StworzWiewiorkeRozmnazanie(CPole* _pole)
{
	if (_pole == nullptr)
	{
		//std::cout << "Nie mozna stworzyc wilka bo pole jest zle";
	}
	else
	{
		CKomponentEkoSystemu* wskaznik;
		wskaznik = new CWiewiorka(wyspa->Pola()[_pole->DajX()][_pole->DajY()], wyspa, this);
		komponenty.push_back(wskaznik);
		InicjalizacjaKomponentuNaPolu(_pole->DajX(), _pole->DajY(), wskaznik);
	}
}

void CGra::StworzNiedzwiedziaRozmnazanie(CPole* _pole)
{
	if (_pole == nullptr)
	{
		//std::cout << "Nie mozna stworzyc wilka bo pole jest zle";
	}
	else
	{
		CKomponentEkoSystemu* wskaznik;
		wskaznik = new CNiedzwiedz(wyspa->Pola()[_pole->DajX()][_pole->DajY()], wyspa, this);
		komponenty.push_back(wskaznik);
		InicjalizacjaKomponentuNaPolu(_pole->DajX(), _pole->DajY(), wskaznik);
	}
}


CGra* CGra::DajGre()
{
	return this;
}


void CGra::UsunMartweKomponentyZGry()
{
	wyspa->UsunMarteKomponentyZWyspy();
}

void CGra::Update()
{
	for (int i = 0; i < komponenty.size(); i++)
	{
		komponenty[i]->Zyj();
	}
	//std::cout << " Ilosc komponentow w grze: " << komponenty.size() << std::endl;
	system("cls");
	this->OdswiezWektor();
	this->KoniecRundyOdswiezanie();
	this->UsunMartweKomponentyZGry();
	this->ZwrocWyspe()->WyswietlWyspe_Tablica();
	Sleep(100);
}

void CGra::UpdateWyswietl()
{
	for (int i = 0; i < komponenty.size(); i++)
	{
		system("cls");
		komponenty[i]->Zyj();
		this->ZwrocWyspe()->WyswietlWyspe_Tablica();
		Sleep(1000);
	}
	this->OdswiezWektor();
	this->KoniecRundyOdswiezanie();
	this->UsunMartweKomponentyZGry();
}

void CGra::UpdateBezTabeli()
{
	for (int i = 0; i < komponenty.size(); i++)
	{
		komponenty[i]->Zyj();
		this->ZwrocWyspe()->WyswietlWyspe_Komponenty();
	}
}
void CGra::Inicjalizacja() // inicjalizuje dzialanie komponento odswierza wszystko co potrzebne jest im do gry
{
	for (int i = 0; i < komponenty.size(); i++)
	{
		komponenty[i]->Inicjalizacja();
	}
}

void CGra::KoniecRundyOdswiezanie() // odswiezanie widzianych celow i wymazanie zmarlych z widoku danego zwierzaka
{
	for (int i = 0; i < komponenty.size(); i++)
	{
		komponenty[i]->KoniecRundyOdswiezanie();
	}
}

void CGra::OdswiezWektor()
{
	for (auto iterator = komponenty.begin(); iterator != komponenty.end(); )
	{
		if ((*iterator)->CzyKomponentJestMartwy())
		{
			iterator = komponenty.erase(iterator);
		}
		else
		{
			iterator++;
		}
	}
}