#include <stdlib.h>
#include <stdio.h>
#include <time.h>

typedef struct pqentry_t
{

    char * value;
    float priority;

}pqentry_t;

typedef struct pqueue_t
{

    pqentry_t *element ;
    struct pqueue_t * next;
    
}pqueue_t;

pqueue_t * head = NULL;

pqueue_t* pq_create()
{

    head = NULL;

    return head;

};

void pq_insert( char *value, float p)
{

    struct pqueue_t * pq = (pqueue_t*) malloc(sizeof(struct pqueue_t));

    pq->element =(pqentry_t*) malloc(sizeof(struct pqentry_t));

    pq->element->value = value;
    pq->element->priority = p;
    pq->next = NULL;

    if(head == NULL)
    {
        pq->next = head;
        head = pq;
        return;
    }

    struct pqueue_t * temp = head;

    while(temp!=NULL)
    {   

        if (temp->next == NULL)     //if temp is on the last position
        {
            break;
        }

        if(temp->next->element->priority >= p)
        {
            break;
        }

        
        temp = temp->next;
    }

    pq->next = temp->next;
    temp->next = pq; 

};

void print_queue()
{

    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    pqueue_t *temp = head; 

    while(temp != NULL)
    {

        printf("value: %s, priority: %f\n",temp->element->value,temp->element->priority);

        temp = temp->next;

    }     

}


void extractmin(){

    pqueue_t *temp;

    if(head == NULL)
    {

        return;

    }

    temp = head;
    
    head = temp->next;

    free(temp);

}

char* min()
{

    return head->element->value;

}

void pq_remove( char* value)
{

    pqueue_t *temp = head;

    if(head == NULL)
    {

        return;

    }

    while(temp != NULL)
    {

        if(temp->next == NULL)
        {
            break;
        }

        if(temp->next->element->value == value)
        {
            temp->next = temp->next->next;
            return;
        }

        temp = temp->next;

    }  


};

void pq_destroy(){

    free(head);
    head = NULL;

};

void pq_decreaseKey(char* value, float p)
{

    pq_remove(value);
    pq_insert(value,p);
    

};

int main(){

    pq_create();

    pq_insert("Duhan",1);
    pq_insert("Eymen",2);
    pq_insert("Yaren",3);
    pq_insert("Ecren",4);

    //print_queue();

    //printf("\n");

    //printf("Min Element = %s \n",min());

    //extractmin();
    //print_queue();

    //printf("\n");

    pq_insert("Beren",5);

    print_queue();

    //printf("\n");

    //pq_remove("Yaren");

    //print_queue();

    printf("\n");

    pq_decreaseKey("Yaren",1);

    print_queue();


    printf("Hello World\n");

    return 0;

}
