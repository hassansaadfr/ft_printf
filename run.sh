#!/bin/bash

clang main.c -lftprintf -L. -fsanitize=address
#./a.out $1
