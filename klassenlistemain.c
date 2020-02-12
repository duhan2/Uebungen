#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct schueler {

    char name[20];
    int alter;

}schueler;

typedef struct klasse{

    schueler schueler;

}klasse;

int main(){

int i = 0; 

printf("Geben Sie die Groesse der Klasse ein\n");
scanf("%d",&i);

printf("Ihre Eingabe lautet: %d\n",i);

printf("\n");

klasse A[i];

char hilfsname[20];
int hilfsalter;

for(int j = 0; j < i; j++){

    printf("Geben Sie den Namen des Schülers ein\n");
    scanf("%19s",&hilfsname[0]);

    printf("Geben Sie das Alter des Schülers ein\n");
    scanf("%d",&hilfsalter);

    strcpy(A[j].schueler.name, hilfsname);
    A[j].schueler.alter = hilfsalter; 

}

printf("\n");

for(int j = 0; j < i; j++){

    printf("%d. Name: %s Alter: %d \n",j+1,A[j].schueler.name,A[j].schueler.alter);

}

printf("Hello World\n");

return 0;
}
