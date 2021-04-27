PWD := ~/C/ccDigitalMatrix/
LN := ~/bin/
CC := clang

all: rain.out tncurses.out

rain.out: rain.c
	$(CC) -g -o $@ $< -lncurses

tncurses.out: tncurses.c
	$(CC) -g -o $@ $< -lncurses

install:
	ln -s $(PWD)tncurses.out $(LN)tncurses
	ln -s $(PWD)rain.out $(LN)rain

clean:
	rm $(PWD)tncurses.out
	rm $(LN)tncurses
	rm $(PWD)rain.out
	rm $(LN)rain
	
