#!/bin/bash
set -e

echo "=== E3 : ACL et capacités POSIX ==="

echo "=== ACL ==="
touch /lab/shared/acl_demo.txt

if command -v setfacl >/dev/null 2>&1; then
    setfacl -m u:charlie:r /lab/shared/acl_demo.txt
    getfacl /lab/shared/acl_demo.txt
else
    echo "setfacl/getfacl non disponibles dans ce conteneur"
fi

echo "=== Capacité POSIX ==="

if command -v setcap >/dev/null 2>&1; then
    cp /bin/ping /lab/ping_cap 2>/dev/null || true

    if [ -f /lab/ping_cap ]; then
        chmod u-s /lab/ping_cap
        setcap cap_net_raw+ep /lab/ping_cap
        getcap /lab/ping_cap
        ls -l /lab/ping_cap
    else
        echo "/bin/ping absent : démonstration de capacité à adapter"
    fi
else
    echo "setcap/getcap non disponibles dans ce conteneur"
fi
