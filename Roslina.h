#pragma once
//#include "Gra.h"
#include "KomponentEkoSystemu.h"
#include <iostream>
class CRoslina :
	public CKomponentEkoSystemu
{
protected:
	int kalorycznosc;
public:
	CRoslina();
	CRoslina(CPole* _ustawianapozycja, CWyspa* _ustawianawyspa);
	~CRoslina();

	void WyswietlKomponent();
	void WyswietlKomponent_Tablica();
	int DajKalorycznosc();
	void Zyj();
};

