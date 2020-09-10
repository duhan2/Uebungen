#include "h_stack_t.h"

bool stack_t::isEmpty() {
    if (head == NULL) {
        return true;
    }
    else {
        return false;
    }
}

void stack_t::push(float value) {

    stack_t* element = new stack_t;
    element->value = value;

    if (isEmpty() == true) {
        head = element;
        return;
    }

    stack_t* temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = element;
}

void stack_t::print() {
    stack_t* temp = head;
    while (temp != NULL) {

        cout << temp->value << endl;
        temp = temp->next;

    }
}

float stack_t::top() {

    try {

        stack_t* temp = head;

        if (temp == NULL) {
            throw "Stack is empty";
        }

        while (temp->next != NULL) {

            temp = temp->next;
        }

        return temp->value;

    }
    catch(const char* err_string){
        cerr << err_string << endl;
        return 0;
    };
    
}

void stack_t::pop() {

    try{

        stack_t* temp = head;

        if (temp == NULL) {
            throw "Stack is empty";
            //return;
        }

        while (temp->next->next != NULL) {
        
            temp = temp->next;

        }

        stack_t* temp2 = temp->next;

        temp->next = temp2->next;

        delete temp2;

    }
    catch (const char* err_string) {
        cerr << err_string << endl;
    };
}

