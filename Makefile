CFLAGS = -Wall -std=c++11

main: main.cpp lcs.o
	g++ ${CFLAGS} $^ -o main

lcs.o: lcs.cpp
	g++ ${CFLAGS} -c $<

clean:
	rm *.o *.exe main

wclean:
	del *.o *.exe main