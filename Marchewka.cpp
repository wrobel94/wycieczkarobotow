#include "stdafx.h"
#include "Marchewka.h"


CMarchewka::CMarchewka()
{
	inicialy = "Ma";
	nazwa = "Marchewka";
}

CMarchewka::CMarchewka(CPole* _ustawianapozycja, CWyspa* _ustawianawyspa, CGra* _gra) : CRoslina(_ustawianapozycja, _ustawianawyspa)
{
	inicialy = "Ma";
	nazwa = "Marchewka";
	kalorycznosc = 18;
	gra = _gra;
}

CMarchewka::~CMarchewka()
{
	//std::cout << "Destruktor CMarchewka" << std::endl;
}
