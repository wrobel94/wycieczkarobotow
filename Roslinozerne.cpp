#include "stdafx.h"
#include "Roslinozerne.h"


CRoslinozerne::CRoslinozerne()
{
}


CRoslinozerne::CRoslinozerne(CPole* _ustawianapozycja, CWyspa* _ustawianawyspa) : CZwierze(_ustawianapozycja, _ustawianawyspa)
{

}


CRoslinozerne::~CRoslinozerne()
{
	for (int i = 0; i < zjadanerosliny.size(); i++)
	{
		delete zjadanerosliny[i];
	}
	//std::cout << "Destruktor CRoslinozerne" << std::endl;
}

void CRoslinozerne::UzupelnijRoslinyWPoluWidzeniaDoZjedzenia()
{
	if (!(roslinywpoluwidzeniadozjedzenia.empty()))
	{
		roslinywpoluwidzeniadozjedzenia.clear();
	}
	for (auto i : roslinywpoluwidzenia)
	{
		for (int j = 0; j < zjadanerosliny.size(); j++)
		{
			if (i->DajNazwe() == zjadanerosliny[j]->DajNazwe())
			{
				roslinywpoluwidzeniadozjedzenia.push_back(i);
			}
		}
	}
}

/*void CRoslinozerne::UciekajPrzedMiesozenym(CZwierze* _atakujacy)
{
	if (_atakujacy)
	{
		if (_atakujacy->DajPole()->DajX() > this->DajPole()->DajX())
		{
			if (_atakujacy->DajPole()->DajY() > this->DajPole()->DajY())
			{
				if (this->DajWyspe()->CzyPoleJestNaWyspie(this->DajPole()->DajX() - 1, this->DajPole()->DajY() - 1))
				{
					ZmienPozycje(this->DajWyspe()->Pola()[this->DajPole()->DajX() - 1][this->DajPole()->DajY() - 1]);
				}
				else
				{
					if (this->DajWyspe()->CzyPoleJestNaWyspie(this->DajPole()->DajX() + 1, this->DajPole()->DajY() - 1))
					{
						ZmienPozycje(this->DajWyspe()->Pola()[this->DajPole()->DajX() + 1][this->DajPole()->DajY() - 1]);
					}
					else
					{
						if (this->DajWyspe()->CzyPoleJestNaWyspie(this->DajPole()->DajX() - 1, this->DajPole()->DajY() + 1))
						{
							ZmienPozycje(this->DajWyspe()->Pola()[this->DajPole()->DajX() - 1][this->DajPole()->DajY() + 1]);
						}
						else
						{
							if (this->DajWyspe()->CzyPoleJestNaWyspie(this->DajPole()->DajX() - 1, this->DajPole()->DajY()))
							{
								ZmienPozycje(this->DajWyspe()->Pola()[this->DajPole()->DajX() - 1][this->DajPole()->DajY()]);
							}
							else
							{
								if (this->DajWyspe()->CzyPoleJestNaWyspie(this->DajPole()->DajX() + 1, this->DajPole()->DajY()))
								{
									ZmienPozycje(this->DajWyspe()->Pola()[this->DajPole()->DajX() + 1][this->DajPole()->DajY()]);
								}
							}
						}
					}
				}
			}
			else if (_atakujacy->DajPole()->DajY() < this->DajPole()->DajY())
			{
				if (this->DajWyspe()->CzyPoleJestNaWyspie(this->DajPole()->DajX() - 1, this->DajPole()->DajY() + 1))
				{
					ZmienPozycje(this->DajWyspe()->Pola()[this->DajPole()->DajX() - 1][this->DajPole()->DajY() + 1]);
				}
				else
				{
					if (this->DajWyspe()->CzyPoleJestNaWyspie(this->DajPole()->DajX() + 1, this->DajPole()->DajY() + 1))
					{
						ZmienPozycje(this->DajWyspe()->Pola()[this->DajPole()->DajX() + 1][this->DajPole()->DajY() + 1]);
					}
					else
					{
						if (this->DajWyspe()->CzyPoleJestNaWyspie(this->DajPole()->DajX() + 1, this->DajPole()->DajY()))
						{
							ZmienPozycje(this->DajWyspe()->Pola()[this->DajPole()->DajX() + 1][this->DajPole()->DajY()]);
						}
						else
						{
							if (this->DajWyspe()->CzyPoleJestNaWyspie(this->DajPole()->DajX() - 1, this->DajPole()->DajY()))
							{
								ZmienPozycje(this->DajWyspe()->Pola()[this->DajPole()->DajX() - 1][this->DajPole()->DajY()]);
							}
						}
					}
				}
			}
			else
			{
				if (this->DajWyspe()->CzyPoleJestNaWyspie(this->DajPole()->DajX() - 1, this->DajPole()->DajY()))
				{
					ZmienPozycje(this->DajWyspe()->Pola()[this->DajPole()->DajX() - 1][this->DajPole()->DajY()]);
				}
				else
				{
					if (this->DajWyspe()->CzyPoleJestNaWyspie(this->DajPole()->DajX(), this->DajPole()->DajY() + 1))
					{
						ZmienPozycje(this->DajWyspe()->Pola()[this->DajPole()->DajX()][this->DajPole()->DajY() + 1]);
					}
					else
					{
						if (this->DajWyspe()->CzyPoleJestNaWyspie(this->DajPole()->DajX(), this->DajPole()->DajY() - 1))
						{
							ZmienPozycje(this->DajWyspe()->Pola()[this->DajPole()->DajX()][this->DajPole()->DajY() - 1]);
						}
					}

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
				else
				{
					if (this->DajWyspe()->CzyPoleJestNaWyspie(this->DajPole()->DajX() + 1, this->DajPole()->DajY() + 1))
					{
						ZmienPozycje(this->DajWyspe()->Pola()[this->DajPole()->DajX() + 1][this->DajPole()->DajY() + 1]);
					}
					else
					{
						if (this->DajWyspe()->CzyPoleJestNaWyspie(this->DajPole()->DajX() + 1, this->DajPole()->DajY()))
						{
							ZmienPozycje(this->DajWyspe()->Pola()[this->DajPole()->DajX() + 1][this->DajPole()->DajY()]);
						}
						else
						{
							if (this->DajWyspe()->CzyPoleJestNaWyspie(this->DajPole()->DajX() - 1, this->DajPole()->DajY()))
							{
								ZmienPozycje(this->DajWyspe()->Pola()[this->DajPole()->DajX() - 1][this->DajPole()->DajY()]);
							}
						}
					}

				}
			}
			else if (_atakujacy->DajPole()->DajY() < this->DajPole()->DajY())
			{
				if (this->DajWyspe()->CzyPoleJestNaWyspie(this->DajPole()->DajX() + 1, this->DajPole()->DajY() + 1))
				{
					ZmienPozycje(this->DajWyspe()->Pola()[this->DajPole()->DajX() + 1][this->DajPole()->DajY() + 1]);
				}
				else
				{
					if (this->DajWyspe()->CzyPoleJestNaWyspie(this->DajPole()->DajX() + 1, this->DajPole()->DajY() - 1))
					{
						ZmienPozycje(this->DajWyspe()->Pola()[this->DajPole()->DajX() + 1][this->DajPole()->DajY() - 1]);
					}
					else
					{
						if (this->DajWyspe()->CzyPoleJestNaWyspie(this->DajPole()->DajX() + 1, this->DajPole()->DajY()))
						{
							ZmienPozycje(this->DajWyspe()->Pola()[this->DajPole()->DajX() + 1][this->DajPole()->DajY()]);
						}
						else
						{
							if (this->DajWyspe()->CzyPoleJestNaWyspie(this->DajPole()->DajX() - 1, this->DajPole()->DajY()))
							{
								ZmienPozycje(this->DajWyspe()->Pola()[this->DajPole()->DajX() - 1][this->DajPole()->DajY()]);
							}
							else
							{
								if (this->DajWyspe()->CzyPoleJestNaWyspie(this->DajPole()->DajX(), this->DajPole()->DajY() - 1))
								{
									ZmienPozycje(this->DajWyspe()->Pola()[this->DajPole()->DajX()][this->DajPole()->DajY() - 1]);
								}
							}
						}
					}
				}
			}
			else
			{
				if (this->DajWyspe()->CzyPoleJestNaWyspie(this->DajPole()->DajX() + 1, this->DajPole()->DajY()))
				{
					ZmienPozycje(this->DajWyspe()->Pola()[this->DajPole()->DajX() + 1][this->DajPole()->DajY()]);
				}
				else
				{
					if (this->DajWyspe()->CzyPoleJestNaWyspie(this->DajPole()->DajX(), this->DajPole()->DajY() - 1))
					{
						ZmienPozycje(this->DajWyspe()->Pola()[this->DajPole()->DajX()][this->DajPole()->DajY() - 1]);
					}
					else
					{
						if (this->DajWyspe()->CzyPoleJestNaWyspie(this->DajPole()->DajX(), this->DajPole()->DajY() + 1))
						{
							ZmienPozycje(this->DajWyspe()->Pola()[this->DajPole()->DajX()][this->DajPole()->DajY() + 1]);
						}
					}
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
				else
				{
					if (this->DajWyspe()->CzyPoleJestNaWyspie(this->DajPole()->DajX() + 1, this->DajPole()->DajY() - 1))
					{
						ZmienPozycje(this->DajWyspe()->Pola()[this->DajPole()->DajX() + 1][this->DajPole()->DajY() - 1]);
					}
					else
					{
						if (this->DajWyspe()->CzyPoleJestNaWyspie(this->DajPole()->DajX() + 1, this->DajPole()->DajY()))
						{
							ZmienPozycje(this->DajWyspe()->Pola()[this->DajPole()->DajX() + 1][this->DajPole()->DajY()]);
						}
						else
						{
							if (this->DajWyspe()->CzyPoleJestNaWyspie(this->DajPole()->DajX() - 1, this->DajPole()->DajY()))
							{
								ZmienPozycje(this->DajWyspe()->Pola()[this->DajPole()->DajX() - 1][this->DajPole()->DajY()]);
							}
						}
					}
				}
			}
			else if (_atakujacy->DajPole()->DajY() < this->DajPole()->DajY())
			{
				if (this->DajWyspe()->CzyPoleJestNaWyspie(this->DajPole()->DajX(), this->DajPole()->DajY() + 1))
				{
					ZmienPozycje(this->DajWyspe()->Pola()[this->DajPole()->DajX()][this->DajPole()->DajY() + 1]);
				}
				else
				{
					if (this->DajWyspe()->CzyPoleJestNaWyspie(this->DajPole()->DajX() - 1, this->DajPole()->DajY() + 1))
					{
						ZmienPozycje(this->DajWyspe()->Pola()[this->DajPole()->DajX() - 1][this->DajPole()->DajY() + 1]);
					}
					else
					{
						if (this->DajWyspe()->CzyPoleJestNaWyspie(this->DajPole()->DajX() + 1, this->DajPole()->DajY() + 1))
						{
							ZmienPozycje(this->DajWyspe()->Pola()[this->DajPole()->DajX() + 1][this->DajPole()->DajY() + 1]);
						}
						else
						{
							if (this->DajWyspe()->CzyPoleJestNaWyspie(this->DajPole()->DajX() + 1, this->DajPole()->DajY()))
							{
								ZmienPozycje(this->DajWyspe()->Pola()[this->DajPole()->DajX() + 1][this->DajPole()->DajY()]);
							}
							else
							{
								if (this->DajWyspe()->CzyPoleJestNaWyspie(this->DajPole()->DajX() - 1, this->DajPole()->DajY()))
								{
									ZmienPozycje(this->DajWyspe()->Pola()[this->DajPole()->DajX() - 1][this->DajPole()->DajY()]);
								}
							}
						}
					}
				}
			}
		}
	}
}*/

