#include "stdafx.h"
#include "Orzech.h"


COrzech::COrzech()
{
	nazwa = "Orzech";
	inicialy = "Or";
	kalorycznosc = 9;
}

COrzech::COrzech(CPole* _ustawianapozycja, CWyspa* _ustawianawyspa, CGra* _gra) : CRoslina(_ustawianapozycja, _ustawianawyspa)
{
	nazwa = "Orzech";
	inicialy = "Or";
	kalorycznosc = 9;
	gra = _gra;
}

COrzech::~COrzech()
{
	//std::cout << "Destruktor COrzech" << std::endl;
}
