#pragma once
#include "Zwierze.h"
#include "Roslina.h"
#include "Miesozerne.h"
class CRoslinozerne :
	public virtual CZwierze
{
protected:
	std::vector<CRoslina*> zjadanerosliny;
	std::vector<CRoslina*> roslinywpoluwidzeniadozjedzenia;
	CRoslina* celroslina;
public:
	CRoslinozerne();
	CRoslinozerne(CPole* _ustawianapozycja, CWyspa* _ustawianawyspa);
	~CRoslinozerne();

	void UzupelnijRoslinyWPoluWidzeniaDoZjedzenia();
	//void UciekajPrzedMiesozenym(CZwierze* _atakujacy); // Przepisane do Zwierze jako void UciekajPrzed(CZwierze* _atakujacy)
	void UciekajPrzedMiesozernym();
	bool CzyMiesozernyJestWPoluWidzenia();												   //	virtual void ZmniejszTluszcz();
	CRoslina* DajCelRoslina();
	void UsunCelRoslina();
	bool CzyRoslinaDoZjedzeniaJestWZasiegu();
	bool SprawdzCzyMaszCelRoslina(); // sprawdza czy zwierzak ma ustawiony celzwierze
	void OdswiezCelRoslina();
	void UstawCelRoslina();
	CKomponentEkoSystemu* ZjedzRoslinaCel();
};

