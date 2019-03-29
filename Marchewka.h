#pragma once
#include "Roslina.h"
#include "Gra.h"
class CMarchewka :
	public CRoslina
{
public:
	CMarchewka();
	CMarchewka(CPole* _ustawianapozycja, CWyspa* _ustawianawyspa, CGra* _gra);
	~CMarchewka();
};

