#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>

void show_uids(const char *message)
{
    uid_t ruid, euid, suid;
    getresuid(&ruid, &euid, &suid);

    printf("%s\n", message);
    printf("RUID=%d EUID=%d SUID=%d\n\n", ruid, euid, suid);
}

int main(void)
{
    uid_t ruid = getuid();

    show_uids("1. Au demarrage");

    if (seteuid(ruid) == -1) {
        perror("seteuid");
        return 1;
    }

    show_uids("2. Apres abandon temporaire");

    if (seteuid(0) == -1) {
        perror("seteuid");
        return 1;
    }

    show_uids("3. Apres restauration");

    return 0;
}
