#pragma once
#include "Roslinozerne.h"
#include "Orzech.h"
#include "Miesozerne.h"
#include "Gra.h"

class CWiewiorka :
	public CRoslinozerne
{
public:
	CWiewiorka();
	CWiewiorka(CPole* _ustawianapozycja, CWyspa* _ustawianawyspa, CGra* _gra);
	~CWiewiorka();

	CPole* RozmnazajSie(); // zwraca pozycje na ktorej ma sie zrespic nowy wilk
	void Inicjalizacja();
	void Zyj();
	void KoniecRundyOdswiezanie();
};

