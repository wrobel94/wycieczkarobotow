#include "stdafx.h"
#include "Niedzwiedz.h"


CNiedzwiedz::CNiedzwiedz()
{
	inicialy = "Ni";
	nazwa = "Niedzwiedz";
}


CNiedzwiedz::CNiedzwiedz(CPole* _ustawianapozycja, CWyspa* _ustawianawyspa, CGra* _gra) :CMiesozerne(_ustawianapozycja, _ustawianawyspa), CRoslinozerne(_ustawianapozycja, _ustawianawyspa), CZwierze(_ustawianapozycja, _ustawianawyspa)
{
	zycie = 220;
	max_zycie = 220;
	tluszcz = 250;
	max_tluszcz = 250;
	zakreswidzenia = 6;
	masa = 150;
	maksymalnyczaspogonizacelzwierze = 10;
	maksymalnyczaspogonizacelrozmnazanie = 12;
	wspolczynnikspalaniatluszczuprzyrozmnazaniu = 70;
	wspolczynnikspalaniatluszczuprzyruchu = 20;
	wspolczynnikzmniejszeniazycia = 20;
	wspolczynnikplodnosci = 6;
	inicialy = "Ni";
	nazwa = "Niedzwiedz";
	gra = _gra;
	zjadanezwierzeta.push_back(new CWiewiorka);
	zjadanezwierzeta.push_back(new COwca);
	zjadanezwierzeta.push_back(new CWilk);
	zjadanezwierzeta.push_back(new CDzik);
	zjadanerosliny.push_back(new CTrawa);
	zjadanerosliny.push_back(new COrzech);
	zjadanerosliny.push_back(new CMarchewka);
}


CNiedzwiedz::~CNiedzwiedz()
{
	//std::cout << "Destruktor CNiedzwiedz" << std::endl;
}


CPole* CNiedzwiedz::RozmnazajSie()
{
	bool rozmnazajsie = false;
	for (int i = 0; i < zwierzetawpoluwidzenia.size(); i++)
	{
		if (Odleglosc(zwierzetawpoluwidzenia[i]) < 1)
		{
			if (dynamic_cast<CNiedzwiedz*>(zwierzetawpoluwidzenia[i]))
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
				this->DajGre()->StworzNiedzwiedziaRozmnazanie(polewidzenia[i]);
				return polewidzenia[i];
			}
		}
	}
	return nullptr;
}

void CNiedzwiedz::Inicjalizacja()
{
	this->OdswiezPoleWidzenia();
	this->WyznaczKomponentyKtoreWidzisz();
	this->UzupelnijRoslinyWPoluWidzeniaDoZjedzenia();
	this->UzupelnijZwierzetaWPoluWidzeniaDoZjedzenia();
	this->UstawCelRoslina();
	this->UstawCelZwierze();
	this->UstawCelRozmnazanie();
	this->ResetujCzasPogoniZaCelZwierze();
	this->ResetujCzasPogoniZaCelRozmnazanie();
}

void CNiedzwiedz::KoniecRundyOdswiezanie()
{
	this->OdswiezPoleWidzenia();
	this->WyznaczKomponentyKtoreWidzisz();
	this->UzupelnijRoslinyWPoluWidzeniaDoZjedzenia();
	this->UzupelnijZwierzetaWPoluWidzeniaDoZjedzenia();
	this->OdswiezCelRoslina();
	this->OdswiezCelZwierze();
	this->OdswiezCelRozmnazanie();
}

void CNiedzwiedz::Zyj()
{
	if (!(this->CzyKomponentJestMartwy()))
	{
		int niezdarnosc;
		niezdarnosc = (std::rand() % 10);
		if (niezdarnosc > 0)
		{
			if (this->DajTluszcz() > 160)
			{
				this->OdswiezPoleWidzenia();
				this->WyznaczKomponentyKtoreWidzisz();
				if ((this->DajCelRozmnazanie() != nullptr) && (!(this->DajCelRozmnazanie()->CzyKomponentJestMartwy())))
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
						this->LosowyRuch();
					}
				}
				this->LosowyRuch();
			}
			else if (this->DajTluszcz() > 90)
			{
				this->OdswiezPoleWidzenia();
				this->WyznaczKomponentyKtoreWidzisz();
				if (this->DajCelZwierze())
				{
					if (this->DajCzasPogoniZaCelZwierze() > 0)
					{
						if ((this->CzyZwierzeDoZjedzeniaJestWZasiegu()) && (!(this->DajCelZwierze()->CzyKomponentJestMartwy())))
						{
							this->ZjedzZwierzeCel();
							this->OdswiezPoleWidzenia();
							this->WyznaczKomponentyKtoreWidzisz();
							this->UzupelnijZwierzetaWPoluWidzeniaDoZjedzenia();
							if (!(this->DajCelZwierze()))
							{
								this->UstawCelZwierze();
								this->ResetujCzasPogoniZaCelRozmnazanie();
							}
						}
						else
						{
							this->IdzWKierunkuCelZwierze();
							this->ZmniejszCzasPogoniZaCelZwierze();
						}
						this->OdswiezCelZwierze(); ///
					}
					else
					{
						this->LosowyRuch();
						this->OdswiezPoleWidzenia();
						this->WyznaczKomponentyKtoreWidzisz();
						this->UzupelnijZwierzetaWPoluWidzeniaDoZjedzenia();
						this->UstawCelZwierze();
						this->ResetujCzasPogoniZaCelZwierze();
					}
				}
				else
				{
					this->LosowyRuch();
					this->OdswiezPoleWidzenia();
					this->WyznaczKomponentyKtoreWidzisz();
					this->UzupelnijZwierzetaWPoluWidzeniaDoZjedzenia();
					this->UstawCelZwierze();
					this->ResetujCzasPogoniZaCelZwierze();
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
							}
						}
						else
						{
							this->IdzWKierunkuCelu(this->DajCelRoslina());
							//this->IdzWKierunkuCelu(this->DajCelRoslina());
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
							//this->ResetujCzasPogoniZaCelRozmnazanie(); //wtf tutaj to robi
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
					this->LosowyRuch();
				}
			}
		}
		else
		{
			this->LosowyRuch();
			this->LosowyRuch();
			this->OdswiezPoleWidzenia();
			this->WyznaczKomponentyKtoreWidzisz();
			this->UzupelnijRoslinyWPoluWidzeniaDoZjedzenia();
			this->UstawCelRoslina();
		}
	}
}