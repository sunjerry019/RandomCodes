#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
 
 
int main(int argc, char **argv) {
        char min, max;
        int status, i;
        char *x, *ptr;
        pid_t pid;
        if (argc != 3) {
                printf("Usage: %s <passwd maxlen> <progname>\n", argv[0]);
                exit(1);
        }
 
        x = (char *)malloc(atoi(argv[1]));
        ptr = x;
 
        while (1) {
                min = 0x20; // Primero caracter imprimivel da tabela ASCII (SPACE)
                max = 0x7E; // Ultimo caracter imprimivel da tabela ASCII (~)
                *ptr = (char)((min + max) / 2); // Meio da tabela ASCII
 
                for (i=0; i<7; i++) {
                        if ((pid = fork()) == -1) {
                                perror("fork");
                                exit(EXIT_FAILURE);
                        }
                        if (pid == 0) {
                                if (execl(argv[2], argv[2], x, NULL) == -1) {
                                        perror("execl");
                                        exit(EXIT_FAILURE);
                                }
                        } else {
                                if ((wait(&status)) == -1) {
                                        perror("wait");
                                        exit(EXIT_FAILURE);
                                }
                                if (WEXITSTATUS(status) == 1)
                                        min = *ptr+1;
                                if (WEXITSTATUS(status) == 255)
                                        max = *ptr-1;
 
                                *ptr = (char)((min + max) / 2); // Meio da busca
                                //printf("min: %d - max: %d - x: %d\n", min, max, *ptr);
                                //printf("WEXITSTATUS: %d\n", WEXITSTATUS(status));
                                //sleep(1);
                        }
                }
                if (*ptr == 0x1F) {
                        printf("----------------------------------------\nPassword Found[%d]: %s\n", strlen(x), x);
                        return(0);
                } else {
                        ptr++;
                        printf("Password found so far: %s\n", x);
                }
        }
        return(0);
}