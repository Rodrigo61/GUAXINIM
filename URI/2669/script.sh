#!/bin/bash
 
g++ main.cpp -std=c++11 -O2
 
for i in {1..26}
do
	echo "L_$i"
	time ./a.out < input/"L_$i" > output/"MySolL_$i.out"
	echo "Caso $i"
	diff --brief output/"L_$i" output/"MySolL_$i.out"
 
done
