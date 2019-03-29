#include "stdafx.h"
#include "Ruchome.h"


CRuchome::CRuchome()
{
}


CRuchome::CRuchome(CPole* _ustawianapozycja, CWyspa* _ustawianawyspa) : CKomponentEkoSystemu(_ustawianapozycja, _ustawianawyspa)
{
}


CRuchome::~CRuchome()
{
	//std::cout << "Destruktor CRuchome" << std::endl;
}


void CRuchome::ZmienPozycje(CPole* _nastepnapozycja)
{
	if (_nastepnapozycja)
	{
		if (_nastepnapozycja->CzyMoznaWejscNaPole(_nastepnapozycja))
		{
			if (!(this->CzyKomponentJestMartwy()))
			{
				int pomX = this->DajPole()->DajX();
				int pomY = this->DajPole()->DajY();


				int min_i = aktualnapozycja->DajX() - 1;
				int max_i = aktualnapozycja->DajX() + 1;
				int min_j = aktualnapozycja->DajY() - 1;
				int max_j = aktualnapozycja->DajY() + 1;
				int docelowapozX = _nastepnapozycja->DajX();
				int docelowapozY = _nastepnapozycja->DajY();
				if (((min_i <= docelowapozX) && (docelowapozX <= max_i)) && ((min_j <= docelowapozY) && (docelowapozY <= max_j)))
				{
					aktualnapozycja->DajPole()->UsunKomponentZPola(this);
					poprzedniapozycja = aktualnapozycja;
					aktualnapozycja = _nastepnapozycja;
					this->UstawPozycje(aktualnapozycja);
					aktualnapozycja->DajPole()->DodajKomponentNaPole(this);
					this->ZmniejszTluszczRuch(); 
				}
			}
		}
	}
}

void CRuchome::LosowyRuch()
{
	int wylosowanaliczba;
	wylosowanaliczba = (std::rand() % 9);
	switch (wylosowanaliczba)
	{
	case 0:
		if (this->DajWyspe()->CzyPoleJestNaWyspie(this->DajPole()->DajX() - 1, this->DajPole()->DajY() - 1))
		{
			ZmienPozycje(this->DajWyspe()->Pola()[this->DajPole()->DajX() - 1][this->DajPole()->DajY() - 1]);
		};
		break;
	case 1:
		if (this->DajWyspe()->CzyPoleJestNaWyspie(this->DajPole()->DajX(), this->DajPole()->DajY() - 1))
		{
			ZmienPozycje(this->DajWyspe()->Pola()[this->DajPole()->DajX()][this->DajPole()->DajY() - 1]);
		};
		break;
	case 2:
		if (this->DajWyspe()->CzyPoleJestNaWyspie(this->DajPole()->DajX() + 1, this->DajPole()->DajY() - 1))
		{
			ZmienPozycje(this->DajWyspe()->Pola()[this->DajPole()->DajX() + 1][this->DajPole()->DajY() - 1]);
		};
		break;
	case 3:
		if (this->DajWyspe()->CzyPoleJestNaWyspie(this->DajPole()->DajX() - 1, this->DajPole()->DajY()))
		{
			ZmienPozycje(this->DajWyspe()->Pola()[this->DajPole()->DajX() - 1][this->DajPole()->DajY()]);
		};
		break;
	case 4:
		break;
	case 5:
		if (this->DajWyspe()->CzyPoleJestNaWyspie(this->DajPole()->DajX() + 1, this->DajPole()->DajY()))
		{
			ZmienPozycje(this->DajWyspe()->Pola()[this->DajPole()->DajX() + 1][this->DajPole()->DajY()]);
		};
		break;
	case 6:
		if (this->DajWyspe()->CzyPoleJestNaWyspie(this->DajPole()->DajX() - 1, this->DajPole()->DajY() + 1))
		{
			ZmienPozycje(this->DajWyspe()->Pola()[this->DajPole()->DajX() - 1][this->DajPole()->DajY() + 1]);
		};
		break;
	case 7:
		if (this->DajWyspe()->CzyPoleJestNaWyspie(this->DajPole()->DajX(), this->DajPole()->DajY() + 1))
		{
			ZmienPozycje(this->DajWyspe()->Pola()[this->DajPole()->DajX()][this->DajPole()->DajY() + 1]);
		};
		break;
	case 8:
		if (this->DajWyspe()->CzyPoleJestNaWyspie(this->DajPole()->DajX() + 1, this->DajPole()->DajY() + 1))
		{
			ZmienPozycje(this->DajWyspe()->Pola()[this->DajPole()->DajX() + 1][this->DajPole()->DajY() + 1]);
		};
		break;
	default:
		break;
	}
}

