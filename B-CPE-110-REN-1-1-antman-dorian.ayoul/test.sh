if [ "$#" != 2 ] && [ "$#" != 3 ] && [ "$#" != 4 ]; then
    echo "======================================================================================================="
    echo "need at least 2 arguments and no more than 4 arg, the first 2 arg are : filepath and types (1, 2 or 3)"
    echo
    echo "the third arg are -c to see the compression ratio or -l to see the ratio loss or -cl/-lc to see both"
    echo
    echo "the fourth arg is -t to see detail time execution (become third arg if you don't use -c/-l)"
    echo "======================================================================================================="
    exit
fi
t="0"
if [ "$#" == "3" ] && [ "$3" == "-t" ]; then
    t="1"
fi
if [ "$#" == "4" ] && [ "$4" == "-t" ]; then
    t="1"
fi
make re
clear
if [ "$t" == "1" ]; then
    echo -n "antman time :"
    time ./antman/antman $1 $2 > compressed
    echo ""
else
    ./antman/antman $1 $2 > compressed
fi
if [ "$2" == "3" ]; then
    style="uncompressed.ppm"
    if [ "$t" == "1" ]; then
        echo -n "giantman time :"
        time ./giantman/giantman compressed 3 > $style
    else
        ./giantman/giantman compressed 3 > $style
    fi
fi
if [ "$2" == "2" ]; then
    style="uncompressed.html"
    if [ "$t" == "1" ]; then
        echo -n "giantman time :"
        time ./giantman/giantman compressed 2 > $style
    else
        ./giantman/giantman compressed 2 > $style
    fi
fi
if [ "$2" == "1" ]; then
    style="uncompressed.lyr"
    if [ "$t" == "1" ]; then
        echo -n "giantman time :"
        time ./giantman/giantman compressed 1 > $style
    else
        ./giantman/giantman compressed 1 > $style
    fi
fi
echo "======================================================================================================="
echo "Compression done !"
if [ "$#" == 2 ]; then
    echo  "add -c at the end to see the compression ratio or -l to see the ratio loss or -cl/-lc to see both"
    echo "======================================================================================================="
    exit
fi
if [ "$3" == "-c" ]; then
    size=$(ls -s $1 | cut -d " " -f1)
    compr=$(ls -s compressed | cut -d " " -f1)
    echo ""
    echo -n "Compression à "
    echo -n $((100-($compr*10/$size*10)))
    echo "%"
fi
if [ "$3" == "-l" ]; then
    echo ""
    ./showloss.sh $1 $style
fi
if [ "$3" == "-cl" ]; then
    size=$(ls -s $1 | cut -d " " -f1)
    compr=$(ls -s compressed | cut -d " " -f1)
    echo ""
    echo -n "Compression à "
    echo -n $((100-($compr*10/$size*10)))
    echo "%"
    echo ""
    ./showloss.sh $1 $style
fi
if [ "$3" == "-lc" ]; then
    echo ""
    ./showloss.sh $1 $style
    echo ""
    size=$(ls -s $1 | cut -d " " -f1)
    compr=$(ls -s compressed | cut -d " " -f1)
    echo -n "Compression à "
    echo -n $((100-($compr*10/$size*10)))
    echo "%"
fi
echo "======================================================================================================="