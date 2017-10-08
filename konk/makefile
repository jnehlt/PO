konk : konk.o con.o
	gcc -g konk.o con.o -o konk -lm

con.o : con.c con.h
	gcc -g -Wall -pedantic -Werror -std=c99 -c con.c -o con.o

konk.o : konk.c con.h
	gcc -g -Wall -pedantic -Werror -std=c99 -c konk.c -o konk.o

.PHONY: clean

clean :
	-rm konk.o con.o konk

