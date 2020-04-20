#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100    //Makro für Arrraygröße

//Funktion für Schritt 3
void swap(int *x, int *y){      

    int temp;
    temp = *x;
    *x = *y;
    *y = temp;

}

//Funktion für Schritt 2
int findmin(int *array, int start, int ende){

    int min_stelle;

    min_stelle = start; 

   for(int i = start; i <= ende; i++){

        if(array[min_stelle] > array[i]){

            min_stelle = i;

        }

    }

    return min_stelle;
}

//Optionale Funktion für Ausgabe
void print(int *array){

    for(int i = 0; i < N; i++){

        printf("Array[%d] = %d \n",i,array[i]);

    }
}


int main(){

    //Für echte Zufallszahlen
    srand(time(0));
    
    //Array deklarieren
    int array[N];

    //Array initialisierem
    for(int i = 0; i < N; i++){

        array[i] = rand()%100; //Damit die Zahlen nicht grösser als 100

    }   
    
    //Ausgabe des Arrays
    printf("Unsortierter Durchlauf\n");
    print(array);
    
    int min;        //Variablen ausserhalb der Schleifen deklariert

    clock_t t1 = clock();

    for(int i = 0; i < N-1; i++){

        min  = findmin(array,i,N-1); 

        swap(&array[min],&array[i]);

    }

    clock_t t2 = clock();
    double duration = (double)(t2 - t1)/(double)CLOCKS_PER_SEC;

    printf("\nDie Laufzeit fuer %d Elemente betraegt: %4e\n",N,duration);

    printf("\nSortierter Durchlauf\n");
     
    //Wieder ausgeben um zu checken, ob das sortieren geklappt hat
    print(array);

    return 0;
}
