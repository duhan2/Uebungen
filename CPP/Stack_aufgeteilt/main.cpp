#include "h_stack_t.h"


int main()
{
    stack_t entity;

    entity.push(1.0);
    entity.push(2.0);
    entity.push(3.0);
    entity.push(4.0);

    entity.print();

    

    //entity.pop();
    //entity.print();

    entity.~stack_t();

    cout << entity.top() << endl;

    entity.pop();

    entity.print();

    cout << "Skrr!" << endl;

    return 0;
}

