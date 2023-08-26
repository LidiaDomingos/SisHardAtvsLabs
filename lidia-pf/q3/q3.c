// Leia o PDF ou MD antes de iniciar este exercício!

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <signal.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

//variável global
int fd;
// Crie AQUI os handlers necessários
void sigint_handler(int num) {
    printf("Esta aplicacao nao fecha com SIGINT!\n");
}

void sigterm_handler(int num) {
    time_t rawtime = time(NULL);
    struct tm *ptime = localtime(&rawtime);
    printf("Agora são %02d:%02d:%02d\n", ptime->tm_hour, ptime->tm_min, ptime->tm_sec);
    char buf2[100];
    sprintf(buf2, "%02d:%02d:%02d ./q3 finished \n", ptime->tm_hour, ptime->tm_min, ptime->tm_sec);
    write(fd, buf2, strlen(buf2));
    close(fd);
    exit(0);
}

int main(int argc, char *argv[]) {

    // Exiba o PID deste processo
    printf("Meu pid: %d\n", getpid());

    fd = open(argv[1], O_WRONLY | O_CREAT | O_APPEND, 0700); 
    time_t rawtime = time(NULL);
    struct tm *ptime = localtime(&rawtime);

    char buf[100];
    sprintf(buf, "%02d:%02d:%02d ./q3 started \n", ptime->tm_hour, ptime->tm_min, ptime->tm_sec);
    write(fd, buf, strlen(buf));

     /* TODO: registar SIGINT aqui. */
    struct sigaction s;
    s.sa_handler = sigint_handler; // aqui vai a função a ser executada
    sigemptyset(&s.sa_mask);
    sigaddset(&s.sa_mask, SIGTERM);
    s.sa_flags = 0;

    sigaction(SIGINT, &s, NULL);
    /* TODO: registar SIGTERM aqui. */

    struct sigaction s2;
    s2.sa_handler = sigterm_handler; // aqui vai a função a ser executada
    sigemptyset(&s2.sa_mask);
    sigaddset(&s2.sa_mask, SIGINT);
    s2.sa_flags = 0;
    sigaction(SIGTERM, &s2, NULL);

    while(1); // roda infinitamente

    return 0;
}