CC = C:\MinGW\bin\mingw-get.exe
all: example arcfour

example: example.o
	$(CC) example.o -o example.exe -Wall -O2

example.o: example.c
	$(CC) -c -O2 -Wall example.c

arcfour: arcfour.o
	$(CC) arcfour.o -o arcfour.dll -O2 -Wall -fPIC -shared -D_GNU_SOURCE

arcfour.o: arcfour.c
	$(CC) -c -O2 -Wall arcfour.c

clean:
	del /Q *.o *.dll example.exe