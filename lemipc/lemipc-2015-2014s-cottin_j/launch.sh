i=0
./lemipc 2 -m &
while [ $i != 9 ]
do
    ./lemipc 2 &
    i=`expr $i + 1`
done

i=0

while [ $i != 10 ]
do
    ./lemipc 1 &
    i=`expr $i + 1`
done
