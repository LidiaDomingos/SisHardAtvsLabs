// Leia o PDF ou MD antes de iniciar este exercício!
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]){
    int ret = 0;
    //retorna o estado do fork
    int status;
    pid_t filho;
    while (ret == 0) {
        char *args[] = {"./verify", argv[1], NULL};
        filho = fork();
        // No pai, espere e trate o resultado
        if (filho == 0) {
            //o processo filho entra aqui
            execvp("./verify", args);
            printf("o exec deu ruim!");
        } else { 
            //processo pai é aqui
            //espera o que vem do filho
            int id = wait(&status);

            //checa se o programa terminou normalmente
            if (WIFEXITED(status)){
                ret = (char) WEXITSTATUS(status);
                printf("VERIFY RETORNOU %d\n", ret);
            }
            //se nao, me diz o que aconteceu, qual sinal recebido
            else{
                printf("VERIFY TEMINOU COM SINAL %s\n",  strsignal(WTERMSIG(status)));
            }
        }
    }
}