#include <iostream>
using namespace std;

int main()
{
    int aux, prev, next;
    int array[5] = {3, 2, 1, 5, 4};

    for (prev = 0; prev < 4; prev++) {
        for (next = prev + 1; next < 5; next++) {
            aux = array[prev];
            if (array[next] < array[prev]) {
                array[prev] = array[next];
                array[next] = aux;
            }
        }
    }

    for (int i = 0; i < 5; i++) {
        printf(" %d ", array[i]);
    }
}
