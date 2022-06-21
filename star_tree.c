#include <iostream>

using namespace std;

int main()
{
    int n = 8;
    int linhas = 0;
    int aux1 = n;
    int aux2 = 0;

    while(linhas < n){
        for (int col = 1; col < aux1; col++){
            printf(" ");
        }
        for (int star = 0; star <= aux2; star++){
            printf("*");
        }
        printf("\n");
        linhas += 1;
        aux1 -= 1;
        aux2 += 1;
    }

    return 0;
}
