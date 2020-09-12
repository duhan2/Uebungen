#include "h_stack_t.h"

template<class T>

bool stack_t<T>::isEmpty() {
    if (head == NULL) {
        return true;
    }
    else {
        return false;
    }
}

template<class T>

void stack_t<T>::push(T value) {

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

template<class T>

void stack_t<T>::print() {
    stack_t* temp = head;
    while (temp != NULL) {

        std::cout << temp->value << std::endl;
        temp = temp->next;

    }
}

template<class T>
 T stack_t<T>::top() {

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
        std::cerr << err_string << std::endl;
        return 0;
    };
    
}

template<class T>

void stack_t<T>::pop() {

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
        std::cerr << err_string << std::endl;
    };
}
