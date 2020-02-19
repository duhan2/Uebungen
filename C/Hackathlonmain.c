#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct {

    char Kurzbezeichnung[5];
    char Teammitglieder[30];


}Team;

typedef struct {

    int Jurypunkte;
    int Publikumspunkte;

}Punkte;

typedef struct {

    Team Teamvariable;
    Punkte Punktevariable;

}Hackathon;

Hackathon * Pointervariable;

int main (){

Hackathon Hackathonvariable[3]; //= {"E-03","Peter, Paul und Mary",2,3};

char HilfsKurzbezeichnung[5];
char HilfsTemmitglieder[30];
int HilfsJurypunkte;
int HilfsPublikumspunkte;

  int i = 0;

  printf("Geben Sie ein an welche Stelle des Arrays Sie schreiben möchten 0-2\n"); 
  scanf("%d",&i);

    printf("Geben Sie eine Kurzbezeichnung ein\n");
    scanf("%4s",&HilfsKurzbezeichnung[0]);

    strcpy(Hackathonvariable[i].Teamvariable.Kurzbezeichnung, HilfsKurzbezeichnung);

    printf("Geben Sie die Namen der Mitglieder ein\n");
    scanf("%29s",&HilfsTemmitglieder[0]);

    strcpy(Hackathonvariable[i].Teamvariable.Teammitglieder, HilfsTemmitglieder);

    printf("Geben Sie Jurypunkte ein\n");
    scanf("%d",&HilfsJurypunkte);

    Hackathonvariable[i].Punktevariable.Jurypunkte = HilfsJurypunkte;

    printf("Geben Sie Publikumspunkte ein\n");
    scanf("%d",&HilfsPublikumspunkte);

    Hackathonvariable[i].Punktevariable.Publikumspunkte = HilfsPublikumspunkte;

    printf("Kurzbezeichnung: %s\n",Hackathonvariable[i].Teamvariable.Kurzbezeichnung);
    printf("Teammitglieder: %s\n",Hackathonvariable[i].Teamvariable.Teammitglieder);
    printf("Jurypunkte: %d\n",Hackathonvariable[i].Punktevariable.Jurypunkte);
    printf("Publikumspunkte: %d\n",Hackathonvariable[i].Punktevariable.Publikumspunkte);

/*
    Pointervariable = &Hackathonvariable;

    printf("Kurzbezeichnung: %s\n",Pointervariable->Teamvariable.Kurzbezeichnung);
    printf("Teammitglieder: %s\n",Pointervariable->Teamvariable.Teammitglieder);
    printf("Jurypunkte: %d\n",Pointervariable->Punktevariable.Jurypunkte);
    printf("Publikumspunkte: %d\n",Pointervariable->Punktevariable.Publikumspunkte);

*/
    printf("Hello World \n");

    return 0;
}
