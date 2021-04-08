CC = g++
CFLAGS = -Wall -g


main: main.o vigenere.o subcipher.o caesar.o

main.o: main.cpp vigenere.cpp subcipher.cpp caesar.cpp

vigenere.o: vigenere.h

subcipher.o: subcipher.h

caesar.o: caesar.h
