/** Ohjelma joka ottaa vastaan k�ytt�j�lt�
*   henkil�n perustietoja. Kun taulukko t�ynn�
*   ohjelma ilmoittaa siit�.
*
*/

#include <iostream>
#include <string>

using namespace std;

/** tietue joka tulee pit�m��n sis�ll��n
*   nimen, koulumatkan pituuden sek� hatun
*   koon
*/
struct tietue {
    string etunimi;
    float koulumatka;
    int hattukoko;
    tietue(): etunimi("empty"), koulumatka(0.0), hattukoko(0) {}
};

int taulunkoko = 2;

int valikko(void);
void TulostaHenkilo(tietue TIEDOT[]);
void TulostaKaikkiHenkilot(tietue TIEDOT[], int lkm);
void LisaaHenkilo(tietue TIEDOT[], int *lkm);

int main(void)
{
    // tietuetaulukon kokona 10 alkiota
    tietue hRekisteri[taulunkoko];
    int valinta = 99;
    int kohta = 0;

    do {
        valinta = valikko();
        if (valinta == 0) { break; }

        /** Oletuksena taulukon etunimi- j�sen on "empty" jotta voidaan tiet�� mik�
        *   alkio on ns. tyhj�. Ohjelma siis etsii aluksi tyhj�n kohdan johon voi lis�t�
        *   henkil�tietoja.
        */
        else if (valinta == 1) {
                int* pTauluKoko = &taulunkoko;
                LisaaHenkilo(hRekisteri,pTauluKoko);
        }

        /** Listaa henkil�tiedot
        *   taulukosta
        */
        else if (valinta == 2) {
            TulostaKaikkiHenkilot(hRekisteri, taulunkoko);
            /** for (int a = 0; a < taulunkoko; a++) {
            *   cout << "Henkil� " << a << ": " << hRekisteri[a].etunimi << " "
            *   << hRekisteri[a].koulumatka << " " << hRekisteri[a].hattukoko << endl;
            *   }
            */
        }

        else cout << "Valitse uudelleen";

    } while (valinta != 0);
}

/** Valikko n�kyville
*   nyt aliohjelmana
*/
int valikko(void) {
    int valinta = 99;
    cout << endl;
    cout << "VALIKKO" << endl;
    cout << "0 - Lopeta" << endl;
    cout << "1 - Lisaa henkilo" << endl;
    cout << "2 - Listaa kaikki henkilot" << endl;
    cin >> valinta;
    return valinta;
}

void TulostaHenkilo(tietue TIEDOT[]) {
    string nimi;
    cout << "Sy�t� hakemasi henkil�n etunimi" << endl;
    cin >> nimi;

    for (int a = 0; a < taulunkoko; a++) {
        if (TIEDOT[a].etunimi == nimi) {
            cout << endl << "L�ytyi henkil�: " << TIEDOT[a].etunimi << " " << TIEDOT[a].koulumatka <<
            " " << TIEDOT[a].hattukoko << endl;
            break;
        }

        if (a == taulunkoko - 1 && TIEDOT[a].etunimi != nimi) {
            cout << endl << "Ei l�ytynyt henkil��: " << nimi << endl;
            break;
        }
    }
}

/** Listaa kaikki henkil�t lkm kokoisessa
*   taulukossa TIEDOT
*
*/
void TulostaKaikkiHenkilot(tietue TIEDOT[], int lkm) {
    for (int a = 0; a < lkm; a++) {
        cout << "Henkil� " << a << ": " << TIEDOT[a].etunimi << " "
        << TIEDOT[a].koulumatka << " " << TIEDOT[a].hattukoko << endl;
    }
}

void LisaaHenkilo(tietue TIEDOT[], int *lkm) {
    int listattavaa = lkm;
    int kohta = 99;
    bool taynna = false;
    for (int a = 0; a < listattavaa; a++) {
        if (TIEDOT[a].etunimi == "empty") {
            kohta = a;
            break;
        }
    }

    if (!taynna) {
        string eNimi;
        float kMatka;
        int hKoko;
        cout << "Henkil�n etunimi" << endl;
        cin >> eNimi;
        cout << "Henkil�n koulumatka" << endl;
        cin >> kMatka;
        cout << "Henkil�n hatun koko" << endl;
        cin >> hKoko;
        TIEDOT[kohta].etunimi = eNimi;
        TIEDOT[kohta].koulumatka = kMatka;
        TIEDOT[kohta].hattukoko = hKoko;
        if (kohta == listattavaa - 1) { taynna = true; }
    }

    else if (taynna) { cout << endl << "Taulukko t�ynn�!" << endl; }
}
