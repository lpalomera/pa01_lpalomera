#include <iostream>
#include <algorithm>
#include <vector>
#include "hashtable.h"
#include "bst.h"
#include <fstream>
#include <sstream> 
#include <string>
using namespace std;

/*
void parser(string x){
	  string word="";
      for (int i=0; i<x.size()-1; i++){
	    if(x[i]==' '){
	      
	      
	      if(word=="range"){          //case 4
	        i=i+8;
	        word="";
	        for(int m=i; m<=x.size();m++){
	          if( x[m]==' ' || m==x.size() ){
	            //string first=word; 
	            cout<<word<<endl;
	            //
	            i=m+4;
	            word="";
	            for(int y=i; y<=x.size(); y++){
	              if( x[y]==',' || y==x.size() ){
	                //string last=word;
                    b1.bstRangeSearch(first,last);
                    h1.hashRangeSearch(first,last);
	                //cout<<word<<endl;
	                i=y;
	                word="";
	                break;
	                }else{word=word+x[y];}
	              }
	            
	            //
	            word="";
	            break;
	            }
	          else{
	            word=word+x[m];}
	          }
	      }
	             
	      
	      if(word=="insert"){           //case 1
	        word="";
	        for(int j=i+1;j<=x.size();j++){
	          if(x[j]==','|| j==x.size() ){
	            //insert Functions go here
                b1.bstInsert();
                h1.hashInsert();
	            //cout<<word<<endl;    
	            i=j+1;
	            word="";
	            break;
	            }
	          else{
	            word=word+x[j];}
	          }
	        }
	      
	      if(word=="delete"){        //case 2
	        word="";
	        for(int k=i+1; k<=x.size();k++){
	          if(x[k]==',' || k==x.size()){
	            //Delete functions go here
	            b1.bstDelete(word);
                h1.hashDelete(word);
                //cout<<word<<endl;
	            i=k+1;
	                        word="";
	            break;
	            }
	          else{
	            word=word+x[k];}
	          }
	      }
	      
	      if(word=="search"){         //case 3
	        word="";
	        for(int n=i+1; n<=x.size();n++){
	          if(x[n]==','|| n==x.size()){
	             //Search functions go here
                 b1.bstSearch(word);
                 h1.hashInsert(word);
	             //cout<<word<<endl;
	             i=n+1;
	             word="";
	             break;
	            }
	          else{
	            word=word+x[n];}
	           }
	      }
	      
	      
	    
	      //else{cout<<"how did you make it here"<<endl;}
	    }
	    else{word=word+x[i];}
	  }
}	
*/

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
    myfile.open("PA1_dataset.txt");///autograder/submission/PA1_dataset.txt); //PA1_dataset.txt");
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
    //b1.bstSearch("broadcasting");
    //b1.bstInsert("computers");
    //b1.hashDelete("broadcasting");
    //b1.bstDelete("hospitalize");
    //search broadcasting, insert computers, delete hospitalize
  





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
                                cout << commands[vecIt] << " ";
                                if (commands[vecIt] == "range search") {
                                    h1.hashRangeSearch(commands[vecIt + 1], commands[vecIt + 2]);
                                    b1.bstRangeSearch(commands[vecIt + 1], commands[vecIt + 2] );
                                    }
                                    else if (commands[vecIt] == "delete") {
                                        h1.hashDelete(commands[vecIt + 1]);
                                        b1.bstDelete(commands[vecIt + 1]);
                                        }
                                        else if (commands[vecIt] == "insert") {
                                            h1.hashInsert(commands[vecIt + 1]);
                                            b1.bstInsert(commands[vecIt + 1]);
                                            }
                                            else if (commands[vecIt] == "search") {
                                                h1.hashSearch(commands[vecIt + 1]);
                                                b1.bstSearch(commands[vecIt + 1]);
                                                }
                                                }
                                                

return 0;
    }
