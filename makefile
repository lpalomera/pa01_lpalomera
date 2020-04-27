all: prog1.out

prog1.out: bst.cpp hashtable.cpp prog1.cpp
	clang++ bst.cpp hashtable.cpp prog1.cpp -o prog1.out

