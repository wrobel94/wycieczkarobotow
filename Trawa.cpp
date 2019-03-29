#include "stdafx.h"
#include "Trawa.h"


CTrawa::CTrawa()
{
	inicialy = "Tr";
	nazwa = "Trawa";
	kalorycznosc = 10;
}

CTrawa::CTrawa(CPole* _ustawianapozycja, CWyspa* _ustawianawyspa, CGra* _gra) : CRoslina(_ustawianapozycja, _ustawianawyspa)
{
	inicialy = "Tr";
	nazwa = "Trawa";
	kalorycznosc = 10;
	gra = _gra;
}

CTrawa::~CTrawa()
{
	//std::cout << "Destruktor CTrawa" << std::endl;
}
