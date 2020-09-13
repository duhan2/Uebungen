#include "h_heap_t.h"


int main()
{

    int a[10];

    int* ptr = a;

    for (int i = 0; i < 10; i++) {
        a[i] = i;
    }
    
    a[9] = 99;

    heap_t <float> entity(ptr);

    entity.print();

    entity.extractMin();

    std::cout << entity.minimum() << std::endl;

    entity.~heap_t();

    entity.print();

    std::cout << "Skrr!" << std::endl;

    return 0;
}
