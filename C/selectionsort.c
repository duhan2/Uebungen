#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(){

    //Für echte Zufallszahlen
    srand(time(0));
    
    //Array deklarieren
    int array[10];

    //Array initialisierem
    for(int i = 0; i < 10; i++){

        array[i] = rand()%100; //Damit die Zahlen nicht grösser als 100

    }

    printf("Unsortierter Durchlauf\n");

    //Ausgabe des Arrays
    for(int i = 0; i < 10; i++){

        printf("Array[%d] = %d \n",i,array[i]);

    }
    
    int min;        //Variablen ausserhalb der Schleifen deklariert
    int temp;       // hat 2 Gründe

    //Schritt 1
    for(int i = 0; i < 10; i++){

        min = i;
        
        //Schritt 2
        for(int j = i + 1; j < 10; j++){

            if(array[min] > array[j]){

                //Schritt 3
                temp = array[min];
                array[min] = array[j];
                array[j] = temp;

            }

        }

    }

    printf("\nSortierter Durchlauf\n");

    //Wieder ausgeben um zu checken ob das sortieren geklappt hat
    for(int i = 0; i < 10; i++){

        printf("Array[%d] = %d \n",i,array[i]);

    }

    printf("\nHallo Mo\n");

    return 0;
}
