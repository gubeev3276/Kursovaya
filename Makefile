#pragma once
target =  main
sources = main.cpp mdfile.cpp 
CC = g++
CCFlags = -Wall
LDLIBS = -lcrypto++
OPT = -Ofast
all:build
build:
	$(CC) $(CCFlags) $(OPT) $(sources) -o $(target) $(LDLIBS)
unit:
	g++ -Wall -Ofast mdfile.cpp UnitTest.cpp -o unit -lcrypto++ -lUnitTest++
dbg:
	$(CC) -g $(sources) -o $(target)DBG
