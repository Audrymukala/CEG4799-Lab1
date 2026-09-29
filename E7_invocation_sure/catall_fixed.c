#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(int argc, char *argv[]) {
    if (argc < 2) return 1;
    uid_t ruid = getuid();
    setresuid(ruid, ruid, ruid);
    uid_t r, e, s; getresuid(&r, &e, &s);
    fprintf(stderr, "[i] Après abandon : ruid=%d euid=%d suid=%d\n", r, e, s);
    char *env[] = { "PATH=/bin:/usr/bin", "IFS= \t\n", "LANG=C", NULL };
    char *args[] = { "/bin/cat", argv[1], NULL };
    execve("/bin/cat", args, env);
    perror("execve");
    return 1;
}
