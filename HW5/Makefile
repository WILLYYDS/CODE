F = -std=c++20 -ggdb
P = string_test
0 = ListNode.o String.o string_test.o
Z = hw5.zip

def: $P

string_test.o: string_test.cpp String.h ListNode.h
	g++ $F -c string_test.cpp

String.o: String.cpp String.h ListNode.hw
	g++ $F -c String.cpp

ListNode.o: ListNode.cpp ListNode.h
	g++ $F -c ListNode.cpp

string_test: $O
	g++ $F $O -o string_test

clean:
	/bin/rm -f $P $O $z

zip:
	zip $Z *.h *.cpp Makefile