void CRuchome::IdzWKierunkuCelu(CKomponentEkoSystemu* _cel)
{
	if (_cel != nullptr)
	{
		if (_cel->DajPole()->DajX() > this->DajPole()->DajX())
		{
			if (_cel->DajPole()->DajY() > this->DajPole()->DajY())
			{
				if (this->DajWyspe()->CzyPoleJestNaWyspie(this->DajPole()->DajX() + 1, this->DajPole()->DajY() + 1))
				{
					ZmienPozycje(this->DajWyspe()->Pola()[this->DajPole()->DajX() + 1][this->DajPole()->DajY() + 1]);
				}
			}
			else if (_cel->DajPole()->DajY() < this->DajPole()->DajY())
			{
				if (this->DajWyspe()->CzyPoleJestNaWyspie(this->DajPole()->DajX() + 1, this->DajPole()->DajY() - 1))
				{
					ZmienPozycje(this->DajWyspe()->Pola()[this->DajPole()->DajX() + 1][this->DajPole()->DajY() - 1]);
				}
			}
			else
			{
				if (this->DajWyspe()->CzyPoleJestNaWyspie(this->DajPole()->DajX() + 1, this->DajPole()->DajY()))
				{
					ZmienPozycje(this->DajWyspe()->Pola()[this->DajPole()->DajX() + 1][this->DajPole()->DajY()]);
				}
			}
		}
		else if (_cel->DajPole()->DajX() < this->DajPole()->DajX())
		{
			if (_cel->DajPole()->DajY() > this->DajPole()->DajY())
			{
				if (this->DajWyspe()->CzyPoleJestNaWyspie(this->DajPole()->DajX() - 1, this->DajPole()->DajY() - 1))
				{
					ZmienPozycje(this->DajWyspe()->Pola()[this->DajPole()->DajX() - 1][this->DajPole()->DajY() + 1]);
				}
			}
			else if (_cel->DajPole()->DajY() < this->DajPole()->DajY())
			{
				if (this->DajWyspe()->CzyPoleJestNaWyspie(this->DajPole()->DajX() - 1, this->DajPole()->DajY() - 1))
				{
					ZmienPozycje(this->DajWyspe()->Pola()[this->DajPole()->DajX() - 1][this->DajPole()->DajY() - 1]);
				}
			}
			else
			{
				if (this->DajWyspe()->CzyPoleJestNaWyspie(this->DajPole()->DajX() - 1, this->DajPole()->DajY()))
				{
					ZmienPozycje(this->DajWyspe()->Pola()[this->DajPole()->DajX() - 1][this->DajPole()->DajY()]);
				}
			}
		}
		else
		{
			if (_cel->DajPole()->DajY() > this->DajPole()->DajY())
			{
				if (this->DajWyspe()->CzyPoleJestNaWyspie(this->DajPole()->DajX(), this->DajPole()->DajY() + 1))
				{
					ZmienPozycje(this->DajWyspe()->Pola()[this->DajPole()->DajX()][this->DajPole()->DajY() + 1]);
				}
			}
			else if (_cel->DajPole()->DajY() < this->DajPole()->DajY())
			{
				if (this->DajWyspe()->CzyPoleJestNaWyspie(this->DajPole()->DajX(), this->DajPole()->DajY() - 1))
				{
					ZmienPozycje(this->DajWyspe()->Pola()[this->DajPole()->DajX()][this->DajPole()->DajY() - 1]);
				}
			}
		}
	}
}