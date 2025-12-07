#include <stdio.h>
#include <stdlib.h>
#include "input.h"

int getUserInput() {
    char buf[10];
    scanf("%s", buf);

    if (buf[0] == 'e' || buf[0] == 'E') {
        return -1;
    }

    if (buf[0] == 'r' || buf[0] == 'R') {
        return -2;
    }

    int num = atoi(buf);
    if (num >= 1 && num <= 9) {
        return num;
    }

    return 0;
}
