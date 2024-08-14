#!/bin/bash

gcc -c *.c -I include/ -g
ar rc libmy.a *.o
