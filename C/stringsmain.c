#include <stdio.h>
#include <string.h>
#include <stdlib.h>



int main() {

    int count;

    int ptr = 0;

    printf("Geben Sie die Anzahl der einzugebenden Wörter ein:\n");
    scanf("%d",&count);

    char* strings; 
    strings = calloc(count, sizeof(strings)) ;

    
    for(int i = 0; i < count; i++){

        printf("Geben Sie die Zeichenkette ein: ");
        scanf("%999s", &strings[ptr]);
    
        while (strings[ptr]!= 0)
        {
            ptr += 1;
        }
         
        ptr +=1;

        //printf("Wert von ptr: %d\n",ptr);
      
    }

    printf("\n");

    printf("Inhalt von strings, ausgegeben char fuer char:\n");

    for(int i = 0; i < ptr; i++){
        printf("%c",strings[i]);
    }

    printf("\n");

    //printf("strings: %s\n",strings);

    //printf("Hallo Welt!\n");


    free(strings);

    return 0;
}
