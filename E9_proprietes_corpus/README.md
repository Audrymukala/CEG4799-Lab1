# E9 — Proprietes verifiables et corpus legue

## Proprietes (voir proprietes.md)

| Id | Propriete                                              | Preuve                     |
|----|--------------------------------------------------------|----------------------------|
| P1 | Moindre privilege : abandon definitif avant invocation | T8 : ruid=euid=suid=1000   |
| P2 | Invocation sure : chemin absolu, pas de shell          | T7 : injection inerte      |
| P3 | Environnement controle : liste blanche                 | T7 : PATH/IFS inertes      |
| P4 | Entrees utilisateur non interpretees                   | T7 : "/etc/passwd; id" -> un seul arg |

## Corpus (voir corpus/)

10 entrees dangereuses documentees, une par fichier, avec :

- ENTREE : payload exact
- SURFACE : ou l'attaque s'applique
- CAUSE : mecanisme vulnerable
- EFFET : consequence observable
- PROPRIETE VIOLÉE : P1 a P4
- CONTRE-MESURE : correction appliquee

### Liste des 10 entrees

| # | Entree                          | Surface          | Propriete violee      |
|---|---------------------------------|------------------|-----------------------|
| 1 | ; cp /etc/shadow /tmp/x         | Injection        | P4                    |
| 2 | | id > /tmp/out                 | Injection        | P4                    |
| 3 | && whoami                       | Injection        | P4                    |
| 4 | $(cat /etc/passwd)              | Injection        | P4                    |
| 5 | `id`                            | Injection        | P4                    |
| 6 | PATH=/tmp/evil:$PATH            | Var. env.        | P2                    |
| 7 | IFS=/                           | Var. env.        | P3                    |
| 8 | LD_PRELOAD=/tmp/evil.so         | Liaison dyn.     | (protection noyau)    |
| 9 | BASH_ENV=/tmp/evil.sh           | Var. env.        | P3                    |
| 10| ../../etc/shadow                | Entree utilisateur | P4                  |

Ces entrees sont leguees au projet final (laboratoire 5) pour alimenter le banc d'essai.
