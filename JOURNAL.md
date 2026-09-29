# Journal d'équipe — Laboratoire 1

## Équipe
- Membre A : [nom]
- Membre B : [nom]

## Séance 0 — 15 sept. 2026
- Environnement SEED vérifié (conteneur Docker, Ubuntu 20.04)
- Dépôt Git créé
- Entente d'usage autorisé signée
- Compilation de `catall.c` réussie

## Séance 1 — 22 sept. 2026
- **Membre A** réalise : E1 (utilisateurs/groupes), E2 (permissions/umask)
- **Membre B** valide : vérification des permissions, tests avec alice/bob
- Analyse E4 (modèle de privilège) : `catall_debug` montre ruid=1000/euid=0
- Analyse E5 (3 surfaces) : entrées utilisateur, variables d'env., liaison dynamique
- **J1 validé** : exigences, rôles, échéancier

## Séance 2 — 29 sept. 2026
- **Membre B** réalise : E6a (injection), E6b (PATH/IFS), T6 (LD_PRELOAD)
- **Membre A** valide : rejoue les scripts, vérifie les traces
- E7 (execve) : correction appliquée, compilation sans avertissement
- E8 (setresuid) : abandon définitif vérifié (T8)
- E9 : propriétés P1-P4 et corpus (10 entrées)
- Démonstration devant l'assistant

## Décisions techniques
- Choix de `execve()` plutôt que `system()` : évite l'interprétation shell
- Choix de `setresuid(ruid,ruid,ruid)` : abandon définitif (vs `seteuid` réversible)
- Environnement reconstruit avec liste blanche : PATH, IFS, LANG uniquement

## Fichiers importants
- `src/catall.c` — programme vulnérable
- `src/catall_fixed.c` — programme corrigé
- `exploits/` — scripts d'attaque rejouables
- `traces/` — traces T3 à T8
- `corpus/` — 10 entrées dangereuses documentées
- `proprietes.md` — propriétés P1 à P4
