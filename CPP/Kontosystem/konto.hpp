#include "Datum.hpp"

#pragma once

class konto{

    public:

        virtual void hebeAb(int betrag, Datum d);
        void zahleEin(int betrag, Datum d);
        int kontostand();
        string kontoauszug();


    protected:
        string auszug = "Kontoauszug:\n";
        int stand = 0;

};

void konto::hebeAb(int betrag, Datum d){
    cout << "BASEKLASSE" << endl;
}

void konto::zahleEin(int betrag, Datum d){
    stand = stand + betrag;
    auszug = auszug +  "Aktion: Einzahlung Betrag: " + to_string(betrag) + " Datum: " + d.getDatum() + "\n";
}

int konto::kontostand(){

    cout << "Kontostand: " << stand << "Euro" << endl;

    return stand;
}

string konto::kontoauszug(){
    cout << auszug << endl;
    return auszug;
}
