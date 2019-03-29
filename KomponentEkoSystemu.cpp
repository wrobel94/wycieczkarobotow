#include "stdafx.h"
#include "KomponentEkoSystemu.h"


CKomponentEkoSystemu::CKomponentEkoSystemu()
{
}


CKomponentEkoSystemu::CKomponentEkoSystemu(CPole* _ustawianapozycja, CWyspa* _ustawianawyspa)
{
	poprzedniapozycja = _ustawianapozycja;
	aktualnapozycja = _ustawianapozycja;
	wyspanaktorejjestem = _ustawianawyspa;
	martwy = false;
}

bool CKomponentEkoSystemu::CzyKomponentJestMartwy()
{
	if (martwy == true)
	{
		return true;
	}
	else
	{
		return false;
	}
}
CKomponentEkoSystemu::~CKomponentEkoSystemu()
{
	//std::cout << "Destruktor CKomponentEkoSystemu" << std::endl;
}

void CKomponentEkoSystemu::UstawMartwy()
{
	martwy = true;
	//std::cout << "CKomponentEkosystemu::UstwaMartwy()" << std::endl;
}

void CKomponentEkoSystemu::UstawPozycje(CPole* _ustawianepole)
{
	aktualnapozycja = _ustawianepole;
}


void CKomponentEkoSystemu::DajPozycje()
{
	aktualnapozycja->WyswietlWspolrzedne();
}

CPole* CKomponentEkoSystemu::DajPole()
{
	return aktualnapozycja;
}

CPole* CKomponentEkoSystemu::DajPoprzedniaPozycje()
{
	return poprzedniapozycja;
}

std::string CKomponentEkoSystemu::DajNazwe()
{
	return nazwa;
}

CWyspa* CKomponentEkoSystemu::DajWyspe()
{
	return wyspanaktorejjestem;
}

CGra* CKomponentEkoSystemu::DajGre()
{
	return gra;
}

void CKomponentEkoSystemu::Inicjalizacja()
{

}

void CKomponentEkoSystemu::KoniecRundyOdswiezanie()
{

}

void CKomponentEkoSystemu::WyswietlTluszcz()
{

}