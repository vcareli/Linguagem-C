#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "fonction.h"

int main(int argc, char *argv[]){
    int *bonne_lettre = NULL;
    int qtd_mot_arq = 0, randomico = 0, linha = 0, nivel = 0;
    long vies = 0, taille = 0;
    char mot_secret[TAILLE_MOT] = "", letra = 0;
    FILE* arquivo = NULL;

// Abre e escolhe uma palavra no arquivo de dados
    arquivo = fopen("dicionario.pnd", "r");
    if(arquivo != NULL){
        do{
            linha = fgetc(arquivo);
            if(linha == '\n'){qtd_mot_arq++;}
        }while(linha != EOF);
        rewind(arquivo);    //Volta pro inicio do arquivo

//Escolhe a palavra aleatoriamente
        srand(time(NULL));
        randomico = rand() % qtd_mot_arq;
        while(randomico > 0){
            linha = fgetc(arquivo);
            if(linha == '\n'){randomico--;}
        }
        fgets(mot_secret, TAILLE_MOT, arquivo);
        fclose(arquivo);    //Fecha o afrquivo
    }else{
        printf("\nImpossivel iniciar jogo, arquivo DICIONARIO.PND não encontrado!");
        exit(1);
    }

// Tratamento da palavra secreta
    taille = strlen(mot_secret)-1;
    mot_secret[taille] = '\0';
    bonne_lettre = malloc(taille * sizeof(int));

    for(int j = 0; j < taille; j++){
        bonne_lettre[j] = 0;
    }

// Jogo em si
    printf("\n* * * * P E N D U * * * *\n\n\nVoce tem %ld vidas...\n", vies);
    printf("\nEscolha seu nivel:\n1 - Facil\n2 - Dificil: ");
    scanf("%d", &nivel);
    if(nivel == 1){vies = 6;}else{vies = 4;}
    printf("\n\nVoce tem %d vidas...\n\n\n", vies);

    while(vies > 0 && !gagner(bonne_lettre, taille)){
        for(int i = 0; i < taille; i++){
            if(bonne_lettre[i]){
                printf("%c ", mot_secret[i]);
            }else{
                printf("_ ");
            }
        }
        printf("\n\nAdvinhe uma letra? \n");
        letra = lirecaracter();
        if(!recherche_lettre(letra, mot_secret, bonne_lettre)){
            vies--;
            printf("\nLetra errada.\nVoce tem %ld vidas...\n", vies);
        }
    }
    if(gagner(bonne_lettre, taille)){
         printf("Parabéns !!! Você acertou a palavra!");
    }else{
        printf("\n\nVocê perdeu... A palavra era %s.\n", mot_secret);
    }
    free(bonne_lettre);
}
