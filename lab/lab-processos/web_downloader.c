#include <curl/curl.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

// retirada/baseada em https://curl.se/libcurl/c/CURLOPT_WRITEFUNCTION.html
typedef struct {
    char *response;
    size_t size;
} memory;

static void inicia_memory(memory *m) {
    (*m).size = 0;
    (*m).response = malloc((*m).size + 1);
    (*m).response[0] = '\0';
}

// retirada/baseada em https://curl.se/libcurl/c/CURLOPT_WRITEFUNCTION.html
static size_t cb(void *data, size_t size, size_t nmemb, void *userp) {
    size_t realsize = size * nmemb;
    memory *mem = (memory *)userp;

    char *ptr = realloc(mem->response, mem->size + realsize + 1);
    if (ptr == NULL)
        return 0; /* out of memory! */

    mem->response = ptr;
    memcpy(&(mem->response[mem->size]), data, realsize);
    mem->size += realsize;
    mem->response[mem->size] = 0;

    return realsize;
}

static void conserta_url(char url[], char url_ok[]) {
    int i = 0;
    int j = 0;
    if (url[4] == ':') {
        i = 7;
    }
    if (url[4] == 's') {
        i = 8;
    }
    while (i < strlen(url)) {
        url_ok[j] = url[i];
        i++;
        j++;
    }
    for (int i = 0; i < strlen(url_ok) - 5; i++) {
        if (url_ok[i] == '.' || url_ok[i] == '/') {
            url_ok[i] = '_';
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc > 3 || argc == 1) {
        printf("\n ERROR! Quantidade inválida de argumentos! \n");
        return -1;
    }
    else if (argc == 3){
        printf("\n Iniciando o download das url's: \n");
        int fd1 = open(argv[2], O_RDONLY | O_EXCL, 0700);
        char buf1[1];
        char M[1024][1024];
        int x = 0;
        int y = 0;
        
        while(read(fd1, buf1, 1) != 0){
            if (buf1[0] == '\n'){
                x++;
                y = 0;
            }
            else{
                M[x][y] = buf1[0];
                y++;
            }
            
        }
        close(fd1);
        int contador_urls = x+1;
        int n_url = 0;

        while (n_url < contador_urls){
            pid_t pai, filho;

            filho = fork();

            if(filho == 0){
                memory m;
                inicia_memory(&m);

                CURL *curl;
                curl = curl_easy_init();
                curl_easy_setopt(curl, CURLOPT_URL, M[n_url]);
                curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, cb);
                curl_easy_setopt(curl, CURLOPT_WRITEDATA, &m);
                CURLcode res = curl_easy_perform(curl);

                if (res != CURLE_OK) {
                    return 0;
                }

                char url_ok[100];
                conserta_url(M[n_url], url_ok);
                int fd2 = open(url_ok, O_WRONLY | O_CREAT, 0700);

                char buf[1];
                for (int i = 0; i < m.size; i++) {
                    buf[0] = m.response[i];
                    write(fd2, buf, 1);
                }
                
                printf("\n %s baixada com sucesso! \n", M[n_url]);
                close(fd2);
                free(m.response);
                curl_easy_cleanup(curl);

                exit(0);
            }else{
                n_url++;
            }
        }
    }
    else if (argc == 2){
        printf("\n Iniciando o download: \n");
        memory m;
        inicia_memory(&m);

        CURL *curl;
        curl = curl_easy_init();
        curl_easy_setopt(curl, CURLOPT_URL, argv[1]);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, cb);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &m);
        CURLcode res = curl_easy_perform(curl);

        if (res != CURLE_OK) {
            return 0;
        }

        char url_ok[100];
        conserta_url(argv[1], url_ok);
        int fd2 = open(url_ok, O_WRONLY | O_CREAT, 0700);

        char buf[1];
        for (int i = 0; i < m.size; i++) {
            buf[0] = m.response[i];
            write(fd2, buf, 1);
        }
        printf("\n %s baixada com sucesso! \n", argv[1]);
        close(fd2);
        free(m.response);
        curl_easy_cleanup(curl);
            
    }

    return 1;
}