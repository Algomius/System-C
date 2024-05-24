#include "stdio.h"
#include "unistd.h"

int main(int argc, char *argv[]) {
    printf("PID dans affichage() : %ld\n", (long) getpid());
    printf("Je suis le programme execute par exec()\n");
    printf("Il y a %d parametres\n", argc);
    for (int i = 0; i < argc; i++) {
        printf("%d : %s\n", i, argv[i]);
    }
} 