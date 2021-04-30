PWD := ~/C/ccDigitalMatrix/
LN := ~/bin/
CC := clang
CFLAG := -g -Wall -o
LDFLAG := -lncurses

.PHONY: all install clean

all: rain.out tncurses.out

rain.out: rain.c
	$(CC) $(CFLAG) $@ $< $(LDFLAG)

tncurses.out: tncurses.c
	$(CC) $(CFLAG) $@ $< $(LDFLAG)

install:
	ln -s $(PWD)tncurses.out $(LN)tncurses
	ln -s $(PWD)rain.out $(LN)rain

clean:
	rm $(PWD)tncurses.out
	rm $(LN)tncurses
	rm $(PWD)rain.out
	rm $(LN)rain
	
