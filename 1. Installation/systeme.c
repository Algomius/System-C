#include <unistd.h>
#include <stdio.h>

int main() {
    printf("PID : %ld - PPID : %ld \n", (long) getpid(), (long) getppid());
    sleep(10);
    printf("Coucou\n");
}