#include <iostream>

using namespace std;

#pragma once

class stack_t {

public:

    stack_t* head;

    stack_t() {
        head = NULL;
    };

    ~stack_t() {
       
        delete head;

        head = NULL;
    }

    bool isEmpty();

    void push(float value);

    float top();

    void pop();

    void print();


private:

    float value = 0;
    stack_t* next = NULL;

};

