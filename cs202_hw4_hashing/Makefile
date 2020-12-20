all: Friendship.o  FriendshipHashing.o PersonHashing.o Person.o main.o
	g++ -Wall Friendship.o  FriendshipHashing.o PersonHashing.o Person.o main.o -o hw4.out

Friendship.o: Friendship.cpp
	g++ -Wall -c Friendship.cpp

FriendshipHashing.o: FriendshipHashing.cpp
	g++ -Wall -c FriendshipHashing.cpp

PersonHashing.o: PersonHashing.cpp
	g++ -Wall -c PersonHashing.cpp

Person.o: Person.cpp
	g++ -Wall -c Person.cpp

main.o: main.cpp
	g++ -Wall -c main.cpp

clean:
	rm -rf *.o
	rm -f *.out
	rm -f *~ *.h.gch *#[

run:
	./hw4.out
