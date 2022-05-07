#!/bin/bash

DIR=test1

for F in {0000..0100}; do 
if [ ! -e $DIR/000${F}_in.txt ] ; then 
echo "All Ok"
exit 1
fi
./progtest2/ciselna_rada  < $DIR/000${F}_in.txt > /tmp/out.txt 

if ! diff /tmp/out.txt $DIR/000${F}_out.txt; then 
echo "Mismatch: $DIR/000${F}_in.txt"
echo "Must be: $(cat "$DIR/000${F}_out.txt")\n"
echo "Yours: $(cat /tmp/out.txt)"
exit1
fi 
done 

