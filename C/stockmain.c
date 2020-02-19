//
//  stock.c
//
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
 
 
/* structure to store all information about items */
 
struct item_s {
    // each item has a unique id to clearly identify it
    unsigned id;
    // manufacturer and model
    char manufacturer [16];
    char model [16];
    // where the item is stored: rack and position within rack
    unsigned rack;
    unsigned position;
    // number of items in stock
    unsigned quantity;
};
 
 
#define MAX_NR_ITEMS 10000
/* all items in stock */
struct item_s stock[MAX_NR_ITEMS];
/* number of items in stock */
unsigned stock_size = 0;
 
 
/* read at most max_nr items from file "filename" and write them to array items
 * the number of items actually read is returned */
 
void read_items_from_file(char *filename)
{
    // storage to preliminarily store the information of an item
    unsigned id; char manufacturer[16]; char model[16];
    unsigned rack; unsigned position; unsigned quantity;
    // number of tokens read from current input line
    size_t len = 0;
   
    // open the input file for reading
    FILE * fp = fopen(filename, "r");
    if (fp == NULL)
    {
        // if file could not be opened (wrong path, not readable, ...)
        // output a short message and immediately exit
        char resp;
        printf("Eingabedatei kann nicht geoeffnet werden.\n");
        scanf("%c", &resp);
        exit(EXIT_FAILURE);
    }
   
    // the following loop reads a new item in every iteration
    // until the end of the file (or an invalid entry appears)
    len = fscanf(fp, "%i %s %s %i %i %i", &id, &manufacturer, &model, &rack, &position, &quantity);
 
    // as long as there is space in the array and a correct line is read
    while ((stock_size < MAX_NR_ITEMS) && (len == 6))
    {
        // printf("Lese Element: %i\n", id);
        stock[stock_size].id = id;
        strcpy(stock[stock_size].manufacturer, manufacturer);
        strcpy(stock[stock_size].model, model);
        stock[stock_size].rack = rack;
        stock[stock_size].position = position;
        stock[stock_size].quantity = quantity;
        stock_size++;
        // reading next item
        len = fscanf(fp, "%i %s %s %i %i %i", &id, &manufacturer, &model, &rack, &position, &quantity);
    }
   
    // finally close the input file
    fclose(fp);
}
 
 
/* compare function for items which orders them by ID */
 
int order_items_by_id(const void *i1, const void *i2)
{
    // first convert pointers to correct type
    struct item_s *item1 = (struct item_s *)i1;
    struct item_s *item2 = (struct item_s *)i2;
    if( item1->id > item2->id ) return 1;
    else if ( item1->id < item2->id ) return -1;
    else return 0;
}
 
int order_items_by_rack(const void *i1, const void *i2)
{
    // first convert pointers to correct type
    struct item_s *item1 = (struct item_s *)i1;
    struct item_s *item2 = (struct item_s *)i2;
    if( item1->rack > item2->rack ) return 1;
    else if ( item1->rack < item2->rack ) return -1;
    else return 0;
}
 
 
 
/* function that checks whether some item is in stock */
 
unsigned item_in_stock( unsigned item_id ) {
    for(int i=0; i<stock_size; i++) {
        if( item_id == stock[i].id ) return 1;
    }
    return 0;
}
 
unsigned index_of_item( unsigned item_id)
{
    for(int i=0; i<stock_size; i++) {
        if( item_id == stock[i].id ) return i;
    }
    return 0;
}
 
 
// --- part 1
 
void enter_desired_items(unsigned ID, unsigned number)
{
    unsigned index, nr = number;
    if(item_in_stock(ID) == 1)
    {
        index = index_of_item(ID);
        if(number > stock[index].quantity)
        {
            do{
                printf("Die Anzahl die Sie entnehmen möchten ist größer als die vorhandene Anzahl. Bitte geben Sie eine andere Anzahl an: ");
                scanf("%i", nr);
            }while(nr > stock[index].quantity);
        }
        else{
            printf("Die Anzahl des Artikel wird um %i verringert. Die neue Anzahl ist %i", nr, stock[index].quantity - nr);
            printf("\nDer Artikel ist gelagert im Regal %i an der Position %i", stock[index].rack, stock[index].position );
        }
    }
}
 
void remove_items_from_stock(unsigned id, unsigned nr)
{
    stock[index_of_item(id)].quantity -= nr;
}
 
// --- part 2
 
struct item_s enter_new_item(unsigned id);
 
