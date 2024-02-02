#include "asunto.h"

Asunto::Asunto() {
    std::cout << "Asunto luotu" << std::endl;
    maarita(2, 100);
}

void Asunto::maarita(int asukasMaara, int neliot) {
    this->asukasMaara = asukasMaara;
    this->neliot = neliot;
    std::cout << "Asunto maaritelty - Asukkaita: " << asukasMaara << ", Neliot: " << neliot << std::endl;
}

double Asunto::laskeKulutus(double kulutus) {
    double kokonaisKulutus = kulutus * neliot;
    std::cout << "Kokonaiskulutus: " << kokonaisKulutus << std::endl;

    return kokonaisKulutus;
}

void Kerros::maarita(int asukasMaara, int neliot, int kerrosNumero) {
    std::cout << "Kerros luotu" << std::endl;
    Asunto::maarita(asukasMaara, neliot);
    this->kerrosNumero = kerrosNumero;
}

double Kerros::laskeKulutus(double kulutus) {
    double kerrosKulutus = Asunto::laskeKulutus(kulutus) + kerrosNumero;

    // std::cout << "Kerroskulutus: " << kerrosKulutus << std::endl;

    return kerrosKulutus;
}

void Katutaso::maarita(int asukasMaara, int neliot, int kerrosNumero, bool onkoLiiketila) {
    std::cout << "Katutaso luotu" << std::endl;
    Kerros::maarita(asukasMaara, neliot, kerrosNumero);
    this->onkoLiiketila = onkoLiiketila;
}

double Katutaso::laskeKulutus(double kulutus) {
    double katutasoKulutus = Kerros::laskeKulutus(kulutus) + (onkoLiiketila ? 10.0 : 0.0);


    // std::cout << "Katutasokulutus: " << katutasoKulutus << std::endl;

    return katutasoKulutus;
}



Kerrostalo::Kerrostalo() {
    std::cout << "Kerrostalo luotu" << std::endl;
}

void Kerrostalo::maaritaAsunnot() {
    eka.maarita(2, 100, 1, true);
    toka.maarita(2, 100, 2);
    kolmas.maarita(2, 100, 3);
}

double Kerrostalo::laskeKulutus(double hinta) {
    double kulutus = eka.laskeKulutus(hinta) + toka.laskeKulutus(hinta) + kolmas.laskeKulutus(hinta);
    std::cout << "Kerrostalon kokonaiskulutus: " << kulutus << std::endl;
    return kulutus;
}

int main() {

    Katutaso katutaso1;
    katutaso1.maarita(2, 100, 2290, false);

    Kerros kerros1, kerros2, kerros3, kerros4;
    kerros1.maarita(2, 100, 1);
    kerros2.maarita(2, 100, 2);
    kerros3.maarita(2, 100, 3);
    kerros4.maarita(2, 100, 4);
    Kerrostalo kerrostalo;
    double hinta = 1.0;
    double katutasoKulutus = katutaso1.laskeKulutus(hinta);
    double kerrosKulutus = kerros1.laskeKulutus(hinta) + kerros2.laskeKulutus(hinta) +kerros3.laskeKulutus(hinta) + kerros4.laskeKulutus(hinta);

    std::cout << "Katutason ja perityn kerroksen kulutus, kun hinta = " << hinta << " on " << katutasoKulutus + kerrosKulutus << std::endl;

    return 0;
}
