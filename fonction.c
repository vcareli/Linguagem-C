#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/*
    Bibliotecas de funçoes do jogo Pendu - Forca
*/

char lirecaracter(){
    char caracter = 0;

    caracter = getchar();
    caracter = toupper(caracter);

    while(getchar() != '\n');

    return caracter;
}

int recherche_lettre(char lettre, char mot[], int tableau[]){
    int i = 0, cherche = 0;

    for(i = 0; mot[i] != '\0'; i++){
        if(lettre == mot[i]){
            tableau[i] = 1;
            cherche = 1;
        }
    }
    return cherche;
}

int gagner(int tableau[], long longueur){
    int resultat = 1;

    for(int i = 0; i < longueur; i++){
        if(tableau[i] == 0){
            resultat = 0;
        }
    }
    return resultat;
}
