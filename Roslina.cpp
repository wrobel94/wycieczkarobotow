#include "stdafx.h"
#include "Roslina.h"


CRoslina::CRoslina()
{
}

CRoslina::CRoslina(CPole* _ustawianapozycja, CWyspa* _ustawianawyspa) : CKomponentEkoSystemu(_ustawianapozycja, _ustawianawyspa)
{
}

CRoslina::~CRoslina()
{
	//std::cout << "Destruktor CRoslina" << std::endl;
}

void CRoslina::WyswietlKomponent()
{
	std::cout << "(" << nazwa /*<< ", zycie:" << zycie << ", tluszcz:" << tluszcz */ << ")";
}

void CRoslina::WyswietlKomponent_Tablica()
{
	std::cout << inicialy;
}

int CRoslina::DajKalorycznosc()
{
	return kalorycznosc;
}

void CRoslina::Zyj()
{

}