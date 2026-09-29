#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
    char cmd[256];
    if (argc < 2) return 1;
    snprintf(cmd, sizeof(cmd), "cat %s", argv[1]);
    system(cmd);
    return 0;
}
