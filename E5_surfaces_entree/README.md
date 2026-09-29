# E5 — Analyse des 3 surfaces d'entrée

## Programme analysé
catall.c — Set-UID root, invoque /bin/cat <argv[1]> via system().

## Surface 1 — Entrées utilisateur

Point d'entrée dans le code :
    sprintf(command, "%s %s", v[0], v[1]);
    system(command);

Hypothèse implicite : argv[1] est un nom de fichier ne contenant aucun
métacaractère shell.

Violation : system() invoque /bin/sh -c, qui interprète ; | && $() et backticks.

Attaque possible : injection de commande arbitraire.

## Surface 2 — Variables d'environnement

Hypothèses implicites :
- PATH conserve sa valeur système.
- IFS conserve sa valeur par défaut.
- Aucune variable héritée ne modifie le comportement du shell.

Violation :
- IFS='/' modifie le découpage des mots par le shell.
- BASH_ENV=/tmp/evil.sh force l'exécution d'un script au démarrage.

Attaque possible : détournement de commande via IFS, exécution de script via BASH_ENV.

## Surface 3 — Liaison dynamique

Hypothèse implicite : ld.so charge uniquement les bibliothèques système.

Nuance : pour un binaire Set-UID, le noyau ignore LD_PRELOAD et LD_LIBRARY_PATH
fournis par l'utilisateur (protection AT_SECURE). Cette hypothèse est garantie
par le système, mais elle doit être écrite explicitement car le programme en dépend.

## Tableau récapitulatif

| Surface | Entrée | Hypothèse implicite | Propriété violée |
|---------|--------|---------------------|------------------|
| 1 | argv[1] | Pas de métacaractères | P4 |
| 2a | PATH | Valeur système | P2 |
| 2b | IFS | Valeur par défaut | P3 |
| 2c | BASH_ENV | Pas de script externe | P3 |
| 3 | LD_PRELOAD | Chargeur sûr | (garanti par noyau) |
