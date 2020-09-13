#include "konto.hpp"
#include "Datum.hpp"

#pragma once

class Sparkonto : public konto{

    public:

        void hebeAb(int betrag, Datum d);


};

void Sparkonto::hebeAb(int betrag, Datum d){

    if((stand - betrag) < 0 ){
        cout << "Aktion wuerde Kontostand ins negative ziehen" << endl;
        return;
    }
    else{
        stand = stand - betrag;
        auszug = auszug +  "Aktion: Auszahlung Betrag: " + to_string(betrag) + " Datum: " + d.getDatum() + "\n";

    }

}; 