#include "stdafx.h"
#include "Miesozerne.h"


CMiesozerne::CMiesozerne()
{
	celzwierze = nullptr;
}


CMiesozerne::CMiesozerne(CPole* _ustawianapozycja, CWyspa* _ustawianawyspa) : CZwierze(_ustawianapozycja, _ustawianawyspa)
{
	celzwierze = nullptr;
}


CMiesozerne::~CMiesozerne()
{
	for (int i = 0; i < zjadanezwierzeta.size(); i++)
	{
		delete zjadanezwierzeta[i];
	}
	//std::cout << "Destruktor CMiesozerny" << std::endl;
}

void CMiesozerne::UzupelnijZwierzetaWPoluWidzeniaDoZjedzenia()
{
	if (!zwierzetawpoluwidzeniadozjedzenia.empty())
	{
		zwierzetawpoluwidzeniadozjedzenia.clear();
	}
	for (auto i : zwierzetawpoluwidzenia)
	{
		for (int j = 0; j < zjadanezwierzeta.size(); j++)
		{
			if (i->DajNazwe() == zjadanezwierzeta[j]->DajNazwe())
			{
				zwierzetawpoluwidzeniadozjedzenia.push_back(i);
				//std::cout << i->DajNazwe(); // debug
			}
		}
	}
}

void CMiesozerne::WyswietlCelZwierze()
{
	if (this->DajCelZwierze())
	{
		celzwierze->DajPozycje();
		std::cout << celzwierze->DajNazwe() << std::endl;
		std::cout << "celzwierze istnieje" << std::endl;
	}
	else
	{
		std::cout << "Nie mam aktualnie celzwierze" << std::endl;
	}
}

