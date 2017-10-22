wyzn : wyzn.o val.o det.o
	gcc -g wyzn.o val.o det.o -o wyzn -lm

val.o : val.c val.h
	gcc -g -Wall -pedantic -Werror -std=c99 -c val.c -o val.o

det.o : det.c det.h
	gcc -g -Wall -pedantic -Werror -std=c99 -c det.c -o det.o

wyzn.o : wyzn.c val.h
	gcc -g -Wall -pedantic -Werror -std=c99 -c wyzn.c -o wyzn.o

.PHONY: clean

clean :
	-rm wyzn.o val.o det.o wyzn

