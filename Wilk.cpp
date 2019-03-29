#include "stdafx.h"
#include "Wilk.h"

/*template<class Komponent1, class Komponent2> bool PorownajDwaKomponenty(Komponent1* _komponentnaktoregotyprzutuje, Komponent2* _komponentrzutowany)
{
if (dynamic_cast<Komponent1*>(_komponentrzutowany) != nullptr)
{
return true;
}
else
{
return false;
}
}*/

CWilk::CWilk()
{
	inicialy = "wI";
	nazwa = "Wilk";
}

CWilk::CWilk(CPole* _ustawianapozycja, CWyspa* _ustawianawyspa, CGra* _gra) :CMiesozerne(_ustawianapozycja, _ustawianawyspa), CZwierze(_ustawianapozycja, _ustawianawyspa)
{
	zycie = 70;
	max_zycie = 70;
	tluszcz = 100;
	max_tluszcz = 100;
	zakreswidzenia = 5;
	maksymalnyczaspogonizacelzwierze = 30;
	maksymalnyczaspogonizacelrozmnazanie = 20;
	wspolczynnikspalaniatluszczuprzyrozmnazaniu = 40;
	wspolczynnikspalaniatluszczuprzyruchu = 7;
	wspolczynnikzmniejszeniazycia = 10;
	wspolczynnikplodnosci = 3;
	masa = 50;
	gra = _gra;
	inicialy = "wI";
	nazwa = "Wilk";
	//std::cout << " Konstruktor Wilk" << " Moje Pole: ";
	//std::cout << std::endl;
	//std::cout << _ustawianapozycja->DajX();  //debag
	//std::cout << std::endl; //debag
	zjadanezwierzeta.push_back(new CWiewiorka);
	zjadanezwierzeta.push_back(new COwca);
}


CWilk::~CWilk()
{
	for (auto iterator = zjadanezwierzeta.begin(); iterator != zjadanezwierzeta.end(); )
	{
		delete *iterator;
		iterator = zjadanezwierzeta.erase(iterator);
	}
	//std::cout << "Destruktor CWilk" << std::endl;
}

CPole* CWilk::RozmnazajSie()
{
	bool rozmnazajsie = false;
	for (int i = 0; i < zwierzetawpoluwidzenia.size(); i++)
	{
		if (Odleglosc(zwierzetawpoluwidzenia[i]) <= 1)
		{
			if (dynamic_cast<CWilk*>(zwierzetawpoluwidzenia[i]))
			{
				rozmnazajsie = true;
			}
		}
	}
	if (rozmnazajsie)
	{
		for (int i = 0; i < polewidzenia.size(); i++)
		{
			if ((polewidzenia[i]->DajKomponentyNaPolu().empty()) && (this->Odleglosc(polewidzenia[i]) <= 1)) //jezeli pole jest puste mozna postawic na nim komponent
			{
				
				//polewidzenia[i]->WyswietlWspolrzedne();
				this->DajGre()->StworzWilkaRozmnazanie(polewidzenia[i]);
				return polewidzenia[i];
			}
		}
	}
	return nullptr;
}


void CWilk::UciekajPrzedNiedzwiedziem()
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
	if (pomocnicze == nullptr)
	{
		delete pomocnicze; // czy to jest zasadne
	}
}

void CWilk::Zyj()
{
	if (!(this->CzyKomponentJestMartwy()))
	{
		int niezdarnosc;
		niezdarnosc = (std::rand() % 12);
		if (niezdarnosc > 0)
		{
			if (this->DajTluszcz() > 65)
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
						if (this->Odleglosc(this->DajCelRozmnazanie()) > 1)
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
								//this->UsunCelRozmnaznie();
								if (!(this->DajCelRozmnazanie()))
								{
									this->UstawCelRozmnazanie();
									this->ResetujCzasPogoniZaCelRozmnazanie();
								}
								//this->LosowyRuch(); // usun
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
			}
			else
			{
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
							//this->IdzWKierunkuCelu(); //skasuj
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
				}
			}
		}
		else
		{
			this->LosowyRuch();
			this->OdswiezPoleWidzenia();
			this->WyznaczKomponentyKtoreWidzisz();
			this->UzupelnijZwierzetaWPoluWidzeniaDoZjedzenia();
		}
	}
}

void CWilk::KoniecRundyOdswiezanie()
{
	this->OdswiezPoleWidzenia();
	this->WyznaczKomponentyKtoreWidzisz();
	this->UzupelnijZwierzetaWPoluWidzeniaDoZjedzenia();
	this->OdswiezCelRozmnazanie();
	this->OdswiezCelZwierze();
}
void CWilk::Inicjalizacja()
{
	this->OdswiezPoleWidzenia();
	this->WyznaczKomponentyKtoreWidzisz();
	this->UzupelnijZwierzetaWPoluWidzeniaDoZjedzenia();
	this->UstawCelZwierze();
	this->UstawCelRozmnazanie();
	this->ResetujCzasPogoniZaCelRozmnazanie();
}


bool CWilk::CzyNiedzwiedzJestWPoluWidzenia()
{
	for (int i = 0; i < zwierzetawpoluwidzenia.size(); i++)
	{
		if (dynamic_cast<CNiedzwiedz*>(zwierzetawpoluwidzenia[i]))
		{
			if ((this->Odleglosc(zwierzetawpoluwidzenia[i]) <= this->DajZakresWidzenia()))
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