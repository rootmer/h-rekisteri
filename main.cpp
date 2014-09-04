/** Ohjelma joka ottaa vastaan käyttäjältä
*   henkilön perustietoja. Kommentoitia lisää
*   myöhemmin..
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
    tietue(): etunimi("empty") {}
};

int main()
{
    // tietuetaulukon kokona 10 alkiota
    tietue hRekisteri[10];
    int valinta = 99;
    int kohta = 0;

    do {
        // Valikko näkyville
        cout << endl;
        cout << "VALIKKO" << endl;
        cout << "0 - Lopeta" << endl;
        cout << "1 - Lisaa henkilo" << endl;
        cout << "2 - Listaa kaikki henkilot" << endl;
        cin >> valinta;

        if (valinta == 0) { break; }

        else if (valinta == 1) {
                for (int a = 0; a < 10; a++) {
                    if (hRekisteri[a].etunimi == "empty") {
                        kohta = a;
                    }
                }

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
        }

        else if (valinta == 2) {
            for (int a = 0; a < 10; a++) {
                cout << "Henkilö " << a << ": " << hRekisteri[a].etunimi << " "
                << hRekisteri[a].koulumatka << " " << hRekisteri[a].hattukoko << endl;
            }
        }

        else cout << "Valitse uudelleen";

    } while (valinta != 0);
}
