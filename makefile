# build an executable named parsing from parsing.c
all: parsing.c
	cc -std=c99 -Wall parsing.c mpc.c -ledit -lcurses -o parsing
clean:
	$(RM) parsing
