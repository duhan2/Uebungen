#include <iostream>

#pragma once

//using namespace std;

template<class T>

class heap_t {

public:

    heap_t* head;

    heap_t() {
        head = NULL;
    };

    heap_t(int* values) {
        head = NULL;

        int i = 0;

        while ((*(values + i)) != 99) {

           insert(*(values + i));
           i++;
        }

    };


    ~heap_t() {

        delete head;

        head = NULL;
    }

    bool isEmpty();

    void insert(T value);

    T minimum();

    void extractMin();

    void print();


private:

    T value = 0;
    heap_t* next = NULL;

};

template<class T>

bool heap_t<T>::isEmpty() {
    if (head == NULL) {
        return true;
    }
    else {
        return false;
    }
}

template<class T>

void heap_t<T>::insert(T value) {

    heap_t* element = new heap_t();
    element->value = value;

    if (isEmpty() == true) {
        head = element;
        return;
    }

    heap_t* temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = element;
}

template<class T>

void heap_t<T>::print() {
    heap_t* temp = head;
    while (temp != NULL) {

        std::cout << temp->value << std::endl;
        temp = temp->next;

    }
}

template<class T>
T heap_t<T>::minimum() {

    try {

        heap_t* temp = head;

        if (temp == NULL) {
            throw "Heap is empty";
        }

        return temp->value;

    }
    catch (const char* err_string) {
        std::cerr << err_string << std::endl;
        return 0;
    };

}

template<class T>

void heap_t<T>::extractMin() {

    try {

        heap_t* temp = head;

        if (temp == NULL) {
            throw "Heap is empty";
            //return;
        }

        head = head->next;

        delete temp;

        temp = NULL;

    }
    catch (const char* err_string) {
        std::cerr << err_string << std::endl;
    };
}


