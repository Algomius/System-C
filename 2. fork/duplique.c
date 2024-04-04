#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

int main() {
    pid_t f1 = fork();
    pid_t f2 = fork();
    int nb = 5;


    if (f1 == -1 || f2 == -1) {
        printf("Probleme dans le fork - %d\n", errno);
        return -1;
    }
    if (f1 == 0 && f2 != 0) {
        printf(" Je suis dans le fils 1\n");
        printf("F - %d\n", nb);
        nb = 7;
        sleep(10);
        printf("F - %d\n", nb);
        printf("F1 - Utilisateur reel %u, uttilisateur effectif %u\n", getuid(), geteuid());
        printf("F - PID : %ld - PPID : %ld\n", (long) getpid(), (long) getppid());
    } 
    else if (f1 != 0 && f2 == 0) {
        printf(" Je suis dans le fils 2\n");
        printf("F - %d\n", nb);
        nb = 7;
        sleep(10);
        printf("F - %d\n", nb);
        printf("F2 - Utilisateur reel %u, uttilisateur effectif %u\n", getuid(), geteuid());
        printf("F - PID : %ld - PPID : %ld\n", (long) getpid(), (long) getppid());
    } 
    else if (f1 != 0 && f2 != 0) 
    {
        printf("Je suis dans le pere\n");
        printf("P - %d\n", nb);
        nb = 1;
        int status;
        pid_t fils = waitpid(f2, &status, 0);
        printf("Mon fils %ld s'est termine\n", fils);
        /*while ((fils = wait(&status)) > 0) {
            printf("Mon fils %ld s'est termine\n", fils);
        } */
        printf("P - %d\n", nb);
        printf("P - Utilisateur reel %u, uttilisateur effectif %u\n", getuid(), geteuid());
        printf("P - PID : %ld - PPID : %ld\n", (long) getpid(), (long) getppid());
    }
    
}