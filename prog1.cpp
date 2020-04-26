#include <iostream>
#include <algorithm>
#include <vector>
#include "hashtable.h"

using namespace std;

int main(){

    Hashtable h1;
    h1.hashInsert("goodbye");
    h1.hashInsert("hello");
    h1.hashInsert("please");
    h1.hashInsert("terra");
    h1.hashInsert("animal");
    h1.hashInsert("crossing");
    h1.hashInsert("nominate");
    h1.hashInsert("snoody");
    h1.HashRangeSearch("g","ron");






    return 0;
    }
