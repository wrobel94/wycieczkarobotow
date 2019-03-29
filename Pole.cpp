#include "stdafx.h"
#include "Pole.h"


CPole::CPole()
{
}

CPole::CPole(int _x, int _y, CWyspa* _wyspa)
{
	x = _x;
	y = _y;
	maksymalnapojemnoscpola = 2;
	wyspa = _wyspa;
}

CPole::~CPole()
{
	//std::cout << "Destruktor CPole" << std::endl;
}


void CPole::WyswietlWspolrzedne()
{
	std::cout << "(" << x << "," << y << ")";
}

int CPole::IloscKomponentowNaPolu()
{
	return komponentynapolu.size();
}

void CPole::DodajKomponentDoPola(CKomponentEkoSystemu* _wskaznikdokomponentu)
{
	komponentynapolu.push_back(_wskaznikdokomponentu);
}

void CPole::WyswietlKomponentyNaPolu()
{
	std::cout << "Pole" << "(" << x << "," << y << ") ";
	if (komponentynapolu.size())
	{
		for (int i = 0; i < komponentynapolu.size(); i++)
		{
			std::cout << "Komponent nr " << i + 1 << " na polu ";
			komponentynapolu[i]->WyswietlKomponent();
		}
	}
	else
	{
		std::cout << "Na polu tym nic niema";
	}
	std::cout << std::endl;
}

void CPole::WyswietlKomponentyNaPolu_Tablica()
{
	if (komponentynapolu.size())
	{
		if (komponentynapolu.size() == 1)
		{
			std::cout << "    ";
			komponentynapolu[0]->WyswietlKomponent_Tablica();
			std::cout << "    ";
		}
		else
		{
			for (int i = 0; i < komponentynapolu.size(); i++) // ilosc komponentow wyswietlanych na polu
			{
				std::cout << "  ";
				komponentynapolu[i]->WyswietlKomponent_Tablica();
			}
			std::cout << "  ";
		}
	}
	else
	{

		std::cout << "..........";
	}
}


int CPole::DajX()
{
	return x;
}


int CPole::DajY()
{
	return y;
}

CPole* CPole::DajPole()
{
	return this;
}

std::vector<CKomponentEkoSystemu*> CPole::DajKomponentyNaPolu()
{
	return komponentynapolu;
}


void CPole::UsunKomponentZPola(CKomponentEkoSystemu* _komponent)
{
	auto iterator = std::find_if(komponentynapolu.begin(), komponentynapolu.end(),
		[&](CKomponentEkoSystemu* _komponent1)
	{
		return _komponent1 == _komponent;
	});
	//std::cout << (*iterator)->DajNazwe(); //debag
	//delete *iterator;
	komponentynapolu.erase(iterator);

	//this->DajWyspe()


	/*std::cout << "Pole" << "(" << x << "," << y << ")" << std::endl;
	if (komponentynapolu.size())
	{
	for (int i = 0; i < komponentynapolu.size(); i++)
	{
	std::cout << "Komponent nr " << i + 1 << " na polu ";
	komponentynapolu[i]->WyswietlKomponent();
	}
	}
	else
	{
	std::cout << "Na polu tym nic niema";
	}*/

}
void CPole::UsunMartweKomponentyZPola()
{
	//std::vector<CKomponentEkoSystemu*>::iterator iterator;
	for (auto iterator = komponentynapolu.begin(); iterator != komponentynapolu.end(); )
	{
		if ((*iterator)->CzyKomponentJestMartwy())
		{
			delete *iterator;
			iterator = komponentynapolu.erase(iterator);
			//std::cout << "USUNIENTY" << std::endl;
		}
		else
		{
			iterator++;
		}
	}
	/*for (int i = 0; i < komponentynapolu.size(); i++)
	{
	if (komponentynapolu[i]->CzyKomponentJestMartwy())
	{
	delete komponentynapolu[i];
	komponentynapolu.erase(komponentynapolu.begin() + i);
	}
	}*/
	/*komponentynapolu.erase(std::remove_if(komponentynapolu.begin(), komponentynapolu.end(), [](CKomponentEkoSystemu* _komponent)
	{
	return _komponent->CzyKomponentJestMartwy();
	}),komponentynapolu.end());*/
	/*auto iterator = komponentynapolu.begin();
	while (iterator != komponentynapolu.end())
	{
	iterator = std::find_if(komponentynapolu.begin(), komponentynapolu.end(), [&](CKomponentEkoSystemu* _komponent)
	{
	return _komponent->CzyKomponentJestMartwy();
	}
	);
	komponentynapolu.erase(iterator);
	iterator++;
	}*/
}

void CPole::UsunKomponentZGry(CKomponentEkoSystemu* _komponent)
{
	//delete _komponent;
	auto iterator = std::find_if(komponentynapolu.begin(), komponentynapolu.end(),
		[&](CKomponentEkoSystemu* _komponent1)
	{
		return _komponent1 == _komponent;
	});
	//std::cout << (*iterator)->DajNazwe() << std::endl;
	//std::cout << (*iterator)->DajNazwe(); //debag
	komponentynapolu.erase(iterator);
	std::cout << "Ususniety";
	//delete *iterator;
	std::cout << "WYKASOWANY";
}

void CPole::DodajKomponentNaPole(CKomponentEkoSystemu* _komponent)
{
	//	if()
	if (komponentynapolu.size() < maksymalnapojemnoscpola) {
		komponentynapolu.push_back(_komponent);
	}
}

bool CPole::CzyMoznaWejscNaPole(CPole* _pole)
{
	if (_pole->DajKomponentyNaPolu().size() < maksymalnapojemnoscpola)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int CPole::OdlegloscOdPola(CPole* _pole1, CPole* _pole2)
{
	int pozX = _pole1->DajX();
	int pozY = _pole1->DajY();
	int deltaX = abs(pozX - _pole2->DajX());
	int deltaY = abs(pozY - _pole2->DajY());
	return std::max(deltaX, deltaY);
}

/*CWyspa* CPole::DajWyspe()
{
this->
}*/
/*
void CPole::StworzWilka()
{

}

void CPole::StworzOwce()
{

}

void CPole::StworzWiewiorke()
{

}

void CPole::StworzDzika()
{

}

void CPole::StworzNiedzwiedzia()
{

}*/