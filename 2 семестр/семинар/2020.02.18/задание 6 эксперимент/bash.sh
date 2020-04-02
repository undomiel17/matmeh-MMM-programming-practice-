#!/bin/bash
make -f makefile.txt MyProg
n=0
for k in 1 2 3 4 5 6 7 8 9 10
do
if [[ $k -ne 10 ]]
then
	pathin=./[$k]_test_in.txt
	pathout=./[$k]_test_out.txt
	pathres=./[$k]_test_res.txt
else
	pathin=./10_test_in.txt
	pathout=./10_test_out.txt
	pathres=./10_test_res.txt
fi
	touch $pathout
	./MyProg <$pathin >$pathout 
  diff -bs $pathout $pathres
 res=$(cat $pathout)

if [[ $res == "yes" ]]
then	
let "n=$n+1"
fi
	
done
echo "количество пройденных тестов"
echo "$n"

