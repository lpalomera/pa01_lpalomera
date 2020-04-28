#include <iostream>
#include <algorithm>
#include <vector>
#include "hashtable.h"
#include "bst.h"
#include <fstream>
#include <sstream> 
#include <string>
using namespace std;


int main(int argc, char *argv[]){
    BST b1;
    Hashtable h1;

/*
    string parseThis;
    ifstream words(argv[1]); 
    cout<<argv[1]<<endl;
    words>>parseThis;
    cout<<parseThis<<endl;
    
    cout<<"----------"<<endl;
*/

    ifstream myfile;
    ///autograder/submission/PA1_dataset.txt
    
    myfile.open("PA1_dataset.txt");        //PA1_dataset.txt);
    char output[100];
    int z=0; 
    if (myfile.is_open()) {
        while (!myfile.eof() && z<9999) {
            z++;
            myfile >> output;
            h1.hashInsert2(output);
            b1.bstInsert2(output);
            }
    }
    myfile.close();
    /*h1.hashSearch("broadcasting");
    h1.hashInsert("computers");
    h1.hashDelete("hospitalize");
    h1.hashInsert ("honour"); 
    h1.hashSearch("hospitalize");
    h1.hashDelete("broadcasting");
    h1.hashDelete("broadcasting");
*/





string parse = argv[1] ;
string::iterator it = parse.begin();
string name, n;
vector<string> dict;
for (it; it != parse.end(); it++) {
    if (name.length() > 5)
        n = name.substr(name.length() - 4, 4);
        if (name == "search" || name == "delete" || name == "insert" || name == "range search") {
            dict.push_back(name);
            name.clear();
            }
            else {
                if(*it == ',') {
                    dict.push_back(name);
                    name.clear();
                    it++;
                    }
                    else if (n == " to ") {
                        name = name.substr(0, name.length() - 4);
                        dict.push_back(name);
                        name.clear();
                        n.clear();
                        name += *it;
                        }
                        else
                            name += *it;
                            }
             }
                            dict.push_back(name);
                            for (int vecIt = 0; vecIt < dict.size(); vecIt++) {
                                if (dict[vecIt] == "range search") {
                                    //h1.hashRangeSearch(dict[vecIt + 1], dict[vecIt + 2]);
                                    b1.bstRangeSearch(dict[vecIt + 1], dict[vecIt + 2] );
                                    }
                                    else if (dict[vecIt] == "delete") {
                                        //h1.hashDelete(dict[vecIt + 1]);
                                        b1.bstDelete(dict[vecIt + 1]);
                                        }
                                        else if (dict[vecIt] == "insert") {
                                            //h1.hashInsert(dict[vecIt + 1]);
                                            b1.bstInsert(dict[vecIt + 1]);
                                            }
                                            else if (dict[vecIt] == "search") {
                                                //h1.hashSearch(dict[vecIt + 1]);
                                                b1.bstSearch(dict[vecIt + 1]);
                                            }
                              }
                                                


return 0;
    }
