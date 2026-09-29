# Propriétés de sécurité vérifiables — E9

## Programme corrigé : catall_fixed.c

### P1 — Moindre privilège (abandon définitif)
**Énoncé :** Le programme abandonne définitivement son UID effectif avant toute
opération non privilégiée.
**Code :** `setresuid(ruid, ruid, ruid)` avant `execve()`.
**Vérification :** `getresuid()` après l'appel renvoie `ruid=euid=suid=1000`.
**Preuve :** trace T8 (`[i] Après abandon : ruid=1000 euid=1000 suid=1000`).

### P2 — Invocation sûre des commandes externes
**Énoncé :** Aucune commande externe n'est invoquée par nom relatif ni par shell.
**Code :** `execve("/bin/cat", args, safe_env)` avec chemin absolu.
**Vérification :** le programme ne contient ni `system()` ni `popen()`.
**Preuve :** trace T7 (`/bin/cat: '/etc/passwd; id': No such file or directory`).

### P3 — Environnement contrôlé
**Énoncé :** L'environnement passé à `execve()` est reconstruit (liste blanche).
**Code :** tableau `safe_env[]` avec uniquement PATH, IFS, LANG.
**Vérification :** aucune variable héritée de l'appelant n'est transmise.
**Preuve :** le détournement PATH/IFS (T5) est inerte sur `catall_fixed`.

### P4 — Entrées utilisateur non interprétées
**Énoncé :** Aucune entrée utilisateur n'est passée à un shell.
**Code :** `execve()` direct, pas de `system()`.
**Vérification :** les métacaractères `;`, `|`, `$()` sont des caractères ordinaires.
**Preuve :** trace T7 (injection inerte).
