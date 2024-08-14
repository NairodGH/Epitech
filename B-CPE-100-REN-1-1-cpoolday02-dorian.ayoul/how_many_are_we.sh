#!
cut -d';' -f 3 | grep -Ei "$1" | wc -l
