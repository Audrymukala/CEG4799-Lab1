#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>

int main(void)
{
    uid_t ruid, euid, suid;

    if (getresuid(&ruid, &euid, &suid) == -1) {
        perror("getresuid");
        return 1;
    }

    printf("RUID = %d\n", ruid);
    printf("EUID = %d\n", euid);
    printf("SUID = %d\n", suid);

    return 0;
}
