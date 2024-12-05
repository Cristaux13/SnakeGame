but : snake



OFILES = main.o \
	 affichage.o \
	 deplacement.o \
	 initialisation.o

CC = gcc
CFLAGS =  -ansi -pedantic -lgraph -g





main.o : affichage.h deplacement.h initialisation.h

affichage.o : affichage.h

deplacement.o : deplacement.h

initialisation.o : initialisation.h







snake : $(OFILES)
	$(CC) $(CFLAGS) -o snake $(OFILES)

run : snake
		./snake

clean :
	-rm -f $(OFILES) snake

.PHONY : but clean
