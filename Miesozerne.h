#pragma once
#include "Zwierze.h"
class CMiesozerne :
	public virtual CZwierze
{
protected:
	std::vector<CZwierze*> zjadanezwierzeta;
	std::vector<CZwierze*> zwierzetawpoluwidzeniadozjedzenia;
	CZwierze* celzwierze; //wybrane zwierze do poscigu
	int czaspogonizacelzwierze;
	int maksymalnyczaspogonizacelzwierze;
public:
	CMiesozerne();
	CMiesozerne(CPole* _ustawianapozycja, CWyspa* _ustawianawyspa);
	~CMiesozerne();

	void UzupelnijZwierzetaWPoluWidzeniaDoZjedzenia(); // na podstawie nazwy porownuje zwierzeta widziane ze zjadanymi, musi byc  wywolane po uzupelnieniu widzianych komponent
	void WyswietlCelZwierze(); // wyswietla zwierze ktore jest celem pogoni
	void IdzWKierunkuCelZwierze(); // nie sprawdza czy pole jest na wyspie ----DOPISAC JAK W UCIACZKA OWCA
	CKomponentEkoSystemu* ZjedzZwierzeCel(); // Usuwa dodaje tluszcz cel zwierzecia
	void UsunCelZwierze();
	CZwierze* DajCelZwierze();
	bool CzyZwierzeDoZjedzeniaJestWZasiegu();
	bool SprawdzCzyMaszCelZwierze(); // sprawdza czy zwierzak ma ustawiony celzwierze
	void OdswiezCelZwierze(); //Zmienia celzwierze na nullptr jesli zwierzak jest martwy 
	int DajCzasPogoniZaCelZwierze();
	void ZmniejszCzasPogoniZaCelZwierze();
	void ResetujCzasPogoniZaCelZwierze();
	void UstawCelZwierze();
};

