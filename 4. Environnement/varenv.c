#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

extern char ** environ;

int main() {
    pid_t f1 = fork();

    if (f1 == -1) {
        printf("Probleme dans le fork - %d\n", errno);
        return -1;
    }

    if (f1 == 0) {
        // je suis dans le fils
        printf("Dans le fils -> PID : %ld - PPID : %ld\n", (long) getpid(), (long) getppid());
        for (int i = 0; environ[i] != NULL; i++) {
            printf("%d : %s\n", i, environ[i]);
        }


    }
    else {
        // Je suis dans le père
        int status;
        pid_t fils = waitpid(f1, &status, 0);
        printf("Dans le père -> PID : %ld - PPID : %ld\n", (long) getpid(), (long) getppid());
        for (int i = 0; environ[i] != NULL; i++) {
            printf("%d : %s\n", i, environ[i]);
        }
    }

}