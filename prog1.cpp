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
    
    myfile.open("/autograder/submission/PA1_dataset.txt");        //PA1_dataset.txt);
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





string argument = argv[1] ;
string::iterator it = argument.begin();
string subword, sub;
vector<string> commands;
for (it; it != argument.end(); it++) {
    if (subword.length() > 5)
        sub = subword.substr(subword.length() - 4, 4);
        if (subword == "search" || subword == "delete" || subword == "insert" || subword == "range search") {
            commands.push_back(subword);
            subword.clear();
            }
            else {
                if(*it == ',') {
                    commands.push_back(subword);
                    subword.clear();
                    it++;
                    }
                    else if (sub == " to ") {
                        subword = subword.substr(0, subword.length() - 4);
                        commands.push_back(subword);
                        subword.clear();
                        sub.clear();
                        subword += *it;
                        }
                        else
                            subword += *it;
                            }
             }
                            commands.push_back(subword);
                            for (int vecIt = 0; vecIt < commands.size(); vecIt++) {
                               // cout << commands[vecIt] << " ";
                                if (commands[vecIt] == "range search") {
                                    //cout << commands[vecIt] << " ";
                                    //cout<< commands[vecIt + 1]<<" to "<<commands[vecIt + 2]<<endl;
                                    //cout << commands[vecIt+1] << endl;
                                    h1.hashRangeSearch(commands[vecIt + 1], commands[vecIt + 2]);
                                    b1.bstRangeSearch(commands[vecIt + 1], commands[vecIt + 2] );
                                    }
                                    else if (commands[vecIt] == "delete") {
                                        //cout << commands[vecIt] << " ";
                                        //cout << commands[vecIt+1] << endl;
                                        h1.hashDelete(commands[vecIt + 1]);
                                        b1.bstDelete(commands[vecIt + 1]);
                                        }
                                        else if (commands[vecIt] == "insert") {
                                            //cout << commands[vecIt] << " ";
                                            //cout << commands[vecIt+1] << endl;
                                            h1.hashInsert(commands[vecIt + 1]);
                                            b1.bstInsert(commands[vecIt + 1]);
                                            }
                                            else if (commands[vecIt] == "search") {
                                                //cout << commands[vecIt] << " ";
                                                //cout << commands[vecIt+1] << endl;
                                                h1.hashSearch(commands[vecIt + 1]);
                                                b1.bstSearch(commands[vecIt + 1]);
                                                }
                                                }
                                                


return 0;
    }
