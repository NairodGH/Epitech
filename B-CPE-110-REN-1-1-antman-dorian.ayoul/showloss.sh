if [ "$#" != 2 ]; then
    echo "need 2 filepath to compare"
    exit
fi
diff -a $1 $2 > loss
var=$(cat loss)
if [ "$var" == "" ];then
    echo "no loss !"
    rm loss
    exit
fi
echo "loss :"
grep "c" loss
grep "d" loss
rm loss