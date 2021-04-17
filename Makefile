PWD := ~/C/ccDigitalMatrix/
LN := ~/exec/
CC := clang
tncurses: tncurses.c
	$(CC) -g -o $@ $< -lncurses

install:
	ln -s $(PWD)tncurses $(LN)tncurses
	
