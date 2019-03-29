#include "stdafx.h"
#include "Owca.h"


COwca::COwca()
{
	inicialy = "Ow";
	nazwa = "Owca";
}


COwca::COwca(CPole* _ustawianapozycja, CWyspa* _ustawianawyspa, CGra* _gra) :CRoslinozerne(_ustawianapozycja, _ustawianawyspa), CZwierze(_ustawianapozycja, _ustawianawyspa)
{
	zycie = 30;
	max_zycie = 30;
	tluszcz = 120;
	max_tluszcz = 120;
	zakreswidzenia = 2;
	masa = 40;
	maksymalnyczaspogonizacelrozmnazanie = 16;
	wspolczynnikspalaniatluszczuprzyrozmnazaniu = 37;
	wspolczynnikspalaniatluszczuprzyruchu = 4;
	wspolczynnikzmniejszeniazycia = 4;
	wspolczynnikplodnosci = 3;
	gra = _gra;
	inicialy = "Ow";
	nazwa = "Owca";
	zjadanerosliny.push_back(new CTrawa);
}


COwca::~COwca()
{
	//std::cout << "Destruktor COwca" << std::endl; //debag
}




CPole* COwca::RozmnazajSie()
{
	bool rozmnazajsie = false;
	for (int i = 0; i < zwierzetawpoluwidzenia.size(); i++)
	{
		if (Odleglosc(zwierzetawpoluwidzenia[i]) <= 1)
		{
			if (dynamic_cast<COwca*>(zwierzetawpoluwidzenia[i]))
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
				this->DajGre()->StworzOwceRozmnazanie(polewidzenia[i]);
				return polewidzenia[i];
			}
		}
	}
	return nullptr;
}

/*void COwca::ZmniejszTluszczRuch()
{
	if (tluszcz == 0)
	{
		this->ZmniejszZycie(this->DajWspoczynnikZmniejszeniaZycia());
		std::cout << "Wywolaj funkcje smierci ......"; // napisz ja najpierw
	}
	else
	{
		tluszcz = tluszcz - 2;
		if (tluszcz < 0)
		{
			tluszcz = 0;
		}
	}
}*/


/*void COwca::Zyj()
{
	if (!(this->CzyKomponentJestMartwy()))
	{
		if (this->DajTluszcz() > 80)
		{
			this->OdswiezPoleWidzenia();
			this->WyznaczKomponentyKtoreWidzisz();
			this->Uciekaj();
		}
		else if (this->DajTluszcz() > 25)
		{
			this->OdswiezPoleWidzenia();
			this->WyznaczKomponentyKtoreWidzisz();
			if ((this->DajCelRozmnazanie() != nullptr) && (!(this->DajCelRozmnazanie()->CzyKomponentJestMartwy())))
			{
				if (this->DajCzasPogoniZaCelRozmnazanie() > 0)
				{
					if (this->Odleglosc(this->DajCelRozmnazanie()) > 1)
					{
						this->CRuchome::IdzWKierunkuCelu(this->DajCelRozmnazanie());
						this->ZmniejszCzasPogoniZaCelRozmnazanie();
					}
					else
					{
						int wylosowanaliczba;
						wylosowanaliczba = (std::rand() % 200);
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
							//this->LosowyRuch(); // usun
						}
						this->ZmniejszTluszczRozmanzanie(); // nie tworzy potomka ale dochodzi do .....
					}
					this->OdswiezCelRozmnazanie();
				}
			}
			else if (this->CzyMiesozernyJestWPoluWidzenia())
			{
				this->Uciekaj();
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
					//std::cout << "Komponent Zjedzony" << std::endl;
					this->OdswiezPoleWidzenia();
					this->WyznaczKomponentyKtoreWidzisz();
					this->UzupelnijRoslinyWPoluWidzeniaDoZjedzenia();
					//this->OdswiezCelZwierze(); // na wszelki wypadek tak naprawde dzieje sie w ZjedzZwierzeCel
					if (!(this->DajCelRoslina()))
					{
						this->UstawCelRoslina();
						this->ResetujCzasPogoniZaCelRozmnazanie();
					}
				}
				else
				{
					this->IdzWKierunkuCelu(this->DajCelRoslina());
					//this->IdzWKierunkuCelu(); //skasuj
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
}*/

void COwca::Inicjalizacja()
{
	this->OdswiezPoleWidzenia();
	this->WyznaczKomponentyKtoreWidzisz();
	this->UzupelnijRoslinyWPoluWidzeniaDoZjedzenia();
	this->UstawCelRoslina();
	this->UstawCelRozmnazanie();
	this->ResetujCzasPogoniZaCelRozmnazanie();
}

void COwca::KoniecRundyOdswiezanie()
{
	this->OdswiezPoleWidzenia();
	this->WyznaczKomponentyKtoreWidzisz();
	this->UzupelnijRoslinyWPoluWidzeniaDoZjedzenia();
	this->OdswiezCelRozmnazanie();
	this->OdswiezCelRoslina();
}

void COwca::Zyj()
{
	if (!(this->CzyKomponentJestMartwy()))
	{
		if (this->DajTluszcz() > 80)
		{
			this->OdswiezPoleWidzenia();
			this->WyznaczKomponentyKtoreWidzisz();
			if (this->CzyMiesozernyJestWPoluWidzenia())
			{
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
							//this->LosowyRuch(); // usun
						}
						this->ZmniejszTluszczRozmanzanie(); // nie tworzy potomka ale dochodzi do .....
					}
					this->OdswiezCelRozmnazanie();
				}
			}
			else
			{
				this->LosowyRuch();
			}
		}
		else if(this->DajTluszcz() > 25)
		{
			this->OdswiezPoleWidzenia();
			this->WyznaczKomponentyKtoreWidzisz();
			if (this->CzyMiesozernyJestWPoluWidzenia())
			{
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
		}
	}
}