void add_items_to_stock(unsigned id, unsigned nr)
{
    unsigned rack, position, number = nr;
    char manufacturer[16], model[16];
    if(item_in_stock(id) == 1)
    {
        unsigned index = index_of_item(id);
        printf("Der Artikel befindet sich bereits im Lager.\n");
        stock[index].quantity += number;
        printf("Die Anzahl des Artikel wird um %i erhöht.", number);
    }
    else{
        stock[stock_size].quantity = nr;
        stock[stock_size].id = id;
        printf("Bitte geben Sie den Hersteller des Artikles an: ");
        scanf("%s", &manufacturer);
        while (getchar() != '\n');
        strcpy(stock[stock_size].manufacturer, manufacturer);
        printf("Bitte geben Sie die Modellnummer des Artikles an: ");
        scanf("%s", &model);
        strcpy(stock[stock_size].model, model);
        while (getchar() != '\n');
        printf("Bitte geben Sie das Regal und die Position ein an der die Artikel gelagert werden sollen(Regal,Position): ");
        scanf("%i,%i", &rack, &position);
        stock[stock_size].rack = rack;
        stock[stock_size].position = position;
        printf("\nDer Artikle wurde zum Inventar hinzugefügt.");
        stock_size++;
    }
}
 
// --- part 3 (preliminary solution)
 
void print_stock()
{
    qsort(stock,stock_size ,sizeof(struct item_s),order_items_by_rack);
    for(unsigned i=0; i<stock_size; i++)
        printf("%04i %s %s - rack %i/pos %i - #items: %i\n",
               stock[i].id,
               stock[i].manufacturer,
               stock[i].model,
               stock[i].rack,
               stock[i].position,
               stock[i].quantity );
}
 
// --- part 4
 
void save_items_to_file(char *filename){
    FILE *fp = fopen(filename, "w");
    if(fp == NULL){
        printf("Error opening file!\n");
        return;
    }
    else{
        for(unsigned i=0; i<stock_size; i++)
        fprintf(fp,"%i %s %s %i %i %i\n",
                stock[i].id,
                stock[i].manufacturer,
                stock[i].model,
                stock[i].rack,
                stock[i].position,
                stock[i].quantity );
    }
    printf("\nInventar erfolgreich gespeichert.");
    fclose(fp);
}
 
/*
 * main function: entry of point
 */
 
int main()
{
    // print program header
    printf("\n\n");
    printf("HAUPTMENU\n");
    printf("---------\n\n");
   
    // read intial stock from files
    read_items_from_file("lager.txt");
   
    //
    do {
        // read the name to be searched
        printf("\n\nWas wollen Sie tun?\n");
        printf("(1) Entnahme von Elementen\n");
        printf("(2) Hinzufuegen von Elementen\n");
        printf("(3) aktuellen Lagerbestand speichern\n");
        printf("(4) Inventarliste ausgeben\n");
        printf("(0) Programm beenden\n");
        printf("\tIhre Wahl: ");
       
        unsigned  choice;
        int ID, number;
        scanf("%d", &choice);
        while (getchar() != '\n');
        // menu items
        switch(choice)
        {
            case 1:
               
                printf("Bitte geben Sie die Id von dem Artikel den Sie entnehmen wollen an: ");
                scanf("%i", &ID);
                while (getchar() != '\n');
                printf("Bitte geben Sie an wie viele Artikel Sie entnehmen wollen: ");
                scanf("%i", &number);
                while (getchar() != '\n');
                if(number <= 0)
                {
                    do{
                        printf("Bitte geben Sie eine größere Anzahle ein: ");
                        scanf("%i", number);
                    }while(number <= 0);
                }
                enter_desired_items(ID, number);
                remove_items_from_stock(ID, number);
               
                break;
            case 2:
                printf("Bitte geben Sie die ID ein zu der Sie Artikel hizufügen möchten/ neue Artikel in das Lager aufnehmen wollen: ");
                scanf("%i", &ID);
                while (getchar() != '\n');    
                printf("Bitte geben Sie die Anzahl des Artikels an die Sie zum Lager hinzufügen: ");
                scanf("%i", &number);
                while (getchar() != '\n');
                add_items_to_stock(ID,number);
                break;
            case 3:
                save_items_to_file("lager.txt");
                break;
            case 4:
                print_stock();
                break;
            case 0:
                return 0;
            default:
                printf("Ungueltige Eingabe.\n");
        }
       
    } while(1);
}
