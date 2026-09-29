# E7 — Invocation sure des commandes externes

## Code corrige

char *safe_env[] = { "PATH=/bin:/usr/bin", "IFS= \t\n", "LANG=C", NULL };
char *args[] = { "/bin/cat", argv[1], NULL };
execve("/bin/cat", args, safe_env);

## Trois garanties

1. execve() ne passe pas par un shell -> pas d'interpretation de ; | $()
2. Chemin absolu /bin/cat -> pas de detournement PATH
3. Environnement reconstruit (liste blanche) -> pas d'heritage de variables
   malveillantes

## Preuve (trace T7)

--- Test 1 : injection de commande ---
[i] Apres abandon : ruid=1000 euid=1000 suid=1000
/bin/cat: '/etc/passwd; id': No such file or directory
[+] SUCCES : injection inerte

--- Test 2 : PATH detourne ---
[+] SUCCES : PATH inoperant (chemin absolu)

--- Test 3 : IFS detourne ---
[+] SUCCES : IFS inoperant

## Comparaison avant/apres

| Avant (vulnerable)             | Apres (corrige)                        |
|--------------------------------|----------------------------------------|
| system(command)                | execve("/bin/cat", args, safe_env)     |
| Shell interprete ;             | ; = caractere ordinaire                |
| PATH detournable               | /bin/cat absolu                        |
| IFS detournable                | Environnement reconstruit              |
