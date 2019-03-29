#pragma once
#include "Miesozerne.h"
#include "Wiewiorka.h"
#include "Owca.h"
#include "Gra.h"
class CWilk :
	public CMiesozerne
{
public:
	CWilk();
	CWilk(CPole* _ustawianapozycja, CWyspa* _ustawianawyspa, CGra* _gra);
	~CWilk();

	CPole* RozmnazajSie(); // zwraca pozycje na ktorej ma sie zrespic nowy wilk
	void UciekajPrzedNiedzwiedziem();
	bool CzyNiedzwiedzJestWPoluWidzenia();
	void Inicjalizacja();
	void Zyj();
	void KoniecRundyOdswiezanie(); // zmniec na mieso i roslinozerne
};

