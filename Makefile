PWD := ~/C/ccDigitalMatrix/
LN := ~/exec/
CC := clang
tncurses.out: tncurses.c
	$(CC) -g -o $@ $< -lncurses

install:
	ln -s $(PWD)tncurses.out $(LN)tncurses

clean:
	rm $(PWD)tncurses.out
	rm $(LN)tncurses
	