void CRoslinozerne::UciekajPrzedMiesozernym()
{
	CZwierze* pomocnicze = nullptr;
	for (int i = 0; i < zwierzetawpoluwidzenia.size(); i++)
	{
		if (dynamic_cast<CMiesozerne*>(zwierzetawpoluwidzenia[i]))
		{
			if ((this->Odleglosc(zwierzetawpoluwidzenia[i]) <= this->DajZakresWidzenia())) //ucieka jesli tylko zobaczy cos w polu widzenia
			{
				pomocnicze = zwierzetawpoluwidzenia[i];
			}
			else
			{
				pomocnicze = zwierzetawpoluwidzenia[i];
			}
		}
	}
	if (pomocnicze != nullptr)
	{
		this->UciekajPrzed(pomocnicze);
	}
	//this->UciekajPrzedMiesozenym(pomocnicze);  // przepisana jako this->UciekajPrzed(pomocnicze);
	if (pomocnicze == nullptr)
	{
		delete pomocnicze; // czy to jest zasadne
	}
}

bool CRoslinozerne::CzyMiesozernyJestWPoluWidzenia()
{
	//CZwierze* pomocnicze = nullptr;
	for (int i = 0; i < zwierzetawpoluwidzenia.size(); i++)
	{
		if (dynamic_cast<CMiesozerne*>(zwierzetawpoluwidzenia[i]))
		{
			if ((this->Odleglosc(zwierzetawpoluwidzenia[i]) <= this->DajZakresWidzenia()))
			{
				return true;
				//pomocnicze = zwierzetawpoluwidzenia[i];
			}
			else
			{
				return false;
				//pomocnicze = zwierzetawpoluwidzenia[i];
			}
		}
		return false;
	}
	return false;
	//this->UciekajPrzedMiesozenym(pomocnicze);
	//if (pomocnicze == nullptr)
	//{
		//delete pomocnicze; // czy to jest zasadne
	//}
}

