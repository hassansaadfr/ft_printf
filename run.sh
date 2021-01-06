#!/bin/bash

clang main.c -lftprintf -L. -g -fsanitize=address
#./a.out $1
