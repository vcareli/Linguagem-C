#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/*
    Bibliotecas de funçoes do jogo Pendu - Forca
*/

char lirecaracter(){
/*
    Função para ler um caracter digitado e desconsiderar a tecla ENTER
*/
    char caracter = 0;

    caracter = getchar();      //Lê o caracter digitado e coloca em maiusculo
    caracter = toupper(caracter);

    while(getchar() != '\n');

    return caracter;
}

void affiche_mot(int tamanho, int palavra[]){
    for(int i = 0; i < tamanho; i++){
        printf("%c ", palavra[i]);
    }
}

