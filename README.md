# Push_swap
The Push_swap project is a very simple and highly effective algorithm project: data will
need to be sorted. You have at your disposal a set of int values, 2 stacks and a set of
instructions to manipulate both stacks.
Your goal ? Write 2 programs in C:

1. The first, named **checker** which takes integer arguments and reads instructions on
the standard output. Once read, checker executes them and displays OK if integers
are sorted. Otherwise, it will display KO.
2. The second one called **push_swap** which calculates and displays on the standard
output the smallest progam using Push_swap instruction language that sorts integer
arguments received.

## Allowed functions
1. `write`
2. `read`
3. `malloc`
4. `free`
5. `exit`

## Mandatory part
1. The game is composed of 2 stacks named a and b.
2. To start with:

    **a** contains a random number of either positive or negative numbers without any duplicates.
    
    **b** is empty.
    
3. The goal is to sort in ascending order numbers into stack a.
4. To do this you have the following operations at your disposal:

    **sa** : swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements).
  
    **sb** : swap b - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements).
  
    **ss** : sa and sb at the same time.
  
    **pa** : push a - take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
  
    **pb** : push b - take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
  
    **ra** : rotate a - shift up all elements of stack a by 1. The first element becomes the last one.
  
    **rb** : rotate b - shift up all elements of stack b by 1. The first element becomes the last one.
  
    **rr** : ra and rb at the same time.
  
    **rra** : reverse rotate a - shift down all elements of stack a by 1. The flast element becomes the first one.

## Usage
1. `make && make clean`
2. `./push_swap 2 1 3 6 5 8`

    OR
    
    `ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l`
    
    OR
    
    `ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG`
