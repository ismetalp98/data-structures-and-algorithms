
all: main.o MaxHeap.o MinHeap.o QuickMedian.o
	g++ -Wall  main.o MaxHeap.o MinHeap.o QuickMedian.o -o hw3.out

main.o: main.cpp
	g++ -Wall -c main.cpp

MaxHeap.o: MaxHeap.cpp
	g++ -Wall -c MaxHeap.cpp

MinHeap.o: MinHeap.cpp
	g++ -Wall -c MinHeap.cpp

QuickMedian.o: QuickMedian.cpp
	g++ -Wall -c QuickMedian.cpp

clean:
	rm -rf *.o
	rm -f *.out
	rm -f *~ *.h.gch *#[

run:
	./hw3.out
