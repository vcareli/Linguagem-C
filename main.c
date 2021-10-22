#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "fonction.h"

int main(int argc, char *argv[]){

    int size_mot = 0, *maLettre = NULL, coups = 5, duvida = 1, mot_affiche[30];
    char mot_secret[] = "CORPAO";

    printf("=== Bienvenue au Pendu ===\n");
    size_mot = strlen(mot_secret);      //Conta tamanho da palavra secreta
    maLettre = malloc(size_mot * sizeof(int));
    strcpy(mot_affiche, mot_secret);    //copia conteudo da palavra secreta para palavra de tela

    for(int i = 0; i < size_mot; i++){
        mot_affiche[i] = '_';       //Substitui letra por underline
    }
    mot_affiche[size_mot] = '\0';
     if(strcmp(mot_affiche, mot_secret) == 0){
        affiche_mot(size_mot, mot_secret);
        printf("\nTu as reussi... Felicitations !!!");
    }

    while(coups > 0 || strcmp(mot_affiche, mot_secret) != 0){
        printf("\nTu as %d coups", coups);
        printf("\nMot Secret: ");
        affiche_mot(size_mot, mot_affiche);     //Função para mostrar palavra escondida
        printf("\nUne lettre: ");
        maLettre = lirecaracter();             //Lê caracter excluindo ENTER
        for(int i = 0; mot_secret[i] != '\0'; i++){
            if(maLettre == mot_secret[i]){
                mot_affiche[i] = maLettre;
                duvida = 0;
            }
        }
        if(duvida == 1){coups--;}
    }
    if(strcmp(mot_affiche, mot_secret) == 0){

        affiche_mot(size_mot, mot_secret);
        printf("Tu as reussi... Felicitations !!!");
    }
    return 0;
}
