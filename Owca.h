#pragma once
#include "Roslinozerne.h"
#include "Trawa.h"
//#include "Miesozerne.h" // przepisalem do roslinozerne
#include "Gra.h"

class COwca :
	public CRoslinozerne
{
public:
	COwca();
	COwca(CPole* _ustawianapozycja, CWyspa* _ustawianawyspa, CGra* _gra);
	~COwca();


	
	//void Uciekaj();
	//void ZmniejszTluszczRuch();
	CPole* RozmnazajSie(); // zwraca pozycje na ktorej ma sie zrespic nowy wilk
						   //void StworzPotomka();

	void Inicjalizacja();
	void Zyj();
	void KoniecRundyOdswiezanie();
};

