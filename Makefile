all: prog1.out

prog1.out: bst.cpp hashtable.cpp prog1.cpp
	g++ -std=c++11 bst.cpp hashtable.cpp prog1.cpp -o prog.out

