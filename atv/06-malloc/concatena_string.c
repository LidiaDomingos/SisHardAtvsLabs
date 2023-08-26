#include <stdio.h>
#include <stdlib.h>
#include "macros_correcoes.h"

/* Recebe duas strings e concatena em uma terceira */
char *mystrcat(char *str1, char *str2) {
    /* Faça sua solução aqui!*/
    /* Pode alterar tudo, inclusive o retorno*/
    char *nova_string;
    int i;
    int n1 = 0;
    int n2 = 0;

    while (str1[n1] != '\0'){
        n1++;
    }

    while (str2[n2] != '\0'){
        n2++;
    }

    nova_string = malloc( (n1 + n2 + 1) * sizeof(char));

    if (nova_string == NULL) {
        perror("malloc");
        exit(0);
    }

    for (i = 0; i < n1; i++){
        nova_string[i] = str1[i];            
    }

    for (int j = 0; j <= n2; j++){
        nova_string[i] = str2[j];
        if (j == n2){
            nova_string[i] = '\0';
        }
        i++;
    }
    
    return nova_string;
}

int main(int argc, char *argv[]) {
    # define teste1 "str1"
    # define teste2 "str2"
    # define teste3 "0 str 3"


    char *res = mystrcat(teste1, teste2);
    assertEquals("teste 1", strcmp(res, teste1 teste2), 0);
    free(res);

    res = mystrcat(teste1, teste1);
    assertEquals("teste 2", strcmp(res, teste1 teste1), 0);
    free(res);

    res = mystrcat(teste1, teste3);
    assertEquals("teste 3", strcmp(res, teste1 teste3), 0);
    free(res);

    res = mystrcat(teste3, teste1);
    assertEquals("teste 4", strcmp(res, teste3 teste1), 0);
    free(res);

    res = mystrcat("", teste2);
    assertEquals("teste vazio 1", strcmp(res, teste2), 0);
    free(res);

    res = mystrcat(teste1, "");
    assertEquals("teste vazio 2", strcmp(res, teste1), 0);
    free(res);

    res = mystrcat("", "");
    assertEquals("teste vazio 3", strcmp(res, ""), 0);
    free(res);

    printSummary

    return 0;
}
