#pragma once
#include "Roslina.h"
#include "Gra.h"

class COrzech :
	public CRoslina
{
public:
	COrzech();
	COrzech(CPole* _ustawianapozycja, CWyspa* _ustawianawyspa, CGra* _gra);
	~COrzech();
};

