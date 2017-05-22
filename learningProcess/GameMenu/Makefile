all: menue.o guessNumber.o k.o tictactoe.o
	gcc menue.c guessNumber.c k.c tictactoe.c -o game
menue.o: menue.c guessNumber.h k.h tictactoe.h
	gcc -c menue.c
guessNumber.o: guessNumber.c guessNumber.h
	gcc -c guessNumber.c
k.o: k.c k.h
	gcc -c k.c
tictactoe.o: tictactoe.c tictactoe.h
	gcc -c tictactoe.c
