#include <iostream>
#include <algorithm>
#include <vector>
#include "hashtable.h"
#include "bst.h"
using namespace std;

int main(){
    BST b1;
    b1.bstInsert("hello");
    b1.bstInsert("alamony");
    b1.bstInsert("pig");
    b1.bstInsert("zebra");
    b1.bstInsert("alamony");
    b1.bstInsert("serenity");
    b1.printInOrder();
    cout<<"------------------------"<<endl;

    b1.bstRangeSearch("h","t");

    //b1.remove("alamony");
    //cout<<b1.getPredecessor("hello")<<endl;
    //cout<<b1.getSuccessor("zebra")<<endl;
    cout<<"------------------------"<<endl;


    //b1.printInOrder();
    /*
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
    */





    return 0;
    }
