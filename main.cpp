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

const int taulunkoko = 2;

int main()
{
    // tietuetaulukon kokona 10 alkiota
    tietue hRekisteri[taulunkoko];
    int valinta = 99;
    int kohta = 0;
    bool taynna = false;

    do {
        // Valikko näkyville
        cout << endl;
        cout << "VALIKKO" << endl;
        cout << "0 - Lopeta" << endl;
        cout << "1 - Lisaa henkilo" << endl;
        cout << "2 - Listaa kaikki henkilot" << endl;
        cin >> valinta;

        if (valinta == 0) { break; }

        /** Oletuksena taulukon etunimi- jäsen on "empty" jotta voidaan tietää mikä
        *   alkio on ns. tyhjä. Ohjelma siis etsii aluksi tyhjän kohdan johon voi lisätä
        *   henkilötietoja.
        */
        else if (valinta == 1) {
                for (int a = 0; a < taulunkoko; a++) {
                    if (hRekisteri[a].etunimi == "empty") {
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
                    hRekisteri[kohta].etunimi = eNimi;
                    hRekisteri[kohta].koulumatka = kMatka;
                    hRekisteri[kohta].hattukoko = hKoko;
                    if (kohta == taulunkoko - 1) { taynna = true; }
                }

                else if (taynna) { cout << endl << "Taulukko täynnä!" << endl; }
        }

        /** Listaa henkilötiedot
        *   taulukosta
        */
        else if (valinta == 2) {
            for (int a = 0; a < taulunkoko; a++) {
                cout << "Henkilö " << a << ": " << hRekisteri[a].etunimi << " "
                << hRekisteri[a].koulumatka << " " << hRekisteri[a].hattukoko << endl;
            }
        }

        else cout << "Valitse uudelleen";

    } while (valinta != 0);
}
