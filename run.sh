#!/bin/bash

clang main.c -lftprintf -L. -fsanitize=address -g
#./a.out $1
