#include <iostream>

using namespace std;


class Unikat {

    private:

        static Unikat *_unikat_obj;

    protected:

        // Auschalten des Konstruktors
        Unikat(){};

        // Auschalten des Copy - Konstruktors
        Unikat(const Unikat &) = delete;

        // Ausschalten des Zuweisungsoperators
        Unikat & operator = (Unikat &) = delete;

    public:
    
        int wert = 0;

        static Unikat * exemplar(){

            if(Unikat :: _unikat_obj  == 0){

                Unikat :: _unikat_obj = new Unikat();

            }

            return Unikat::_unikat_obj;
        }
};

Unikat *Unikat::_unikat_obj = 0;

int main(){

    Unikat * no1 = Unikat::exemplar ();
    Unikat * no2 = Unikat::exemplar ();
    Unikat * no3 = Unikat::exemplar (); 

    no1->wert = 42;
    cout << " 1: " << no1->wert << endl ;
    cout << " 2: " << no2->wert << endl ;
    cout << " 3: " << no3->wert << endl ;

    return 0;
}