#!/bin/bash

clang -Wall -Wextra -Werror main.c -lftprintf -lft -L. -g -fsanitize=address
./a.out $1
