CC = gcc
OUT = mastermind
run:
	${CC} -o ${OUT} main.c
clean:
	rm -f ${OUT}