void CRoslinozerne::UsunCelRoslina()
{
	if (this->DajCelRoslina() != nullptr)
	{
		celroslina = nullptr;
	}
}

bool CRoslinozerne::SprawdzCzyMaszCelRoslina()
{
	if (this->DajCelRoslina() != nullptr)
	{
		std::cout << "TRUE" << std::endl;
		return true;
	}
	else
	{
		std::cout << "FALSE" << std::endl;
		return false;
	}
}

bool CRoslinozerne::CzyRoslinaDoZjedzeniaJestWZasiegu()
{
	if (this->DajCelRoslina() != nullptr)
	{
		if (this->Odleglosc(this->DajCelRoslina()) == 0) // odleglosc od rosliny aby ja zjesc
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

void CRoslinozerne::OdswiezCelRoslina()
{
	if (this->DajCelRoslina())
	{
		if (this->DajCelRoslina()->CzyKomponentJestMartwy())
		{
			celroslina = nullptr;
		}
	}
}

CRoslina* CRoslinozerne::DajCelRoslina()
{
	if (celroslina != nullptr)
	{
		return celroslina;
	}
	else
	{
		return nullptr;
	}
}


void CRoslinozerne::UstawCelRoslina()
{
	if (!roslinywpoluwidzeniadozjedzenia.empty())
	{
		celroslina = roslinywpoluwidzeniadozjedzenia[0];
		//std::cout << " srutututu";
	}
	else
	{
		celroslina = nullptr;
	}
	//celzwierze = nullptr;
	for (auto i : roslinywpoluwidzeniadozjedzenia)
	{
		if (this->DajCelRoslina())
		{
			if (this->Odleglosc(i) < this->Odleglosc(this->DajCelRoslina()))
			{
				celroslina = i;
			}
		}
	}
	//celzwierze->DajPozycje();
}

CKomponentEkoSystemu* CRoslinozerne::ZjedzRoslinaCel()
{
	if (this->DajCelRoslina())
	{
		if (this->Odleglosc(this->DajCelRoslina()) == 0)
		{
			this->DodajTluszcz(this->DajCelRoslina()->DajKalorycznosc());  //dodaje tluszcz zwierzakowi ktory zjadl rosline
			auto iterator = std::find_if(roslinywpoluwidzeniadozjedzenia.begin(), roslinywpoluwidzeniadozjedzenia.end(),
				[&](CRoslina* _komponent1)
			{
				return _komponent1 == this->DajCelRoslina(); //_komponent1 == pomocniczy;
			});
			(*iterator)->UstawMartwy(); // ustawia na marwta rosline ktora zostala zjedzona
			this->UsunCelRoslina();
			return this->DajCelRoslina();
		}
		return nullptr;
	}
	return nullptr;
}