#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

int main() {
    pid_t f1 = fork();

    if (f1 == -1) {
        printf("Probleme dans le fork - %d\n", errno);
        return -1;
    }
    if (f1 == 0 ) {
        // Je suis dans le fils
        printf(" Je suis dans le fils \n");
        printf("F - PID : %ld - PPID : %ld\n", (long) getpid(), (long) getppid());
    } 
    else {
        // Je suis dans le père
        printf(" Je suis dans le pere\n");
        printf("P - PID : %ld - PPID : %ld\n", (long) getpid(), (long) getppid());
    } 
}