# E8 — Abandon definitif de privilege

## Code

uid_t ruid = getuid();
setresuid(ruid, ruid, ruid);  /* abandon DEFINITIF */

Important : setresuid() (pas seteuid()) — sinon le privilege reste reversible
via l'UID sauvegarde.

## Verification (trace T8)

Avant : ruid=1000 euid=0 suid=0
Apres setresuid : ruid=1000 euid=1000 suid=1000
[+] setuid(0) refuse : Operation not permitted (privilege definitivement abandonne)

## Justification de l'ordre des operations

1. Operations privilegiees (si necessaire) — pendant que euid=0
2. Abandon definitif via setresuid(ruid,ruid,ruid) — AVANT toute invocation externe
3. Operations non privilegiees — avec l'UID reel

## Difference setuid / seteuid / setresuid

| Appel                          | Effet                          | Reversible ?      |
|--------------------------------|--------------------------------|-------------------|
| seteuid(ruid)                  | Change euid seulement          | Oui (via suid)    |
| setuid(ruid) (root)            | Change ruid, euid, suid        | Non (mais ambigu) |
| setresuid(ruid,ruid,ruid)      | Change les 3 explicitement     | Non — CORRECT     |
