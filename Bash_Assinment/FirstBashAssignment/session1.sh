#!/bin/bash

sum()
{
#sum the first and second function arguments 
	local result=$(($1+$2))
#create a variable as a reference to the for loop
	local decrement=$result
#loop and print the result and decrement and continue looping
	for ((i=0;i<decrement;i++))
	do
		echo $result
		((result=$result-1))
     	done
}

#declare a variable to take the first input in from user
	export var1
	echo "please enter the first digit"
	read var1

#declare a variable to take the second input in from user
	export var2
	echo "please enter the second digit"
	read var2

#call the function sum with 1+2
	echo " "
	sum var1 var2
