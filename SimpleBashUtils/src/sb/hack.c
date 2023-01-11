#include "hack.h"

int main() {
    for (int i = 0; i < 256; i++) {
        printf("hack[%d] = %s\n", i, hack[i]);
    }
}