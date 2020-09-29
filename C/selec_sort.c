#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int findmin(int *a,int i ,int n){

    int min = i;

    for( i ; i < n;i++){
        if(a[min] > a[i]){
            min = i;
        }
    }

    return min;
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp; 
}

int * selectsort(int *a, int n){
    int min = 0;
    for(int i = 0; i < n; i ++){
        min = findmin(a,i,n);
        swap(&a[min],&a[i]);
    }

    return a;
}

int *create_arr(int n){

    srand(time(0));

    int *a = malloc( n * sizeof(int));

    for(int i = 0; i < n; i++){
        a[i] = rand()%100;
    }

    return a;
}

void print_arr(int * a, int n){

    for(int i = 0; i < n; i++){
        printf(" %d.Stelle: %d\n",i , a[i]);
    }

}

int main(){

    int n = 100;

    int *a = create_arr(n);

    print_arr(a,n);

    printf("\nSelection-Sort \n------------\n");

    
    

    // vor dem Aufruf der Sortierfunktion
    clock_t t1 = clock();

    a = selectsort(a,n); 

    // nach dem Aufruf der Sortierfunktion
    clock_t t2 = clock();
    double duration = (double)(t2 - t1)/(double)CLOCKS_PER_SEC;
    // Laufzeit duration und Gr ̈oße des Feldes ausgeben

    printf("Zeit: %lf \n",duration);

    print_arr(a,n);

    printf("Ende des Programms!\n");

    return 0;
}