void CMiesozerne::IdzWKierunkuCelZwierze()
{
	//std::cout << "Czy cel istenieje";
	if (this->DajCelZwierze() != nullptr)
	{
		if (this->DajCelZwierze()->DajPole()->DajX() > this->DajPole()->DajX())
		{
			if (this->DajCelZwierze()->DajPole()->DajY() > this->DajPole()->DajY())
			{
				if (this->DajWyspe()->CZyPoleJestNaWyspieIMoznaNaNieWejsc(this->DajPole()->DajX() + 1, this->DajPole()->DajY() + 1))
				{
					ZmienPozycje(this->DajWyspe()->Pola()[this->DajPole()->DajX() + 1][this->DajPole()->DajY() + 1]);
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
			else if (this->DajCelZwierze()->DajPole()->DajY() < this->DajPole()->DajY())
			{
				if (this->DajWyspe()->CZyPoleJestNaWyspieIMoznaNaNieWejsc(this->DajPole()->DajX() + 1, this->DajPole()->DajY() - 1))
				{
					ZmienPozycje(this->DajWyspe()->Pola()[this->DajPole()->DajX() + 1][this->DajPole()->DajY() - 1]);
				}
				else if (this->DajWyspe()->CZyPoleJestNaWyspieIMoznaNaNieWejsc(this->DajPole()->DajX() + 1, this->DajPole()->DajY()))
				{
					ZmienPozycje(this->DajWyspe()->Pola()[this->DajPole()->DajX() + 1][this->DajPole()->DajY()]);
				}
				else if (this->DajWyspe()->CZyPoleJestNaWyspieIMoznaNaNieWejsc(this->DajPole()->DajX(), this->DajPole()->DajY() - 1))
				{
					ZmienPozycje(this->DajWyspe()->Pola()[this->DajPole()->DajX()][this->DajPole()->DajY() - 1]);
				}
			}
			else
			{
				if (this->DajWyspe()->CZyPoleJestNaWyspieIMoznaNaNieWejsc(this->DajPole()->DajX() + 1, this->DajPole()->DajY()))
				{
					ZmienPozycje(this->DajWyspe()->Pola()[this->DajPole()->DajX() + 1][this->DajPole()->DajY()]);
				}
				else if (this->DajWyspe()->CZyPoleJestNaWyspieIMoznaNaNieWejsc(this->DajPole()->DajX() + 1, this->DajPole()->DajY() - 1))
				{
					ZmienPozycje(this->DajWyspe()->Pola()[this->DajPole()->DajX() + 1][this->DajPole()->DajY() - 1]);
				}
				else if (this->DajWyspe()->CZyPoleJestNaWyspieIMoznaNaNieWejsc(this->DajPole()->DajX() + 1, this->DajPole()->DajY() + 1))
				{
					ZmienPozycje(this->DajWyspe()->Pola()[this->DajPole()->DajX() + 1][this->DajPole()->DajY() + 1]);
				}
			}
		}
		else if (this->DajCelZwierze()->DajPole()->DajX() < this->DajPole()->DajX())
		{
			if (this->DajCelZwierze()->DajPole()->DajY() > this->DajPole()->DajY())
			{
				if (this->DajWyspe()->CZyPoleJestNaWyspieIMoznaNaNieWejsc(this->DajPole()->DajX() - 1, this->DajPole()->DajY() + 1))
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
			}
			else if (this->DajCelZwierze()->DajPole()->DajY() < this->DajPole()->DajY())
			{
				if (this->DajWyspe()->CZyPoleJestNaWyspieIMoznaNaNieWejsc(this->DajPole()->DajX() - 1, this->DajPole()->DajY() - 1))
				{
					ZmienPozycje(this->DajWyspe()->Pola()[this->DajPole()->DajX() - 1][this->DajPole()->DajY() - 1]);
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
			else
			{
				if (this->DajWyspe()->CZyPoleJestNaWyspieIMoznaNaNieWejsc(this->DajPole()->DajX() - 1, this->DajPole()->DajY()))
				{
					ZmienPozycje(this->DajWyspe()->Pola()[this->DajPole()->DajX() - 1][this->DajPole()->DajY()]);
				}
				else if (this->DajWyspe()->CZyPoleJestNaWyspieIMoznaNaNieWejsc(this->DajPole()->DajX() - 1, this->DajPole()->DajY() - 1))
				{
					ZmienPozycje(this->DajWyspe()->Pola()[this->DajPole()->DajX() - 1][this->DajPole()->DajY() - 1]);
				}
				else if (this->DajWyspe()->CZyPoleJestNaWyspieIMoznaNaNieWejsc(this->DajPole()->DajX() + 1, this->DajPole()->DajY() + 1))
				{
					ZmienPozycje(this->DajWyspe()->Pola()[this->DajPole()->DajX() - 1][this->DajPole()->DajY() + 1]);
				}
			}
		}
		else
		{
			if (this->DajCelZwierze()->DajPole()->DajY() > this->DajPole()->DajY())
			{
				if (this->DajWyspe()->CZyPoleJestNaWyspieIMoznaNaNieWejsc(this->DajPole()->DajX(), this->DajPole()->DajY() + 1))
				{
					ZmienPozycje(this->DajWyspe()->Pola()[this->DajPole()->DajX()][this->DajPole()->DajY() + 1]);
				}
				else if (this->DajWyspe()->CZyPoleJestNaWyspieIMoznaNaNieWejsc(this->DajPole()->DajX() + 1, this->DajPole()->DajY() + 1))
				{
					ZmienPozycje(this->DajWyspe()->Pola()[this->DajPole()->DajX() + 1][this->DajPole()->DajY() + 1]);
				}
				else if (this->DajWyspe()->CZyPoleJestNaWyspieIMoznaNaNieWejsc(this->DajPole()->DajX() - 1, this->DajPole()->DajY() + 1))
				{
					ZmienPozycje(this->DajWyspe()->Pola()[this->DajPole()->DajX() - 1][this->DajPole()->DajY() + 1]);
				}
			}
			else if (this->DajCelZwierze()->DajPole()->DajY() < this->DajPole()->DajY())
			{
				if (this->DajWyspe()->CZyPoleJestNaWyspieIMoznaNaNieWejsc(this->DajPole()->DajX(), this->DajPole()->DajY() - 1))
				{
					ZmienPozycje(this->DajWyspe()->Pola()[this->DajPole()->DajX()][this->DajPole()->DajY() - 1]);
				}
				else if (this->DajWyspe()->CZyPoleJestNaWyspieIMoznaNaNieWejsc(this->DajPole()->DajX() + 1, this->DajPole()->DajY() - 1))
				{
					ZmienPozycje(this->DajWyspe()->Pola()[this->DajPole()->DajX() + 1][this->DajPole()->DajY() - 1]);
				}
				else if (this->DajWyspe()->CZyPoleJestNaWyspieIMoznaNaNieWejsc(this->DajPole()->DajX() - 1, this->DajPole()->DajY() - 1))
				{
					ZmienPozycje(this->DajWyspe()->Pola()[this->DajPole()->DajX() - 1][this->DajPole()->DajY() - 1]);
				}
			}
		}
	}
}

CKomponentEkoSystemu* CMiesozerne::ZjedzZwierzeCel()
{
	if (this->DajCelZwierze())  // celzwierze
	{
		if (this->Odleglosc(this->DajCelZwierze()) <= 1)  //celzwierz
		{
			//std::cout << " Dodaj tluszcz" << std::endl; //debag
			if (this->DajCelZwierze()->DajMase() < 20)
			{
				this->DodajTluszcz(18);
			}
			else if (this->DajCelZwierze()->DajMase() < 40)
			{
				this->DodajTluszcz(35);
			}
			else
			{
				this->DodajTluszcz(55);
			}
			auto iterator = std::find_if(zwierzetawpoluwidzeniadozjedzenia.begin(), zwierzetawpoluwidzeniadozjedzenia.end(),
				[&](CZwierze* _komponent1)
			{
				return _komponent1 == this->DajCelZwierze();  //celzwierze
			});
			(*iterator)->UstawMartwy();
			this->UsunCelZwierze();
			return this->DajCelZwierze();
		}
		return nullptr;
	}
	return nullptr;
}

CZwierze* CMiesozerne::DajCelZwierze()
{
	if (celzwierze != nullptr)
	{
		return celzwierze;
	}
	else
	{
		return nullptr;
	}
}

void CMiesozerne::OdswiezCelZwierze()
{
	if (this->DajCelZwierze()) //celzwierze - nie mozna zamienic
	{
		if (celzwierze->CzyKomponentJestMartwy())
		{
			celzwierze = nullptr;
		}
	}
}

bool CMiesozerne::CzyZwierzeDoZjedzeniaJestWZasiegu()
{
	if (this->DajCelZwierze() != nullptr)
	{
		if (this->Odleglosc(this->DajCelZwierze()) <= 1) //celzwierze ?
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

void CMiesozerne::UsunCelZwierze()
{
	if (celzwierze != nullptr)
	{
		celzwierze = nullptr;
	}
}

bool CMiesozerne::SprawdzCzyMaszCelZwierze()
{
	if (celzwierze != nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int CMiesozerne::DajCzasPogoniZaCelZwierze()
{
	return czaspogonizacelzwierze;
}

void CMiesozerne::ZmniejszCzasPogoniZaCelZwierze()
{
	if (czaspogonizacelzwierze > 0)
	{
		czaspogonizacelzwierze = czaspogonizacelzwierze - 1;
	}
	else
	{
		czaspogonizacelzwierze = 0;
	}
}

void CMiesozerne::ResetujCzasPogoniZaCelZwierze()
{
	czaspogonizacelzwierze = maksymalnyczaspogonizacelzwierze;
}

void CMiesozerne::UstawCelZwierze()
{
	if (!zwierzetawpoluwidzeniadozjedzenia.empty())
	{
		celzwierze = zwierzetawpoluwidzeniadozjedzenia[0];
	}
	else
	{
		celzwierze = nullptr;
	}
	for (auto i : zwierzetawpoluwidzeniadozjedzenia)
	{
		if (celzwierze != nullptr)
		{
			if (i->DajMase() < celzwierze->DajMase())  //jesli znajdzie zwierze z mniejsza masa na ktore moze polowac zmienia cel
			{
				celzwierze = i;
			}
		}
	}
}

