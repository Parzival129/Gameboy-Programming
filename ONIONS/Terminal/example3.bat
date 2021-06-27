@echo off
@echo Compiling.............
c:\gbdk\bin\lcc -Wa-l -c -o example3.o example3.c
c:\gbdk\bin\lcc -o example3.gb example3.o

@echo Done !