/** Ohjelma joka ottaa vastaan käyttäjältä
*   henkilön perustietoja. Kun taulukko täynnä
*   ohjelma ilmoittaa siitä.
*
*/

#include <iostream>
#include <string>

using namespace std;

/** Tietue joka tulee pitämään sisällään
*   nimen, koulumatkan pituuden sekä hatun
*   koon. Oletuksena etunimi- jäsen alustetaan tilaan
*   "empty" jotta voidaan tietää mikä alkio on ns. tyhjä.
*/
struct tietue {
    string etunimi;
    float koulumatka;
    int hattukoko;
    tietue(): etunimi("empty"), koulumatka(0.0), hattukoko(0) {}
};

/** Globaalien muuttujien määrittelyt. Taulukon koko
*   määritetty vakiomuuttujassa. tauluTemp tässä koska
*   osoitinta ei voi määrittää vakion kautta. Aliohjelmien
*   esimääritykset myös.
*/
const int taulunkoko = 10;
int tauluTemp = taulunkoko;
int *pTauluKoko = &tauluTemp;
bool taynna = false;

int valikko(void);
void TulostaHenkilo(tietue TIEDOT[]);
void TulostaKaikkiHenkilot(tietue TIEDOT[], int lkm);
void LisaaHenkilo(tietue TIEDOT[], int *lkm);

/** Ohjelman main funktio
*
*/
int main(void)
{
    /** tietuetaulukon kokona 10 alkiota,
    *   määritetty vakiomuuttujassa taulunkoko
    */
    tietue hRekisteri[taulunkoko];
    int valinta = 99;

    do {

        /** Valikosta poistuminen
        *   syöttämällä 0
        */
        valinta = valikko();
        if (valinta == 0) { break; }

        /** Valikosta valinnalla 1
        *   lisätään henkilötieto
        */
        else if (valinta == 1) {

                LisaaHenkilo(hRekisteri,pTauluKoko);
        }

        /** Listaa käyttäjän haluaman
        *   henkilön tiedot
        *
        */
        else if (valinta==2) {
            TulostaHenkilo(hRekisteri);
        }

        /** Listaa kaikki henkilötiedot
        *   taulukosta
        */
        else if (valinta == 3) {
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
    cout << "2 - Listaa tietty henkilo" << endl;
    cout << "3 - Listaa kaikki henkilot" << endl;
    cin >> valinta;
    return valinta;
}

/** Aliohjelma joka hakee henkilön tiedot
*   syötetyn nimen perusteella
*/
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
*   tietuetaulukossa TIEDOT
*
*/
void TulostaKaikkiHenkilot(tietue TIEDOT[], int lkm) {
    for (int a = 0; a < lkm; a++) {
        cout << "Henkilö " << a << ": " << TIEDOT[a].etunimi << " "
        << TIEDOT[a].koulumatka << " " << TIEDOT[a].hattukoko << endl;
    }
}

/** Henkilön lisäämiseen tarkoitettu
*   aliohjelma. Tarkistaa myös onko tilaa tiedoille.
*/
void LisaaHenkilo(tietue TIEDOT[], int *lkm) {
    int kohta = 99;
    for (int a = 0; a < *lkm; a++) {
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
        if (kohta == *lkm - 1) { taynna = true; }
    }

    else if (taynna) { cout << endl << "Taulukko täynnä!" << endl; }
}
