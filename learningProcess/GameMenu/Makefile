all: main.o guessNumber.o k.o tictactoe.o
	gcc main.c guessNumber.c k.c tictactoe.c -o game
main.o: main.c guessNumber.h k.h tictactoe.h
	gcc -c main.c
guessNumber.o: guessNumber.c guessNumber.h
	gcc -c guessNumber.c
k.o: k.c k.h
	gcc -c k.c
tictactoe.o: tictactoe.c tictactoe.h
	gcc -c tictactoe.c
