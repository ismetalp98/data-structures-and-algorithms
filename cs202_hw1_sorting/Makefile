all: main.o sorting.o
	g++ -Wall main.o sorting.o -o hw1.out

main.o: main.cpp
	g++ -Wall -c main.cpp

sorting.o: sorting.cpp
	g++ -Wall -c sorting.cpp

clean:
	rm -rf *.o
	rm -f *.out
	rm -f *~ *.h.gch *#[

run:
	./hw1.out
