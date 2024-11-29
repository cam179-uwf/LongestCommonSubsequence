CFLAGS = -Wall -std=c++11

main: main.cpp lcs.o part1.o part2.o
	g++ ${CFLAGS} $^ -o main

lcs.o: lcs.cpp
	g++ ${CFLAGS} -c $<

part1.o: part1.cpp
	g++ ${CFLAGS} -c $<

part2.o: part2.cpp
	g++ ${CFLAGS} -c $<

clean:
	rm *.o *.exe main

wclean:
	del *.o *.exe main