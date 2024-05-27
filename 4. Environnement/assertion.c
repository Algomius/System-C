#include "stdio.h"
#include "assert.h"
#include "math.h"

double racine (double d) {
    assert(d >= 0);
    return sqrt(d);
}

int main(){
    double d = -25;

    printf("%f\n", racine(d));
    printf("Fin du programme\n");
}
