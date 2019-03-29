#include "stdafx.h"
#include "Wiewiorka.h"


CWiewiorka::CWiewiorka()
{
	inicialy = "Wi";
	nazwa = "Wiewiorka";
}


CWiewiorka::CWiewiorka(CPole* _ustawianapozycja, CWyspa* _ustawianawyspa, CGra* _gra) :CRoslinozerne(_ustawianapozycja, _ustawianawyspa), CZwierze(_ustawianapozycja, _ustawianawyspa)
{
	zycie = 20;
	max_zycie = 20;
	tluszcz = 45;
	max_tluszcz = 45;
	zakreswidzenia = 2;
	masa = 10;
	wspolczynnikzmniejszeniazycia = 1;
	maksymalnyczaspogonizacelrozmnazanie = 10;
	maksymalnyczaspogonizacelrozmnazanie = 20;
	wspolczynnikspalaniatluszczuprzyrozmnazaniu = 2;
	wspolczynnikspalaniatluszczuprzyruchu = 1;
	wspolczynnikplodnosci = 8;
	gra = _gra;
	inicialy = "Wi";
	nazwa = "Wiewiorka";
	//std::cout << " Konstruktor Wiewiorka" << std::endl; //debug
	zjadanerosliny.push_back(new COrzech);
}


CWiewiorka::~CWiewiorka()
{
	//std::cout << "Destruktor CWiewiorka" << std::endl;
}


CPole* CWiewiorka::RozmnazajSie()
{
	bool rozmnazajsie = false;
	for (int i = 0; i < zwierzetawpoluwidzenia.size(); i++)
	{
		if (Odleglosc(zwierzetawpoluwidzenia[i]) <= 1)
		{
			if (dynamic_cast<CWiewiorka*>(zwierzetawpoluwidzenia[i]))
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
				//polewidzenia[i]->WyswietlWspolrzedne();
				this->DajGre()->StworzWiewiorkeRozmnazanie(polewidzenia[i]);
				return polewidzenia[i];
			}
		}
	}
	return nullptr;
}

/*void CWiewiorka::ZmniejszTluszczRuch()
{
	if (tluszcz == 0)
	{
		this->ZmniejszZycie(wspolczynnikzmniejszeniazycia);
		std::cout << "Wywolaj funkcje smierci ......"; // napisz ja najpierw
	}
	else
	{
		tluszcz = tluszcz - 1;
		if (tluszcz < 0)
		{
			tluszcz = 0;
		}
	}
}*/

/*void CWiewiorka::UciekajRuch()
{
	CZwierze* pomocnicze = nullptr;
	for (int i = 0; i < zwierzetawpoluwidzenia.size(); i++)
	{
		if (dynamic_cast<CMiesozerne*>(zwierzetawpoluwidzenia[i]))
		{
			if ((this->Odleglosc(zwierzetawpoluwidzenia[i]) == 0) || (this->Odleglosc(zwierzetawpoluwidzenia[i]) == 1))
			{
				pomocnicze = zwierzetawpoluwidzenia[i];
			}
			else
			{
				pomocnicze = zwierzetawpoluwidzenia[i];
			}
		}
	}
	this->CRoslinozerne::UciekajPrzedMiesozernym();
}*/

/*void CWiewiorka::Uciekaj()
{
	this->UciekajRuch();
	this->UciekajRuch();		// czy te funkcje powinienm wywolywac ??
}*/


void CWiewiorka::Inicjalizacja()
{
	this->OdswiezPoleWidzenia();
	this->WyznaczKomponentyKtoreWidzisz();
	this->UzupelnijRoslinyWPoluWidzeniaDoZjedzenia();
	this->UstawCelRoslina();
	this->UstawCelRozmnazanie();
	this->ResetujCzasPogoniZaCelRozmnazanie();
}

void CWiewiorka::KoniecRundyOdswiezanie()
{
	this->OdswiezPoleWidzenia();
	this->WyznaczKomponentyKtoreWidzisz();
	this->UzupelnijRoslinyWPoluWidzeniaDoZjedzenia();
	this->OdswiezCelRozmnazanie();
	this->OdswiezCelRoslina();
}

void CWiewiorka::Zyj()
{
	if (!(this->CzyKomponentJestMartwy()))
	{
		if (this->DajTluszcz() > 20)
		{
			this->OdswiezPoleWidzenia();
			this->WyznaczKomponentyKtoreWidzisz();
			if (this->CzyMiesozernyJestWPoluWidzenia())
			{
				this->UciekajPrzedMiesozernym();
				this->OdswiezPoleWidzenia();
				this->WyznaczKomponentyKtoreWidzisz();
				this->UciekajPrzedMiesozernym();
			}
			else if ((this->DajCelRozmnazanie() != nullptr) && (!(this->DajCelRozmnazanie()->CzyKomponentJestMartwy())))
			{
				if (this->DajCzasPogoniZaCelRozmnazanie() > 0)
				{
					if (this->Odleglosc(this->DajCelRozmnazanie()) > 1)
					{
						this->CRuchome::IdzWKierunkuCelu(this->DajCelRozmnazanie());
						this->ZmniejszCzasPogoniZaCelRozmnazanie();
						this->CRuchome::IdzWKierunkuCelu(this->DajCelRozmnazanie());
						this->ZmniejszCzasPogoniZaCelRozmnazanie();
					}
					else
					{
						int wylosowanaliczba;
						wylosowanaliczba = (std::rand() % wspolczynnikplodnosci);
						if (wylosowanaliczba == 0)
						{
							int wylosowanaliczba2;
							wylosowanaliczba2 = (std::rand() % 2);
							if (wylosowanaliczba2 == 0)
							{
								this->RozmnazajSie();
								this->RozmnazajSie();
							}
							else
							{
								this->RozmnazajSie();
							}
							this->OdswiezPoleWidzenia();
							this->WyznaczKomponentyKtoreWidzisz();
							this->UsunCelRozmnaznie(); // usun ta linijke
							if (!(this->DajCelRozmnazanie()))
							{
								this->UstawCelRozmnazanie();
								this->ResetujCzasPogoniZaCelRozmnazanie();
							}
							//this->LosowyRuch(); // usun
						}
						this->ZmniejszTluszczRozmanzanie(); // nie tworzy potomka ale dochodzi do .....
					}
					this->OdswiezCelRozmnazanie();
				}
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
		else if (this->DajTluszcz() > 10)
		{
			this->OdswiezPoleWidzenia();
			this->WyznaczKomponentyKtoreWidzisz();
			if (this->CzyMiesozernyJestWPoluWidzenia())
			{
				this->UciekajPrzedMiesozernym();
				this->UciekajPrzedMiesozernym();
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
					//this->OdswiezCelZwierze(); // na wszelki wypadek tak naprawde dzieje sie w ZjedzZwierzeCel
					if (!(this->DajCelRoslina()))
					{
						this->UstawCelRoslina();
					}
				}
				else
				{
					this->IdzWKierunkuCelu(this->DajCelRoslina());
				}
				this->OdswiezCelRoslina(); ///
			}
			else
			{
				this->LosowyRuch();
				this->OdswiezPoleWidzenia();
				this->WyznaczKomponentyKtoreWidzisz();
				this->UzupelnijRoslinyWPoluWidzeniaDoZjedzenia();
				this->UstawCelRoslina();
			}
		}
	}
}