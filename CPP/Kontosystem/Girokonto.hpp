#include "konto.hpp"
#include "Datum.hpp"

#pragma once

class Girokonto : public konto{

    public:

        Girokonto(unsigned int dis){
            dispo = dis;
        }

        void hebeAb(int betrag, Datum d);
        void ueberweise(string kontonr, int betrag, Datum d);

    private:

        unsigned int dispo = 0;

};

void Girokonto::hebeAb(int betrag, Datum d){

    if((stand - betrag) < dispo){
        cout << "Aktion fehlgeschlagen, Limit waere ueberzogen worden" << endl;

    }
    else{
        stand = (stand - betrag);
        auszug = auszug +  "Aktion: Auszahlung Betrag: " + to_string(betrag) + " Datum: " + d.getDatum() + "\n";

    }

}

void Girokonto::ueberweise(string kontonr, int betrag, Datum d){

    if((stand - betrag) < dispo){

        cout << "Transaktion fehlgeschlagen, Limit waere ueberzogen worden" << endl;

    }
    else{

        stand = (stand - betrag);
        auszug = auszug +  "Aktion: Ueberweisung Betrag: " + to_string(betrag) + " Datum: " + d.getDatum() + "\n";
    }

};
