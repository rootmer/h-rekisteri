/** Ohjelma joka ottaa vastaan k�ytt�j�lt�
*   henkil�n perustietoja. Kun taulukko t�ynn�
*   ohjelma ilmoittaa siit�.
*
*/

#include <iostream>
#include <string>

using namespace std;

/** Tietue joka tulee pit�m��n sis�ll��n
*   nimen, koulumatkan pituuden sek� hatun
*   koon. Oletuksena etunimi- j�sen alustetaan tilaan
*   "empty" jotta voidaan tiet�� mik� alkio on ns. tyhj�.
*/
struct tietue {
    string etunimi;
    float koulumatka;
    int hattukoko;
    tietue(): etunimi("empty"), koulumatka(0.0), hattukoko(0) {}
};

/** Globaalien muuttujien m��rittelyt. Taulukon koko
*   m��ritetty vakiomuuttujassa. tauluTemp t�ss� koska
*   osoitinta ei voi m��ritt�� vakion kautta. Aliohjelmien
*   esim��ritykset my�s.
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
    *   m��ritetty vakiomuuttujassa taulunkoko
    */
    tietue hRekisteri[taulunkoko];
    int valinta = 99;

    do {

        /** Valikosta poistuminen
        *   sy�tt�m�ll� 0
        */
        valinta = valikko();
        if (valinta == 0) { break; }

        /** Valikosta valinnalla 1
        *   lis�t��n henkil�tieto
        */
        else if (valinta == 1) {

                LisaaHenkilo(hRekisteri,pTauluKoko);
        }

        /** Listaa k�ytt�j�n haluaman
        *   henkil�n tiedot
        *
        */
        else if (valinta==2) {
            TulostaHenkilo(hRekisteri);
        }

        /** Listaa kaikki henkil�tiedot
        *   taulukosta
        */
        else if (valinta == 3) {
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
    cout << "2 - Listaa tietty henkilo" << endl;
    cout << "3 - Listaa kaikki henkilot" << endl;
    cin >> valinta;
    return valinta;
}

/** Aliohjelma joka hakee henkil�n tiedot
*   sy�tetyn nimen perusteella
*/
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
*   tietuetaulukossa TIEDOT
*
*/
void TulostaKaikkiHenkilot(tietue TIEDOT[], int lkm) {
    for (int a = 0; a < lkm; a++) {
        cout << "Henkil� " << a << ": " << TIEDOT[a].etunimi << " "
        << TIEDOT[a].koulumatka << " " << TIEDOT[a].hattukoko << endl;
    }
}

/** Henkil�n lis��miseen tarkoitettu
*   aliohjelma. Tarkistaa my�s onko tilaa tiedoille.
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
        cout << "Henkil�n etunimi" << endl;
        cin >> eNimi;
        cout << "Henkil�n koulumatka" << endl;
        cin >> kMatka;
        cout << "Henkil�n hatun koko" << endl;
        cin >> hKoko;
        TIEDOT[kohta].etunimi = eNimi;
        TIEDOT[kohta].koulumatka = kMatka;
        TIEDOT[kohta].hattukoko = hKoko;
        if (kohta == *lkm - 1) { taynna = true; }
    }

    else if (taynna) { cout << endl << "Taulukko t�ynn�!" << endl; }
}
