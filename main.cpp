#include "search.hpp"

#include <iostream>

int main()
{
    int p[] = {5,4,3,2,1};
    quicksort(p, 5);
    
    for (int q = 0; q < 5; q++) {
        printf("%i\t", p[q]);
    }
    printf("\n");
    
    return 0;
    
}
