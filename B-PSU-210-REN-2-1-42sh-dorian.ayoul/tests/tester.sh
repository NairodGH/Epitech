#!/bin/bash

RED='\e[31m'
GREEN='\e[32m'
YELLOW='\e[33m'
BLUE='\e[34m'
WHITE='\e[0m'

path="tests/test_files/"

arg_a=0

for arg in $@
do
    shift
    if [ "$arg" = "-a" ]
    then
        arg_a=1
        continue
    fi
    set -- "$@" "$arg"
done

single_test()
{
    line="$1"

    echo "$line" | ./42sh >& ../file1
    err1=$?
    echo "$line" | tcsh >& ../file2
    err2=$?

    if [ $arg_a == 1 ]
    then
        diff ../file1 ../file2
    else
        diff ../file1 ../file2 >/dev/null
    fi

    error=$?

    echo -n -e $line
    i=0
    size=$(printf "%s" "$line" | wc -c)
    var=$(( 50 - size ))
    while [ $i -ne $var ]
    do
        i=$(($i+1))
        echo -n -e " "
    done

    if [ $error -eq 0 ] && [ $err1 == $err2 ]
    then
        echo -e "-> ${GREEN}Success${WHITE}"
    else
        echo -e "-> ${RED}Failure${WHITE}"
    fi

    rm ../file1 ../file2
}

if test -f "42sh"
then
    echo -e "${BLUE}############    TESTS    ############${WHITE}"
else
    echo -e "42sh -> ${YELLOW}Couldn't find binaries${WHITE}"
    exit 1
fi

for entry in $path*
do
    filename=$(basename -- "$entry")
    extension="${filename##*.}"
    filename="${filename%.*}"

    if [ $extension != "txt" ]
    then
        continue
    fi

    if [ $# == 1 ] && [ $1 != $entry ]
    then
        continue
    fi

    echo -e "${BLUE}-- $filename --${WHITE}"

    while IFS= read -r line
    do
        single_test "$line"
    done < "$entry"

done

rm ls >&/dev/null
