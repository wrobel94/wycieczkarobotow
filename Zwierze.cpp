#include "stdafx.h"
#include "Zwierze.h"


CZwierze::CZwierze()
{
}


CZwierze::CZwierze(CPole* _ustawianapozycja, CWyspa* _ustawianawyspa) : CRuchome(_ustawianapozycja, _ustawianawyspa)
{
}

CZwierze::~CZwierze()
{
	//std::cout << "Destruktor CZwierze" << std::endl;
}


void CZwierze::WyswietlKomponent()
{
	std::cout << "(" << nazwa << ", zycie:" << zycie << ", tluszcz:" << tluszcz << ")";
}

void CZwierze::WyswietlKomponent_Tablica()
{
	std::cout << inicialy;
}

void CZwierze::WyswietlKomponentyKtoreWidzisz()
{
	for (int i = 0; i < widzianekomponenty.size(); i++)
	{
		widzianekomponenty[i]->WyswietlKomponent();
	}
}



void CZwierze::OdswiezPoleWidzenia() // wyznacza zakres widzenienia na podstawie zmiennej pole widzenia, wpisuje wszystkie pola do wektora
{
	if (!polewidzenia.empty())
	{
		polewidzenia.clear();
	}
	int min_i = aktualnapozycja->DajX() - zakreswidzenia;
	int max_i = aktualnapozycja->DajX() + zakreswidzenia;
	int min_j = aktualnapozycja->DajY() - zakreswidzenia;
	int max_j = aktualnapozycja->DajY() + zakreswidzenia;
	if (min_i < 0)
	{
		min_i = 0;
	}
	if (max_i > wyspanaktorejjestem->DajWysokosc())
	{
		max_i = wyspanaktorejjestem->DajWysokosc();
	}
	if (min_j < 0)
	{
		min_j = 0;
	}
	if (max_j > wyspanaktorejjestem->DajSzerokosc())
	{
		max_j = wyspanaktorejjestem->DajSzerokosc();
	}
	for (int i = min_i; i < max_i; i++)
	{
		for (int j = min_j; j < max_j; j++)
		{
			polewidzenia.push_back((wyspanaktorejjestem->Pola())[i][j]);
		}
	}
}


void CZwierze::WyswietlPoleWidzenia()
{
	for (int i = 0; i < polewidzenia.size(); i++)
	{
		polewidzenia[i]->WyswietlKomponentyNaPolu();
	}
}

