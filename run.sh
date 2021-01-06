#!/bin/bash

clang -Wall -Wextra -Werror main.c -lftprintf -L. -g -fsanitize=address
#./a.out $1
