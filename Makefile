all : rpn.c stack.c stack.h
		clang -g -o rpn rpn.c stack.c
