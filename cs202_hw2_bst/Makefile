
all: analysis.o main.o PbBST.o PbBSTNode.o
	g++ -Wall analysis.o main.o PbBST.o PbBSTNode.o -o hw2.out

analysis.o: analysis.cpp
	g++ -Wall -c analysis.cpp

main.o: main.cpp
	g++ -Wall -c main.cpp

PbBST.o: PbBST.cpp
	g++ -Wall -c PbBST.cpp

PbBSTNode.o: PbBSTNode.cpp
	g++ -Wall -c PbBSTNode.cpp

clean:
	rm -rf *.o
	rm -f *.out
	rm -f *~ *.h.gch *#[
run:
	./hw2.out
