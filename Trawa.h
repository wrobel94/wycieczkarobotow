#pragma once
#include "Roslina.h"
#include "Gra.h"

class CTrawa :
	public CRoslina
{
public:
	CTrawa();
	CTrawa(CPole* _ustawianapozycja, CWyspa* _ustawianawyspa, CGra* _gra);
	~CTrawa();
};


