#include <stdlib.h>
#include <stdio.h>
#include <time.h>

typedef struct heap_t{

    int value;
    struct heap_t* next;

}heap_t;

heap_t *head = NULL;

void insert(int value){

    struct heap_t* s = malloc(sizeof(struct heap_t));

    s->value = value;
    s->next = NULL;

    if (head == NULL) {
        s->next = head;
        head = s;
        return;
    }

    struct heap_t* temp = head;
    while(temp != NULL) {
        if(temp->next == NULL){
            break;
        }
        temp = temp->next;
    }

    s->next = temp->next;
    temp->next = s;

};



void print_heap(){

    heap_t *temp = head; 

    while(temp != NULL){

        printf("%d ",temp->value);

        temp = temp->next;

    }     

}

void extractmin(){

    heap_t *temp;

    if(head == NULL){

        return;

    }

    temp = head;
    
    head = temp->next;

    free(temp);

}

int min(){

    return head->value;

}


int main(){

    head = NULL;

    insert(1);
    insert(2);
    insert(3);

    print_heap();

    printf("Min Element = %d \n",min());

    extractmin();

    print_heap();


    printf("Hello World\n");

    return 0;

}
