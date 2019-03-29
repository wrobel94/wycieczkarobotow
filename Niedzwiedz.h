#pragma once
#include "Miesozerne.h"
#include "Roslinozerne.h"
#include "Wiewiorka.h"
#include "Dzik.h"
#include "Owca.h"
#include "Wilk.h"
#include "Trawa.h"
#include "Gra.h"

class CNiedzwiedz :
	public CMiesozerne, public CRoslinozerne
{
public:
	CNiedzwiedz();
	CNiedzwiedz(CPole* _ustawianapozycja, CWyspa* _ustawianawyspa, CGra* _gra);
	~CNiedzwiedz();


	//	void UzupelnijZwierzetaWPoluWidzeniaDoZjedzenia(std::vector<CKomponentEkoSystemu*> _widzianekomponenty); // na podstawie nazwy porownuje zwierzeta widziane ze zjadanymi
	//	void ZjedzZwierze(CZwierze* _zwierze);
	//	void WyznaczKomponentyKtoreWidzisz(); // nadpisuje ze zwirzaka chce rzeby widzial wszystko co ma mase powyzej 10 kg 

	//void StworzPotomka();
	CPole* RozmnazajSie(); // zwraca pozycje na ktorej ma sie zrespic nowy wilk
	void Inicjalizacja();
	void Zyj();
	void KoniecRundyOdswiezanie();
};

