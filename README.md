# 42 Push_swap Project

I strongly recommend reading my blog post about my algorithm, where I explain and visualize my approach to make it easier to understand 🤓

__I haven't hardcoded any number combinations, so I'm not sure if I'll be able to get full points!__

## Overview
The Push_swap project is an exercise in sorting data on a stack with a limited set of instructions, using the lowest possible number of actions. The challenge involves manipulating various types of algorithms to choose the most appropriate and efficient solution for optimized data sorting.

## Instructions
- `sa` (swap a): Swap the first 2 elements at the top of stack a.
- `sb` (swap b): Swap the first 2 elements at the top of stack b.
- `ss`: Execute `sa` and `sb` simultaneously.
- `pa` (push a): Move the top element from stack b to stack a.
- `pb` (push b): Move the top element from stack a to stack b.
- `ra` (rotate a): Rotate stack a upwards.
- `rb` (rotate b): Rotate stack b upwards.
- `rr`: Execute `ra` and `rb` simultaneously.
- `rra` (reverse rotate a): Rotate stack a downwards.
- `rrb` (reverse rotate b): Rotate stack b downwards.
- `rrr`: Execute `rra` and `rrb` simultaneously.


## How It Works
1. **Initialization**: The program starts with a stack 'a' filled with a random sequence of integers, and an empty stack 'b'.
2. **Sorting Operations**: Using commands like `sa`, `ra`, `pa`, etc., the program sorts the integers in stack 'a' in ascending order.
3. **Checker Program**: The bonus part of the project includes a checker program that takes the stack as input along with the sorting commands and checks if the stack is sorted correctly.


## Installation
Clone this repository and use the Makefile to compile the project:
```
git clone https://github.com/djelacik/push_swap
```
## Usage

- `make`: Compiles the executable `push_swap`.
- `make bonus`: Compiles the executable `checker`.

### Running push_swap
To run `push_swap` and see the list of operations that sort the provided numbers, use the following command:
```bash
./push_swap 5 3 2 8 7 6 1
```

### Using checker to validate sorts
Execute `checker` with the same series of numbers:
```bash
./checker 5 3 2 8 7 6 1 
```
Manually enter the sorting instructions, one per line, and signal the end of input with Ctrl + D (Unix) or Cmd + D (MacOS):
```bash
ra
pb 
rr
pb 
...
cmd + D
```
`checker` will output `OK` if the stack is sorted correctly and `b` is empty, or `KO` otherwise.


## License

This project is licensed under the MIT License
