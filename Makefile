PWD := ~/C/ccDigitalMatrix/
LN := ~/bin/
CC := clang

rain.out: rain.c
	$(CC) -g -o $@ $< -lncurses

tncurses.out: tncurses.c
	$(CC) -g -o $@ $< -lncurses

install:
	ln -s $(PWD)tncurses.out $(LN)tncurses

clean:
	rm $(PWD)tncurses.out
	rm $(LN)tncurses
	
