#include <iostream>
#include <string>

using namespace std;

#pragma once

class Datum{

    public:

    Datum(int d, int m, int j){
        Tag = d;
        Monat = m;
        Jahr = j;
    }

    string getDatum(){
        
        string s = to_string(Tag) + '.' + to_string(Monat) + '.' + to_string(Jahr);

        return s;

    }

    private:
    int Tag = 0;
    int Monat = 0;
    int Jahr = 0;
};