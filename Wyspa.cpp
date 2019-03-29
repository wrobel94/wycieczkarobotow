#include "stdafx.h"
#include "Wyspa.h"


CWyspa::CWyspa()
{
}

CWyspa::CWyspa(int _x, int _y)
{
	szerokosc = _x;
	wysokosc = _y;
	for (int i = 0; i < wysokosc; i++)
	{
		std::vector<CPole*> vector;
		pola.push_back(vector);
		for (int j = 0; j < szerokosc; j++)
		{
			pola[i].push_back(new CPole(i, j, this));
		}
	}
}


CWyspa::~CWyspa()
{
	for (int i=0;i <pola.size(); i++)
	{
		for (int j =0; j <pola[i].size() ; j++)
		{
			delete pola[i][j];
		}
	}
	//std::cout << "Destruktor CWyspa" << std::endl;
}

void CWyspa::WyswietlWyspe_Wspolrzedne()
{
	for (int i = 0; i < wysokosc; i++)
	{
		for (int j = 0; j < szerokosc; j++)
		{
			pola[i][j]->WyswietlWspolrzedne();
			std::cout << "  ";
		}
		std::cout << std::endl;
	}
}

int CWyspa::DajSzerokosc()
{
	return szerokosc;
}

int CWyspa::DajWysokosc()
{
	return wysokosc;
}

std::vector<std::vector<CPole*>> CWyspa::Pola()
{
	return pola;
}

void CWyspa::WyswietlWyspe_Komponenty()
{
	for (int i = 0; i < wysokosc; i++)
	{
		for (int j = 0; j < szerokosc; j++)
		{
			pola[i][j]->WyswietlKomponentyNaPolu();
			std::cout << std::endl;
		}
	}
}

void CWyspa::WyswietlWyspe_Tablica()
{
	for (int i = 0; i < wysokosc; i++)
	{
		for (int j = 0; j < szerokosc; j++)
		{
			pola[i][j]->WyswietlKomponentyNaPolu_Tablica();
		}
		std::cout << std::endl;
		std::cout << std::endl;
	}
}

bool CWyspa::CzyPoleJestNaWyspie(int _x, int _y)
{
	if ((pola.size()> _x)&&(_x>0))
	{
		if ((pola[_x].size()> _y)&&(_y>0))
		{
			return true;
		}
	}
	return false;
}

bool CWyspa::CZyPoleJestNaWyspieIMoznaNaNieWejsc(int _x, int _y)
{
	if (this->CzyPoleJestNaWyspie(_x, _y))
	{
		if (this->DajPole(_x, _y)->CzyMoznaWejscNaPole(this->DajPole(_x, _y)))
		{
			return true;
		}
		return false;
	}
	return false;
}

CPole* CWyspa::DajPole(int _x, int _y)
{
	if (CzyPoleJestNaWyspie(_x, _y))
	{
		return pola[_x][_y];
	}
	return nullptr;
}

void CWyspa::UsunMarteKomponentyZWyspy()
{
	for (int i = 0; i < wysokosc; i++)
	{
		for (int j = 0; j < szerokosc; j++)
		{
			pola[i][j]->UsunMartweKomponentyZPola();
		}
	}
}