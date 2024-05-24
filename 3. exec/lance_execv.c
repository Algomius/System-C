#include "stdio.h"
#include "unistd.h"
#include "sys/wait.h"
#include "errno.h"

int main() {
    pid_t n = fork();

    if (n == -1) {
        printf("Erreur dans le fork()\n");
        return -1;
    }

    if (n == 0) {
        // Je suis dans le processus fils
        char *argv[] = {"./affichage", "coucou", (char *) NULL};
        printf("PID avant exec() : %ld\n", (long) getpid());
        execv(argv[0], argv);
        printf("Erreur : %d\n", errno);
        printf("Fin du programme de lancement\n");
    }
    else
    {
        // Je suis dans le pere
        int status;
        pid_t fils = waitpid(n, &status, 0);
        printf("Fin du pere");
    }
}
