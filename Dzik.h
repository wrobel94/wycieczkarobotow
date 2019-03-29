#pragma once
#include "Roslinozerne.h"
#include "Marchewka.h"
#include "Trawa.h"
#include "Orzech.h"
#include "Gra.h"
class CDzik :
	public CRoslinozerne
{
public:
	CDzik();
	CDzik(CPole* _ustawianapozycja, CWyspa* _ustawianawyspa, CGra* _gra);
	~CDzik();

	CPole* RozmnazajSie(); // zwraca pozycje na ktorej ma sie zrespic nowy wilk
	void UciekajPrzedNiedzwiedziem();
	bool CzyNiedzwiedzJestWPoluWidzenia();
	void Inicjalizacja();
	void Zyj();
	void KoniecRundyOdswiezanie();
};

