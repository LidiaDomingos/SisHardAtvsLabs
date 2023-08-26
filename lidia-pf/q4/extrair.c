// Faça seus includes aqui!
#include <stdio.h>
#include <stdlib.h>

char *extrair_arquivo(char *url) {
    char *res = malloc( sizeof(char) * 100);
    // SUA SOLUCAO AQUI!
    int indice_ultima_barra = 0;
    int size = 0;
    while (url[size] != '\0') {
        if(url[size]=='/'){
            indice_ultima_barra = size;
        }
        size++;
    }
    printf("Índice na string da última barra: %d\n", indice_ultima_barra);
    int k = 0;
    for (int j = indice_ultima_barra+1; j < size; j++){
        res[k] = url[j];
        k++;
    }
    return res; // Você vai precisar alterar este return!
}
