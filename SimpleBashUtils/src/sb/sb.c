#include <stdio.h>
#include <stdlib.h>


int main() {
    printf("char hack[256][4] = {\n");

    for (int i = 0; i < 256; i++) {
        printf("    \"%c\", \n", i);
    }
    printf("}\n");


}