#include <iostream>

using namespace std;

int eins[] = {2,4,6,8,10};                      //  globale  Arrays
int zwei[] = {1,2,3,4,5,6,7,8,9,10};

int lEins = 5;
int lZwei = 10;

bool teilfolge(int p1 ,int p2) {                //  Prueffunktion

    if(p2 >= lZwei){
        return false;
    }

    if(eins[p1] == zwei[p2]){
        if(p1 == (lEins - 1)){
            return true;
        }
        teilfolge((p1+1),(p2+1));
    }
    else{
        if(p2 == lZwei){
            return false;
        }
        teilfolge(p1 ,(p2+1));
    }

};

int main(){

    if(teilfolge(0, 0)){
        cout  << "ja" << endl;   
    }
    else{
        cout  << "nein" << endl;
    }


    return 0;
}
