#!/bin/bash
set -e

echo "=== E1 : Utilisateurs et groupes ==="

groupadd -f equipe
groupadd -f securite

id alice >/dev/null 2>&1 || useradd -m alice
id bob >/dev/null 2>&1 || useradd -m bob
id charlie >/dev/null 2>&1 || useradd -m charlie

usermod -aG equipe alice
usermod -aG equipe bob
usermod -aG securite charlie

echo "=== Utilisateurs ==="
getent passwd alice
getent passwd bob
getent passwd charlie

echo "=== Groupes ==="
getent group equipe
getent group securite
