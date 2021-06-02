CC = g++
CFLAGS = -Wall -g


main: main.o vigenere.o subcipher.o caesar.o

main.o: main.cpp vigenere.cpp subcipher.cpp caesar.cpp

vigenere.o: ./h_files/vigenere.h

subcipher.o: ./h_files/subcipher.h

caesar.o: ./h_files/caesar.h
