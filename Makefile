CC=gcc
FLAGS= -Wall
EXE=repertoire
GTKFB= `pkg-config --cflags gtk+-3.0`
GTKFA= `pkg-config --libs gtk+-3.0`

all : $(EXE) clean

repertoire: vue.o modele.o listio.o main.o
	$(CC) -o $@ $^

vue.o: vue.c
	$(CC) -o $@ -c $< $(FLAGS)

modele.o: modele.c
	$(CC) -o $@ -c $< $(FLAGS)

listio.o: listio.c
	$(CC) -o $@ -c $< $(FLAGS)

main.o: main.c
	$(CC) $(GTKFB) -o $@ -c $< $(FLAGS) $(GTKFA)

clean :
	rm -rf *.o
