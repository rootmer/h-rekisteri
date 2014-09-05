/** Ohjelma joka ottaa vastaan käyttäjältä
*   henkilön perustietoja. Kun taulukko täynnä
*   ohjelma ilmoittaa siitä.
*
*/

#include <iostream>
#include <string>

using namespace std;

/** tietue joka tulee pitämään sisällään
*   nimen, koulumatkan pituuden sekä hatun
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

        /** Oletuksena taulukon etunimi- jäsen on "empty" jotta voidaan tietää mikä
        *   alkio on ns. tyhjä. Ohjelma siis etsii aluksi tyhjän kohdan johon voi lisätä
        *   henkilötietoja.
        */
        else if (valinta == 1) {
                int* pTauluKoko = &taulunkoko;
                LisaaHenkilo(hRekisteri,pTauluKoko);
        }

        /** Listaa henkilötiedot
        *   taulukosta
        */
        else if (valinta == 2) {
            TulostaKaikkiHenkilot(hRekisteri, taulunkoko);
            /** for (int a = 0; a < taulunkoko; a++) {
            *   cout << "Henkilö " << a << ": " << hRekisteri[a].etunimi << " "
            *   << hRekisteri[a].koulumatka << " " << hRekisteri[a].hattukoko << endl;
            *   }
            */
        }

        else cout << "Valitse uudelleen";

    } while (valinta != 0);
}

/** Valikko näkyville
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
    cout << "Syötä hakemasi henkilön etunimi" << endl;
    cin >> nimi;

    for (int a = 0; a < taulunkoko; a++) {
        if (TIEDOT[a].etunimi == nimi) {
            cout << endl << "Löytyi henkilö: " << TIEDOT[a].etunimi << " " << TIEDOT[a].koulumatka <<
            " " << TIEDOT[a].hattukoko << endl;
            break;
        }

        if (a == taulunkoko - 1 && TIEDOT[a].etunimi != nimi) {
            cout << endl << "Ei löytynyt henkilöä: " << nimi << endl;
            break;
        }
    }
}

/** Listaa kaikki henkilöt lkm kokoisessa
*   taulukossa TIEDOT
*
*/
void TulostaKaikkiHenkilot(tietue TIEDOT[], int lkm) {
    for (int a = 0; a < lkm; a++) {
        cout << "Henkilö " << a << ": " << TIEDOT[a].etunimi << " "
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
        cout << "Henkilön etunimi" << endl;
        cin >> eNimi;
        cout << "Henkilön koulumatka" << endl;
        cin >> kMatka;
        cout << "Henkilön hatun koko" << endl;
        cin >> hKoko;
        TIEDOT[kohta].etunimi = eNimi;
        TIEDOT[kohta].koulumatka = kMatka;
        TIEDOT[kohta].hattukoko = hKoko;
        if (kohta == listattavaa - 1) { taynna = true; }
    }

    else if (taynna) { cout << endl << "Taulukko täynnä!" << endl; }
}
