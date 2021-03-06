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

 string parse = argv[1];
 vector<string> phrase;
 string word="";
 string::iterator it = parse.begin();
 bool statement=false;
 string x; 
 
 
 for (it; it != parse.end()+1; it++) {
   
   if(statement==true){
     if (phrase[0]=="range"){
       h1.hashRangeSearch(phrase[2],phrase[4]);
       b1.bstRangeSearch(phrase[2],phrase[4]);
       phrase.erase (phrase.begin(), phrase.begin()+ phrase.size());
       statement=false;
       }
     else if(phrase[0]=="delete"){
       h1.hashDelete(phrase[1]);
       b1.bstDelete(phrase[1]);
       phrase.erase (phrase.begin(), phrase.begin()+ phrase.size());
       statement=false;
       }
     else if(phrase[0]=="insert"){
       h1.hashInsert(phrase[1]);
       b1.bstInsert(phrase[1]);
       phrase.erase (phrase.begin(), phrase.begin()+ phrase.size());
       statement=false;
       }
     else if(phrase[0]=="search"){
       h1.hashSearch(phrase[1]);
       b1.bstSearch(phrase[1]);
       phrase.erase (phrase.begin(), phrase.begin()+ phrase.size());
       statement=false;
       }   
     
     }
  
  if(*it==' ' || *it==',' || it==parse.end() ){ //if it has reached a space or comma,
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

return 0;
    }
