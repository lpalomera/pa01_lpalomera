#include <iostream>
#include <algorithm>
#include <vector>
#include "hashtable.h"
#include "bst.h"
#include <fstream>
#include <sstream> 
#include <string>
#include <iterator>
using namespace std;


int main(int argc, char *argv[]){
    BST b1;
    Hashtable h1;


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
 //h1.hashSearch("broadcasting");

 string parse = argv[1];
 vector<string> phrase;
 string word="";
 string::iterator it = parse.begin();
 bool statement=false;
 string x; 
 
 
 for (it; it != parse.end()+1; it++) {
   
   if(statement==true){
    //cout<<"are you even in here "<<endl; 
     if (phrase[0]=="range"){
       //cout<<phrase[2]<<" and "<<phrase[4]<<end;
       h1.hashRangeSearch(phrase[2],phrase[4]);
       b1.bstRangeSearch(phrase[2],phrase[4]);
       phrase.erase (phrase.begin(), phrase.begin()+ phrase.size());
       statement=false;
       }
     else if(phrase[0]=="delete"){
       //cout<<"deleting "<<phrase[1]<<endl;
       h1.hashDelete(phrase[1]);
       b1.bstDelete(phrase[1]);
       phrase.erase (phrase.begin(), phrase.begin()+ phrase.size());
       statement=false;
       }
     else if(phrase[0]=="insert"){
       //cout<<"inserting "<<phrase[1]<<endl;
       h1.hashInsert(phrase[1]);
       b1.bstInsert(phrase[1]);
       phrase.erase (phrase.begin(), phrase.begin()+ phrase.size());
       statement=false;
       }
     else if(phrase[0]=="search"){
       //cout<<"searching "<<endl;//<<phrase[1]<<endl;
       h1.hashSearch(phrase[1]);
       b1.bstSearch(phrase[1]);
       phrase.erase (phrase.begin(), phrase.begin()+ phrase.size());
       statement=false;
       }   
     
     }
  
  if(*it==' ' || *it==',' || it==parse.end() ){ //if it has reached a space or comma,
    //cout<<word<<endl;
    if(word!=" " && word!=""){
    x=word;
    phrase.push_back(x); //pushback the word and reset word
    }
    if(*it==','){          //if comma statement is complete* need to add end of statement
      statement=true;
      }
      word="";
    }
    if((*it!=' ') && (*it !=',')){
  word=word+*it;
    }
  }

  if (phrase[0]=="range"){
      h1.hashRangeSearch(phrase[2],phrase[4]);
      b1.bstRangeSearch(phrase[2],phrase[4]);
      }
  else if(phrase[0]=="delete"){
      h1.hashDelete(phrase[1]);
      b1.bstDelete(phrase[1]);
      }
  else if(phrase[0]=="insert"){
      h1.hashInsert(phrase[1]);
      b1.bstInsert(phrase[1]);
      }
  else if(phrase[0]=="search"){
      h1.hashSearch(phrase[1]);
      b1.bstSearch(phrase[1]);
      }

/*
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
                                    h1.hashRangeSearch(dict[vecIt + 1], dict[vecIt + 2]);
                                    b1.bstRangeSearch(dict[vecIt + 1], dict[vecIt + 2] );
                                    }
                                    else if (dict[vecIt] == "delete") {
                                        h1.hashDelete(dict[vecIt + 1]);
                                        b1.bstDelete(dict[vecIt + 1]);
                                        }
                                        else if (dict[vecIt] == "insert") {
                                            h1.hashInsert(dict[vecIt + 1]);
                                            b1.bstInsert(dict[vecIt + 1]);
                                            }
                                            else if (dict[vecIt] == "search") {
                                                h1.hashSearch(dict[vecIt + 1]);
                                                b1.bstSearch(dict[vecIt + 1]);
                                            }
                              }
                                                

*/
return 0;
    }
