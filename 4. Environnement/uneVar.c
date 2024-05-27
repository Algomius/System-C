#include <stdio.h>
#include <stdlib.h>

int main() {
    char * variable;
    variable = getenv("MAVAR");
    if (variable != NULL) {
        printf("contenu = %s\n", variable);
    }
    else
    {
        printf("MAVAR n'existe pas\n");
    }
}