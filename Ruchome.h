#pragma once
#include "KomponentEkoSystemu.h"
#include "Pole.h"
#include "Wyspa.h"
class CRuchome :
	public CKomponentEkoSystemu
{
public:
	CRuchome();
	CRuchome(CPole* _ustawianapozycja, CWyspa* _ustawianawyspa);
	~CRuchome();

	void ZmienPozycje(CPole* _nastepnapozycja); // czy nastepna pozycja jest w poblizu aktualnej
	void LosowyRuch();
	virtual void ZmniejszTluszczRuch() = 0;
	void IdzWKierunkuCelu(CKomponentEkoSystemu* _cel);
};

