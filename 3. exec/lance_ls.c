#include "stdio.h"
#include "stdlib.h"

int main() {
    int ret = system("ps");
    printf("Fin de la commande ls sur retour %d\n", ret);
}