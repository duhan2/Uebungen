
#include "Sparkonto.hpp"
#include "Girokonto.hpp"


int main()
{
    Sparkonto sk;
    Girokonto gk((-250));
    
    Datum d(18,3,2000);

    sk.zahleEin(100,d);
    gk.zahleEin(100,d);

    sk.kontostand();
    gk.kontostand();

    sk.hebeAb(70, d);
    gk.hebeAb(300, d);

    sk.kontostand();
    gk.kontostand();

    sk.kontoauszug();
    gk.kontoauszug();


    cout << "Skrr!" << endl;

    return 0;
}

