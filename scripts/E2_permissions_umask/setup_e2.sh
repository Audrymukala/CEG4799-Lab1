#!/bin/bash
set -e

echo "=== E2 : Permissions, umask et sticky bit ==="

mkdir -p /lab/shared
chown root:equipe /lab/shared

# rwx pour propriétaire et groupe + sticky bit
chmod 1770 /lab/shared

echo "=== Permissions du répertoire partagé ==="
ls -ld /lab/shared

echo "=== Démonstration umask ==="
umask 0027
touch /lab/shared/test_umask.txt
ls -l /lab/shared/test_umask.txt

echo "=== Valeur du umask ==="
umask
