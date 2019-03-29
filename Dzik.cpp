#include "stdafx.h"
#include "Dzik.h"


CDzik::CDzik()
{
	inicialy = "Dz";
	nazwa = "Dzik";
}


CDzik::CDzik(CPole* _ustawianapozycja, CWyspa* _ustawianawyspa, CGra* _gra) :CRoslinozerne(_ustawianapozycja, _ustawianawyspa), CZwierze(_ustawianapozycja, _ustawianawyspa)
{
	zycie = 100;
	max_zycie = 100;
	tluszcz = 150;
	max_tluszcz = 150;
	zakreswidzenia = 3;
	masa = 60;
	maksymalnyczaspogonizacelrozmnazanie = 15;
	wspolczynnikspalaniatluszczuprzyrozmnazaniu = 33;
	wspolczynnikspalaniatluszczuprzyruchu = 8;
	wspolczynnikzmniejszeniazycia = 8;
	wspolczynnikplodnosci = 4;
	inicialy = "Dz";
	nazwa = "Dzik";
	gra = _gra;
	zjadanerosliny.push_back(new CTrawa);
	zjadanerosliny.push_back(new CMarchewka);
	zjadanerosliny.push_back(new COrzech);
}


CDzik::~CDzik()
{
	//std::cout << "Destruktor CDzik" << std::endl;
}



CPole* CDzik::RozmnazajSie()
{
	bool rozmnazajsie = false;
	for (int i = 0; i < zwierzetawpoluwidzenia.size(); i++)
	{
		if (Odleglosc(zwierzetawpoluwidzenia[i]) <= 1)
		{
			if (dynamic_cast<CDzik*>(zwierzetawpoluwidzenia[i]))
			{
				rozmnazajsie = true;
			}
		}
	}
	if (rozmnazajsie)
	{
		for (int i = 0; i < polewidzenia.size(); i++)
		{
			if ((polewidzenia[i]->DajKomponentyNaPolu().empty())) //jezeli pole jest puste mozna postawic na nim komponent
			{
				//polewidzenia[i]->WyswietlWspolrzedne(); //wyswietla wspolrzedne 
				this->DajGre()->StworzDzikaRozmnazanie(polewidzenia[i]);
				return polewidzenia[i];
			}
		}
	}
	return nullptr;
}


void CDzik::UciekajPrzedNiedzwiedziem()
{
	CZwierze* pomocnicze = nullptr;
	for (int i = 0; i < zwierzetawpoluwidzenia.size(); i++)
	{
		if (dynamic_cast<CNiedzwiedz*>(zwierzetawpoluwidzenia[i]))
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
	this->UciekajPrzed(pomocnicze);
}

void CDzik::Zyj()
{
	if (!(this->CzyKomponentJestMartwy()))
	{
		if (this->DajTluszcz() > 100)
		{
			this->OdswiezPoleWidzenia();
			this->WyznaczKomponentyKtoreWidzisz();
			if (this->CzyNiedzwiedzJestWPoluWidzenia())
			{
				this->UciekajPrzedNiedzwiedziem();
			}
			else if ((this->DajCelRozmnazanie() != nullptr) && (!(this->DajCelRozmnazanie()->CzyKomponentJestMartwy())))
			{
				if (this->DajCzasPogoniZaCelRozmnazanie() > 0)
				{
					if (this->Odleglosc(this->DajCelRozmnazanie()) >= 1)
					{
						this->IdzWKierunkuCelu(this->DajCelRozmnazanie());
						this->ZmniejszCzasPogoniZaCelRozmnazanie();
					}
					else
					{
						int wylosowanaliczba;
						wylosowanaliczba = (std::rand() % wspolczynnikplodnosci);
						if (wylosowanaliczba == 0)
						{
							this->RozmnazajSie();
							this->OdswiezPoleWidzenia();
							this->WyznaczKomponentyKtoreWidzisz();
							this->UsunCelRozmnaznie(); // usun ta linijke
							if (!(this->DajCelRozmnazanie()))
							{
								this->UstawCelRozmnazanie();
								this->ResetujCzasPogoniZaCelRozmnazanie();
							}
						}
						this->ZmniejszTluszczRozmanzanie();
					}
					this->OdswiezCelRozmnazanie();
				}
				else
				{
					this->OdswiezPoleWidzenia();
					this->WyznaczKomponentyKtoreWidzisz();
					this->UsunCelRozmnaznie(); // usun ta linijke
					if (!(this->DajCelRozmnazanie()))
					{
						this->UstawCelRozmnazanie();
						this->ResetujCzasPogoniZaCelRozmnazanie();
					}
					this->LosowyRuch();
				}
			}
			else
			{
				this->LosowyRuch();
			}
		}
		else if (this->DajTluszcz() > 60)
		{
			this->OdswiezPoleWidzenia();
			this->WyznaczKomponentyKtoreWidzisz();
			if (this->CzyMiesozernyJestWPoluWidzenia())
			{
				this->UciekajPrzedNiedzwiedziem();
			}
			else
			{
				this->LosowyRuch();
			}
		}
		else
		{
			if (this->DajCelRoslina())
			{
				if ((this->CzyRoslinaDoZjedzeniaJestWZasiegu()) && (!(this->DajCelRoslina()->CzyKomponentJestMartwy())))
				{
					this->ZjedzRoslinaCel();
					this->OdswiezPoleWidzenia();
					this->WyznaczKomponentyKtoreWidzisz();
					this->UzupelnijRoslinyWPoluWidzeniaDoZjedzenia();
					if (!(this->DajCelRoslina()))
					{
						this->UstawCelRoslina();
						this->ResetujCzasPogoniZaCelRozmnazanie();
					}
				}
				else
				{
					this->IdzWKierunkuCelu(this->DajCelRoslina());
				}
				this->OdswiezCelRoslina();
			}
			else
			{
				this->LosowyRuch();
				this->OdswiezPoleWidzenia();
				this->WyznaczKomponentyKtoreWidzisz();
				this->UzupelnijRoslinyWPoluWidzeniaDoZjedzenia();
				this->UstawCelRoslina();
			}
			this->LosowyRuch();
		}
	}
}

void CDzik::KoniecRundyOdswiezanie()
{
	this->OdswiezPoleWidzenia();
	this->WyznaczKomponentyKtoreWidzisz();
	this->UzupelnijRoslinyWPoluWidzeniaDoZjedzenia();
	this->OdswiezCelRozmnazanie();
	this->OdswiezCelRoslina();
}
void CDzik::Inicjalizacja()
{
	this->OdswiezPoleWidzenia();
	this->WyznaczKomponentyKtoreWidzisz();
	this->UzupelnijRoslinyWPoluWidzeniaDoZjedzenia();
	this->UstawCelRoslina();
	this->UstawCelRozmnazanie();
	this->ResetujCzasPogoniZaCelRozmnazanie(); // odkomentowane
}


bool CDzik::CzyNiedzwiedzJestWPoluWidzenia()
{
	for (int i = 0; i < zwierzetawpoluwidzenia.size(); i++)
	{
		if (dynamic_cast<CNiedzwiedz*>(zwierzetawpoluwidzenia[i]))
		{
			if ((this->Odleglosc(zwierzetawpoluwidzenia[i]) <= this->DajZakresWidzenia()))  //zakres widzenia
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		return false;
	}
	return false;
}