template<class Zwierze1, class Zwierze2> bool CZwierze::PorownajDwaZwierzaki(Zwierze1* _zwierzenaktoregotyprzutuje, Zwierze2* _zwierzerzutowane)
{
	if (dynamic_cast<Zwierze1*>(_zwierzerzutowane) != nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void CZwierze::WyznaczKomponentyKtoreWidzisz()
{
	if (!widzianekomponenty.empty())
	{
		widzianekomponenty.clear();
	}

	if (!zwierzetawpoluwidzenia.empty())
	{
		zwierzetawpoluwidzenia.clear();
	}

	if (!roslinywpoluwidzenia.empty())
	{
		roslinywpoluwidzenia.clear();
	}
	for (auto i : polewidzenia)
	{
		for (int j = 0; j < i->DajKomponentyNaPolu().size(); j++)
		{
			if (i->DajKomponentyNaPolu()[j]) {
				if ((i->DajKomponentyNaPolu()[j] != this) && (!(i->DajKomponentyNaPolu()[j]->CzyKomponentJestMartwy()))) // pomija martwe komponenty i siebie samego
				{
					widzianekomponenty.push_back(i->DajKomponentyNaPolu()[j]);
					if (dynamic_cast<CZwierze*>(i->DajKomponentyNaPolu()[j]))
					{
						zwierzetawpoluwidzenia.push_back(dynamic_cast<CZwierze*>(i->DajKomponentyNaPolu()[j]));
					}
					else
					{
						roslinywpoluwidzenia.push_back(dynamic_cast<CRoslina*>(i->DajKomponentyNaPolu()[j]));
					}
				}
			}
		}
	}
}

int CZwierze::DajMase()
{
	return masa;
}


int CZwierze::Odleglosc(CKomponentEkoSystemu* _komponent)
{
	int pozX = _komponent->DajPole()->DajX();
	int pozY = _komponent->DajPole()->DajY();
	int deltaX = abs(pozX - this->aktualnapozycja->DajX());
	int deltaY = abs(pozY - this->aktualnapozycja->DajY());
	return std::max(deltaX, deltaY);
}

int CZwierze::Odleglosc(CZwierze* _zwierze)
{
	int pozX = _zwierze->DajPole()->DajX();
	int pozY = _zwierze->DajPole()->DajY();
	int deltaX = abs(pozX - this->aktualnapozycja->DajX());
	int deltaY = abs(pozY - this->aktualnapozycja->DajY());
	return std::max(deltaX, deltaY);
}


int CZwierze::DajTluszcz()
{
	return tluszcz;
}

void CZwierze::DodajTluszcz(int _tluszcz)
{
	if (this->max_tluszcz <= ((this->tluszcz) + _tluszcz))
	{
		tluszcz = this->max_tluszcz;
	}
	else
	{
		tluszcz = this->tluszcz + _tluszcz;
	}
	this->ResetujZycie();
}

void CZwierze::WyswietlTluszcz()
{
	std::cout << "Moja pozaycja ";
	this->DajPozycje();
	std::cout << " ";
	this->DajNazwe();
	std::cout << " moj tluszcz to: " << tluszcz;
	std::cout << " moje zycie to: " << zycie << std::endl;
}

void CZwierze::UstawCelRozmnazanie()
{
	if (!zwierzetawpoluwidzenia.empty())
	{
		celrozmananie = nullptr;
	}
	for (auto i : zwierzetawpoluwidzenia)
	{
		if (celrozmananie == nullptr)
		{
			if ((i->DajNazwe() == this->DajNazwe()) && (!(i->CzyKomponentJestMartwy())))
			{
				celrozmananie = i;
			}
		}
	}
}

CKomponentEkoSystemu* CZwierze::DajCelRozmnazanie()
{
	if (celrozmananie != nullptr)
	{
		return celrozmananie;
	}
	else
	{
		return nullptr;
	}
}

void CZwierze::OdswiezCelRozmnazanie()
{
	if (this->DajCelRozmnazanie())
	{
		if (celrozmananie->CzyKomponentJestMartwy())
		{
			celrozmananie = nullptr;
		}
	}
}

int CZwierze::Odleglosc(CPole* _pole)
{
	int pozX = _pole->DajPole()->DajX();
	int pozY = _pole->DajPole()->DajY();
	int deltaX = abs(pozX - this->aktualnapozycja->DajX());
	int deltaY = abs(pozY - this->aktualnapozycja->DajY());
	return std::max(deltaX, deltaY); // zwraca max z deltaX i deltaY
}

void CZwierze::KoniecRundyOdswiez()
{

}

void CZwierze::WyswietlCelRozmnazanie()
{
	if (this->DajCelRozmnazanie())
	{
		std::cout << "Posiadam cel rozmnazanie: ";
		std::cout << " " << this->DajCelRozmnazanie()->DajNazwe() << std::endl;
	}
	else
	{
		std::cout << "Nie mam aktualnie cel rozmnazanie" << std::endl;
	}
}

int CZwierze::DajCzasPogoniZaCelRozmnazanie()
{
	return czaspogonizacelrozmnazanie;
}

void CZwierze::ZmniejszCzasPogoniZaCelRozmnazanie()
{
	if (czaspogonizacelrozmnazanie > 0)
	{
		czaspogonizacelrozmnazanie = maksymalnyczaspogonizacelrozmnazanie - 1;
	}
	else
	{
		czaspogonizacelrozmnazanie = 0;
	}
}

void CZwierze::ResetujCzasPogoniZaCelRozmnazanie()
{
	czaspogonizacelrozmnazanie = maksymalnyczaspogonizacelrozmnazanie;
}

void CZwierze::UsunCelRozmnaznie()
{
	if (this->DajCelRozmnazanie() != nullptr)
	{
		this->UstawCelRozmnazanie();
	}
}

void CZwierze::ZmniejszTluszczRuch()
{
	if (this->DajTluszcz() == 0)
	{
		this->ZmniejszZycie(this->DajWspoczynnikZmniejszeniaZycia());
	}
	else
	{
		this->UstawTluszcz(this->DajTluszcz() - this->DajWspolczynnikSpalaniaTluszczuPrzyRuchu());
	}
}

void CZwierze::UstawTluszcz(int _tluszcz)
{
	if (_tluszcz > 0)
	{
		if (tluszcz < _tluszcz)
		{
			if (max_tluszcz < _tluszcz)
			{
				tluszcz = _tluszcz;
			}
			else
			{
				tluszcz = max_tluszcz;
			}
		}
		else
		{
			tluszcz = _tluszcz;
		}
	}
	else
	{
		tluszcz = 0;
		this->ZmniejszZycie(this->DajWspoczynnikZmniejszeniaZycia()); // nie wiem czy tak mozna, jakby byly bagi usun
	}
}

void CZwierze::ZmniejszTluszczRozmanzanie()
{
	if (this->DajTluszcz() == 0)
	{
		this->ZmniejszZycie(this->DajWspoczynnikZmniejszeniaZycia());
	}
	else
	{
		this->UstawTluszcz(this->DajTluszcz() - this->DajWspolczynnikSpalaniaTluszczuPrzyRozmnazaniu());
	}
}

int CZwierze::DajWspolczynnikSpalaniaTluszczuPrzyRuchu()
{
	return wspolczynnikspalaniatluszczuprzyruchu;
}

int CZwierze::DajWspolczynnikSpalaniaTluszczuPrzyRozmnazaniu()
{
	return wspolczynnikspalaniatluszczuprzyrozmnazaniu;
}

int CZwierze::DajZycie()
{
	return zycie;
}

void CZwierze::ZmniejszZycie(int _wspolczynnik)
{
	if (this->DajZycie() > 0)
	{
		if ((this->DajZycie() - _wspolczynnik) > 0)
		{
			zycie = this->DajZycie() - _wspolczynnik;
		}
		else
		{
			this->UstawMartwy();
			//std::cout << "Ustaw martwy" << std::endl;
		}
	}
	else
	{
		this->UstawMartwy();
		//std::cout << "Ustaw martwy" << std::endl;
	}
}

void CZwierze::ResetujZycie()
{
	if (((this->DajTluszcz()*100)/this->DajMax_Tluszcz()) > 10)
	{
		zycie = max_zycie;
	}
}

int CZwierze::DajMax_Tluszcz()
{
	return max_tluszcz;
}

int CZwierze::DajWspoczynnikZmniejszeniaZycia()
{
	return wspolczynnikzmniejszeniazycia;
}


int CZwierze::DajZakresWidzenia()
{
	return zakreswidzenia;
}

int CZwierze::DajWspolczynnikPlodnosci()
{
	return wspolczynnikplodnosci;
}

void CZwierze::UciekajPrzed(CZwierze* _atakujacy)
{
	if (_atakujacy != nullptr)
	{
		if (_atakujacy->DajPole()->DajX() > this->DajPole()->DajX())
		{
			if (_atakujacy->DajPole()->DajY() > this->DajPole()->DajY())
			{
				if (this->DajWyspe()->CZyPoleJestNaWyspieIMoznaNaNieWejsc(this->DajPole()->DajX() - 1, this->DajPole()->DajY() - 1))
				{
					ZmienPozycje(this->DajWyspe()->Pola()[this->DajPole()->DajX() - 1][this->DajPole()->DajY() - 1]);
				}
				else if (this->DajWyspe()->CZyPoleJestNaWyspieIMoznaNaNieWejsc(this->DajPole()->DajX() - 1, this->DajPole()->DajY()))
				{
					ZmienPozycje(this->DajWyspe()->Pola()[this->DajPole()->DajX() - 1][this->DajPole()->DajY()]);
				}
				else if (this->DajWyspe()->CZyPoleJestNaWyspieIMoznaNaNieWejsc(this->DajPole()->DajX(), this->DajPole()->DajY() - 1))
				{
					ZmienPozycje(this->DajWyspe()->Pola()[this->DajPole()->DajX()][this->DajPole()->DajY() - 1]);
				}
				else if (this->DajWyspe()->CZyPoleJestNaWyspieIMoznaNaNieWejsc(this->DajPole()->DajX() + 1, this->DajPole()->DajY() - 1))
				{
					ZmienPozycje(this->DajWyspe()->Pola()[this->DajPole()->DajX() + 1][this->DajPole()->DajY() - 1]);
				}
				else if (this->DajWyspe()->CZyPoleJestNaWyspieIMoznaNaNieWejsc(this->DajPole()->DajX() - 1, this->DajPole()->DajY() + 1))
				{
					ZmienPozycje(this->DajWyspe()->Pola()[this->DajPole()->DajX() - 1][this->DajPole()->DajY() + 1]);
				}
				else if (this->DajWyspe()->CZyPoleJestNaWyspieIMoznaNaNieWejsc(this->DajPole()->DajX(), this->DajPole()->DajY() - 1))
				{
					ZmienPozycje(this->DajWyspe()->Pola()[this->DajPole()->DajX()][this->DajPole()->DajY() - 1]);
				}
				else if (this->DajWyspe()->CZyPoleJestNaWyspieIMoznaNaNieWejsc(this->DajPole()->DajX() - 1, this->DajPole()->DajY()))
				{
					ZmienPozycje(this->DajWyspe()->Pola()[this->DajPole()->DajX() - 1][this->DajPole()->DajY()]);
				}
			}
			else if (_atakujacy->DajPole()->DajY() < this->DajPole()->DajY())
			{
				if (this->DajWyspe()->CzyPoleJestNaWyspie(this->DajPole()->DajX() - 1, this->DajPole()->DajY() + 1))
				{
					ZmienPozycje(this->DajWyspe()->Pola()[this->DajPole()->DajX() - 1][this->DajPole()->DajY() + 1]);
				}
				else if (this->DajWyspe()->CZyPoleJestNaWyspieIMoznaNaNieWejsc(this->DajPole()->DajX() - 1, this->DajPole()->DajY()))
				{
					ZmienPozycje(this->DajWyspe()->Pola()[this->DajPole()->DajX() - 1][this->DajPole()->DajY()]);
				}
				else if (this->DajWyspe()->CZyPoleJestNaWyspieIMoznaNaNieWejsc(this->DajPole()->DajX(), this->DajPole()->DajY() + 1))
				{
					ZmienPozycje(this->DajWyspe()->Pola()[this->DajPole()->DajX()][this->DajPole()->DajY() + 1]);
				}
				else if (this->DajWyspe()->CZyPoleJestNaWyspieIMoznaNaNieWejsc(this->DajPole()->DajX() - 1, this->DajPole()->DajY() - 1))
				{
					ZmienPozycje(this->DajWyspe()->Pola()[this->DajPole()->DajX() - 1][this->DajPole()->DajY() - 1]);
				}
				else if (this->DajWyspe()->CZyPoleJestNaWyspieIMoznaNaNieWejsc(this->DajPole()->DajX() + 1, this->DajPole()->DajY() + 1))
				{
					ZmienPozycje(this->DajWyspe()->Pola()[this->DajPole()->DajX() + 1][this->DajPole()->DajY() + 1]);
				}
				else if (this->DajWyspe()->CZyPoleJestNaWyspieIMoznaNaNieWejsc(this->DajPole()->DajX(), this->DajPole()->DajY() + 1))
				{
					ZmienPozycje(this->DajWyspe()->Pola()[this->DajPole()->DajX()][this->DajPole()->DajY() + 1]);
				}
				else if (this->DajWyspe()->CZyPoleJestNaWyspieIMoznaNaNieWejsc(this->DajPole()->DajX() + 1, this->DajPole()->DajY()))
				{
					ZmienPozycje(this->DajWyspe()->Pola()[this->DajPole()->DajX() + 1][this->DajPole()->DajY()]);
				}
				else if (this->DajWyspe()->CZyPoleJestNaWyspieIMoznaNaNieWejsc(this->DajPole()->DajX(), this->DajPole()->DajY() + 1))
				{
					ZmienPozycje(this->DajWyspe()->Pola()[this->DajPole()->DajX()][this->DajPole()->DajY() + 1]);
				}
			}
			else
			{
				if (this->DajWyspe()->CzyPoleJestNaWyspie(this->DajPole()->DajX() - 1, this->DajPole()->DajY()))
				{
					ZmienPozycje(this->DajWyspe()->Pola()[this->DajPole()->DajX() - 1][this->DajPole()->DajY()]);
				}
				else if (this->DajWyspe()->CZyPoleJestNaWyspieIMoznaNaNieWejsc(this->DajPole()->DajX() - 1, this->DajPole()->DajY() + 1))
				{
					ZmienPozycje(this->DajWyspe()->Pola()[this->DajPole()->DajX() - 1][this->DajPole()->DajY() + 1]);
				}
				else if (this->DajWyspe()->CZyPoleJestNaWyspieIMoznaNaNieWejsc(this->DajPole()->DajX() - 1, this->DajPole()->DajY() - 1))
				{
					ZmienPozycje(this->DajWyspe()->Pola()[this->DajPole()->DajX() - 1][this->DajPole()->DajY() - 1]);
				}
				else if (this->DajWyspe()->CZyPoleJestNaWyspieIMoznaNaNieWejsc(this->DajPole()->DajX(), this->DajPole()->DajY() - 1))
				{
					ZmienPozycje(this->DajWyspe()->Pola()[this->DajPole()->DajX()][this->DajPole()->DajY() - 1]);
				}
				else if (this->DajWyspe()->CZyPoleJestNaWyspieIMoznaNaNieWejsc(this->DajPole()->DajX(), this->DajPole()->DajY() + 1))
				{
					ZmienPozycje(this->DajWyspe()->Pola()[this->DajPole()->DajX()][this->DajPole()->DajY() + 1]);
				}
				else if (this->DajWyspe()->CZyPoleJestNaWyspieIMoznaNaNieWejsc(this->DajPole()->DajX() + 1, this->DajPole()->DajY() - 1))
				{
					ZmienPozycje(this->DajWyspe()->Pola()[this->DajPole()->DajX() + 1][this->DajPole()->DajY() - 1]);
				}
				else if (this->DajWyspe()->CZyPoleJestNaWyspieIMoznaNaNieWejsc(this->DajPole()->DajX() + 1, this->DajPole()->DajY()) + 1)
				{
					ZmienPozycje(this->DajWyspe()->Pola()[this->DajPole()->DajX() + 1][this->DajPole()->DajY() + 1]);
				}
			}
		}
		else if (_atakujacy->DajPole()->DajX() < this->DajPole()->DajX())
		{
			if (_atakujacy->DajPole()->DajY() > this->DajPole()->DajY())
			{
				if (this->DajWyspe()->CzyPoleJestNaWyspie(this->DajPole()->DajX() + 1, this->DajPole()->DajY() - 1))
				{
					ZmienPozycje(this->DajWyspe()->Pola()[this->DajPole()->DajX() + 1][this->DajPole()->DajY() - 1]);
				}
				else if (this->DajWyspe()->CZyPoleJestNaWyspieIMoznaNaNieWejsc(this->DajPole()->DajX(), this->DajPole()->DajY() - 1))
				{
					ZmienPozycje(this->DajWyspe()->Pola()[this->DajPole()->DajX()][this->DajPole()->DajY() - 1]);
				}
				else if (this->DajWyspe()->CZyPoleJestNaWyspieIMoznaNaNieWejsc(this->DajPole()->DajX() + 1, this->DajPole()->DajY()))
				{
					ZmienPozycje(this->DajWyspe()->Pola()[this->DajPole()->DajX() + 1][this->DajPole()->DajY()]);
				}
				else if (this->DajWyspe()->CZyPoleJestNaWyspieIMoznaNaNieWejsc(this->DajPole()->DajX() - 1, this->DajPole()->DajY() - 1))
				{
					ZmienPozycje(this->DajWyspe()->Pola()[this->DajPole()->DajX() - 1][this->DajPole()->DajY() - 1]);
				}
				else if (this->DajWyspe()->CZyPoleJestNaWyspieIMoznaNaNieWejsc(this->DajPole()->DajX() + 1, this->DajPole()->DajY() + 1))
				{
					ZmienPozycje(this->DajWyspe()->Pola()[this->DajPole()->DajX() + 1][this->DajPole()->DajY() + 1]);
				}
				else if (this->DajWyspe()->CZyPoleJestNaWyspieIMoznaNaNieWejsc(this->DajPole()->DajX(), this->DajPole()->DajY() + 1))
				{
					ZmienPozycje(this->DajWyspe()->Pola()[this->DajPole()->DajX()][this->DajPole()->DajY() + 1]);
				}
				else if (this->DajWyspe()->CZyPoleJestNaWyspieIMoznaNaNieWejsc(this->DajPole()->DajX() - 1, this->DajPole()->DajY()))
				{
					ZmienPozycje(this->DajWyspe()->Pola()[this->DajPole()->DajX() - 1][this->DajPole()->DajY()]);
				}
			}
			else if (_atakujacy->DajPole()->DajY() < this->DajPole()->DajY())
			{
				if (this->DajWyspe()->CzyPoleJestNaWyspie(this->DajPole()->DajX() + 1, this->DajPole()->DajY() + 1))
				{
					ZmienPozycje(this->DajWyspe()->Pola()[this->DajPole()->DajX() + 1][this->DajPole()->DajY() + 1]);
				}
				else if (this->DajWyspe()->CzyPoleJestNaWyspie(this->DajPole()->DajX() + 1, this->DajPole()->DajY()))
				{
					ZmienPozycje(this->DajWyspe()->Pola()[this->DajPole()->DajX() + 1][this->DajPole()->DajY()]);
				}
				else if (this->DajWyspe()->CZyPoleJestNaWyspieIMoznaNaNieWejsc(this->DajPole()->DajX(), this->DajPole()->DajY() + 1))
				{
					ZmienPozycje(this->DajWyspe()->Pola()[this->DajPole()->DajX()][this->DajPole()->DajY() + 1]);
				}
				else if (this->DajWyspe()->CZyPoleJestNaWyspieIMoznaNaNieWejsc(this->DajPole()->DajX() + 1, this->DajPole()->DajY() - 1))
				{
					ZmienPozycje(this->DajWyspe()->Pola()[this->DajPole()->DajX() + 1][this->DajPole()->DajY() - 1]);
				}
				else if (this->DajWyspe()->CZyPoleJestNaWyspieIMoznaNaNieWejsc(this->DajPole()->DajX() - 1, this->DajPole()->DajY() + 1))
				{
					ZmienPozycje(this->DajWyspe()->Pola()[this->DajPole()->DajX() - 1][this->DajPole()->DajY() + 1]);
				}
				else if (this->DajWyspe()->CZyPoleJestNaWyspieIMoznaNaNieWejsc(this->DajPole()->DajX() - 1, this->DajPole()->DajY()))
				{
					ZmienPozycje(this->DajWyspe()->Pola()[this->DajPole()->DajX() - 1][this->DajPole()->DajY()]);
				}
				else if (this->DajWyspe()->CZyPoleJestNaWyspieIMoznaNaNieWejsc(this->DajPole()->DajX(), this->DajPole()->DajY() - 1))
				{
					ZmienPozycje(this->DajWyspe()->Pola()[this->DajPole()->DajX()][this->DajPole()->DajY() - 1]);
				}
			}
			else
			{
				if (this->DajWyspe()->CzyPoleJestNaWyspie(this->DajPole()->DajX() + 1, this->DajPole()->DajY()))
				{
					ZmienPozycje(this->DajWyspe()->Pola()[this->DajPole()->DajX() + 1][this->DajPole()->DajY()]);
				}
				else if (this->DajWyspe()->CzyPoleJestNaWyspie(this->DajPole()->DajX() + 1, this->DajPole()->DajY() + 1))
				{
					ZmienPozycje(this->DajWyspe()->Pola()[this->DajPole()->DajX() + 1][this->DajPole()->DajY() + 1]);
				}
				else if (this->DajWyspe()->CzyPoleJestNaWyspie(this->DajPole()->DajX() + 1, this->DajPole()->DajY() - 1))
				{
					ZmienPozycje(this->DajWyspe()->Pola()[this->DajPole()->DajX() + 1][this->DajPole()->DajY() - 1]);
				}
				else if (this->DajWyspe()->CZyPoleJestNaWyspieIMoznaNaNieWejsc(this->DajPole()->DajX(), this->DajPole()->DajY() + 1))
				{
					ZmienPozycje(this->DajWyspe()->Pola()[this->DajPole()->DajX()][this->DajPole()->DajY() + 1]);
				}
				else if (this->DajWyspe()->CZyPoleJestNaWyspieIMoznaNaNieWejsc(this->DajPole()->DajX(), this->DajPole()->DajY() - 1))
				{
					ZmienPozycje(this->DajWyspe()->Pola()[this->DajPole()->DajX()][this->DajPole()->DajY() - 1]);
				}
				else if (this->DajWyspe()->CZyPoleJestNaWyspieIMoznaNaNieWejsc(this->DajPole()->DajX() - 1, this->DajPole()->DajY() - 1))
				{
					ZmienPozycje(this->DajWyspe()->Pola()[this->DajPole()->DajX() - 1][this->DajPole()->DajY() - 1]);
				}
				else if (this->DajWyspe()->CZyPoleJestNaWyspieIMoznaNaNieWejsc(this->DajPole()->DajX() - 1, this->DajPole()->DajY() + 1))
				{
					ZmienPozycje(this->DajWyspe()->Pola()[this->DajPole()->DajX() - 1][this->DajPole()->DajY() + 1]);
				}
			}
		}
		else
		{
			if (_atakujacy->DajPole()->DajY() > this->DajPole()->DajY())
			{
				if (this->DajWyspe()->CzyPoleJestNaWyspie(this->DajPole()->DajX(), this->DajPole()->DajY() - 1))
				{
					ZmienPozycje(this->DajWyspe()->Pola()[this->DajPole()->DajX()][this->DajPole()->DajY() - 1]);
				}
				else if (this->DajWyspe()->CzyPoleJestNaWyspie(this->DajPole()->DajX() + 1, this->DajPole()->DajY() - 1))
				{
					ZmienPozycje(this->DajWyspe()->Pola()[this->DajPole()->DajX() + 1][this->DajPole()->DajY() - 1]);
				}
				else if (this->DajWyspe()->CzyPoleJestNaWyspie(this->DajPole()->DajX() - 1, this->DajPole()->DajY() - 1))
				{
					ZmienPozycje(this->DajWyspe()->Pola()[this->DajPole()->DajX() - 1][this->DajPole()->DajY() - 1]);
				}
				else if (this->DajWyspe()->CZyPoleJestNaWyspieIMoznaNaNieWejsc(this->DajPole()->DajX() + 1, this->DajPole()->DajY()))
				{
					ZmienPozycje(this->DajWyspe()->Pola()[this->DajPole()->DajX() + 1][this->DajPole()->DajY()]);
				}
				else if (this->DajWyspe()->CZyPoleJestNaWyspieIMoznaNaNieWejsc(this->DajPole()->DajX() - 1, this->DajPole()->DajY()))
				{
					ZmienPozycje(this->DajWyspe()->Pola()[this->DajPole()->DajX() - 1][this->DajPole()->DajY()]);
				}
				else if (this->DajWyspe()->CZyPoleJestNaWyspieIMoznaNaNieWejsc(this->DajPole()->DajX() - 1, this->DajPole()->DajY() + 1))
				{
					ZmienPozycje(this->DajWyspe()->Pola()[this->DajPole()->DajX() - 1][this->DajPole()->DajY() + 1]);
				}
				else if (this->DajWyspe()->CZyPoleJestNaWyspieIMoznaNaNieWejsc(this->DajPole()->DajX() + 1, this->DajPole()->DajY() + 1))
				{
					ZmienPozycje(this->DajWyspe()->Pola()[this->DajPole()->DajX() + 1][this->DajPole()->DajY() + 1]);
				}
			}
			else if (_atakujacy->DajPole()->DajY() < this->DajPole()->DajY())
			{
				if (this->DajWyspe()->CZyPoleJestNaWyspieIMoznaNaNieWejsc(this->DajPole()->DajX(), this->DajPole()->DajY() + 1))
				{
					ZmienPozycje(this->DajWyspe()->Pola()[this->DajPole()->DajX()][this->DajPole()->DajY() + 1]);
				}
				else if (this->DajWyspe()->CZyPoleJestNaWyspieIMoznaNaNieWejsc(this->DajPole()->DajX() - 1, this->DajPole()->DajY() + 1))
				{
					ZmienPozycje(this->DajWyspe()->Pola()[this->DajPole()->DajX() - 1][this->DajPole()->DajY() + 1]);
				}
				else if (this->DajWyspe()->CZyPoleJestNaWyspieIMoznaNaNieWejsc(this->DajPole()->DajX() + 1, this->DajPole()->DajY() + 1))
				{
					ZmienPozycje(this->DajWyspe()->Pola()[this->DajPole()->DajX() + 1][this->DajPole()->DajY() + 1]);
				}
				else if (this->DajWyspe()->CZyPoleJestNaWyspieIMoznaNaNieWejsc(this->DajPole()->DajX() - 1, this->DajPole()->DajY()))
				{
					ZmienPozycje(this->DajWyspe()->Pola()[this->DajPole()->DajX() - 1][this->DajPole()->DajY()]);
				}
				else if (this->DajWyspe()->CZyPoleJestNaWyspieIMoznaNaNieWejsc(this->DajPole()->DajX() + 1, this->DajPole()->DajY()))
				{
					ZmienPozycje(this->DajWyspe()->Pola()[this->DajPole()->DajX() + 1][this->DajPole()->DajY()]);
				}
				else if (this->DajWyspe()->CZyPoleJestNaWyspieIMoznaNaNieWejsc(this->DajPole()->DajX() - 1, this->DajPole()->DajY()) - 1)
				{
					ZmienPozycje(this->DajWyspe()->Pola()[this->DajPole()->DajX() - 1][this->DajPole()->DajY() - 1]);
				}
				else if (this->DajWyspe()->CZyPoleJestNaWyspieIMoznaNaNieWejsc(this->DajPole()->DajX() + 1, this->DajPole()->DajY() - 1))
				{
					ZmienPozycje(this->DajWyspe()->Pola()[this->DajPole()->DajX() + 1][this->DajPole()->DajY() - 1]);
				}
				
			}
		}
	}
}
