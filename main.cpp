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

const int taulunkoko = 2;

int main()
{
    // tietuetaulukon kokona 10 alkiota
    tietue hRekisteri[taulunkoko];
    int valinta = 99;
    int kohta = 0;
    bool taynna = false;

    do {
        // Valikko n�kyville
        cout << endl;
        cout << "VALIKKO" << endl;
        cout << "0 - Lopeta" << endl;
        cout << "1 - Lisaa henkilo" << endl;
        cout << "2 - Listaa kaikki henkilot" << endl;
        cin >> valinta;

        if (valinta == 0) { break; }

        /** Oletuksena taulukon etunimi- j�sen on "empty" jotta voidaan tiet�� mik�
        *   alkio on ns. tyhj�. Ohjelma siis etsii aluksi tyhj�n kohdan johon voi lis�t�
        *   henkil�tietoja.
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
                    cout << "Henkil�n etunimi" << endl;
                    cin >> eNimi;
                    cout << "Henkil�n koulumatka" << endl;
                    cin >> kMatka;
                    cout << "Henkil�n hatun koko" << endl;
                    cin >> hKoko;
                    hRekisteri[kohta].etunimi = eNimi;
                    hRekisteri[kohta].koulumatka = kMatka;
                    hRekisteri[kohta].hattukoko = hKoko;
                    if (kohta == taulunkoko - 1) { taynna = true; }
                }

                else if (taynna) { cout << endl << "Taulukko t�ynn�!" << endl; }
        }

        /** Listaa henkil�tiedot
        *   taulukosta
        */
        else if (valinta == 2) {
            for (int a = 0; a < taulunkoko; a++) {
                cout << "Henkil� " << a << ": " << hRekisteri[a].etunimi << " "
                << hRekisteri[a].koulumatka << " " << hRekisteri[a].hattukoko << endl;
            }
        }

        else cout << "Valitse uudelleen";

    } while (valinta != 0);
}
