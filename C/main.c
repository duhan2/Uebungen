#include <stdlib.h>
#include <stdio.h>
#include <time.h>

typedef struct stack_t{

    float value;
    struct stack_t* next;

}stack_t;

stack_t *head = NULL;

void push(float value){

    stack_t *s = (stack_t*)malloc(sizeof(stack_t*));
    s->value = value;
    s->next = head;

    head = s;
};

float top(){

    return head->value;

};

void pop(){

    stack_t *temp;

    if(head == NULL){

        return;

    }

    temp = head;
    head = head->next;

    free(head);

}

void print_stack(){

    stack_t *temp = head; 

    while(temp != NULL){

        printf("%.2f ",temp->value);

        temp = temp->next;

    }     

}

int main(){

    push(1);
    push(2);
    push(3);

    print_stack();

    printf("value on Top = %.2f\n",top());

    printf("Hello World\n");

    return 0;

}