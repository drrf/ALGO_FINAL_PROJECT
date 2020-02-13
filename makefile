# MAKEFILE FOR ASSEMBLER PROGRAM
# Last Modified: June 26, 2019
# GLOBAL DEFINITIONS
# RUN: ./myprog file_dic.txt file_read.txt
GCC=gcc -c -g
FLAGS = -ansi -Wall -pedantic
ALLFILES = main.o file_to_x.o hash.o rbt.o check.o

myprog : $(ALLFILES)
	gcc -g $(FLAGS) $(ALLFILES) -o myprog

main.o : main.c my_h.h
	$(GCC) $(FLAGS) main.c -o main.o

file_to_x.o : file_to_x.c my_h.h
	$(GCC) $(FLAGS) file_to_x.c -o file_to_x.o

hash.o : hash.c my_h.h
	$(GCC) $(FLAGS) hash.c -o hash.o

rbt.o : rbt.c my_h.h
	$(GCC) $(FLAGS) rbt.c -o rbt.o

check.o : check.c my_h.h
	$(GCC) $(FLAGS) check.c -o check.o


run:
	./myprog < in1.txt > out1.txt
	./myprog < int2.txt > out2.txt

gdb:
	gdb ./myprog

clean:
	rm -f *.o
