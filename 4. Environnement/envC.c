#include <stdio.h>
#include <stdlib.h>

int main() {
    int ret;
    ret = setenv("MAVAR", "coucou", 0);
    if (ret == 0) {
        printf("contenu = %s\n", getenv("MAVAR"));
    }
    unsetenv("MAVAR");
    char *v = getenv("MAVAR");
    if (v == NULL) {
        printf("MAVAR n'existe plus\n");
    }
}