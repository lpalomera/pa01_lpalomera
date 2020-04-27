//hashtable.cpp

//(a) a constructor and a destructor.
//(b) a function for searching a word in the BST/Hash Table (the word may not be exist)
//(c) a function for inserting a new word into the BST/Hash Table or increment its counter 
//(d) a function for deleting a word from the BST/Hash Table or decrement its counter
//(e) a function for doing a range search

#include "hashtable.h"
#include <string>
#include <utility>
#include <algorithm>
#include <vector>

using namespace std;
   
//constructor
Hashtable::Hashtable(){}
   
//destructor
Hashtable::~Hashtable(){}

   
size_t Hashtable::hash(std::string word) const {
    size_t accumulator = 0;
    for (size_t i = 0; i < word.size(); i++) {
		accumulator += word.at(i);
	}
	return accumulator % CAPACITY;
}

//search
void Hashtable::hashSearch(std::string word){
    int index=hash(word);
    for(size_t i=0;i<table[index].size();i++){
        if(word==table[index][i].first){
            //table[index][i].second=table[index][i].second+1;
            //cout<< "Search " <<table[index][i].first<<endl;
            cout<< table[index][i].first << " found,count = "<< table[index][i].second<<endl;
            return;
        }
    }
    //table[index].push_back(make_pair(valWord,1));
	cout<< word <<" not found "<< endl;
    return;
    }
   
//insert
void Hashtable::hashInsert(std::string word){
    int index=hash(word);
    for(size_t i=0;i<table[index].size();i++){
        if(word==table[index][i].first){
            table[index][i].second=table[index][i].second+1;
            //cout<< "insert "<< table[index][i].first <<endl;
            cout<< table[index][i].first << " inserted, new count = "<< table[index][i].second<<endl;
            return;
        }
    }
    cout<< word<< " inserted,new count = 1"<<endl;
    table[index].push_back(make_pair(word,1));
    return;

    }
   
//delete
void Hashtable::hashDelete(std::string word){
    int index=hash(word);
    for(size_t i=0; i<table[index].size(); i++){
        if(word==table[index][i].first){
            if(table[index][i].second>1){
            table[index][i].second-=1;
            //cout<<"delete "<< table[index][i].first<<endl;
            cout<< table[index][i].first << " deleted, new count = "<< table[index][i].second<<endl;
            return;
            }
        else if(table[index][i].second==1){
            table[index].erase(table[index].begin()+(i));
            cout<<table[index][i].first<<" deleted"<<endl;
            return ;
            }
        }
    }
	return;

    }
   
//range search
void Hashtable::HashRangeSearch(std::string begin, std::string end){
    vector<pair<string,int> > sortedVec;
    for(size_t i=0; i<CAPACITY;i++){
        for(size_t j=0; j< table[i].size();j++)
            sortedVec.push_back(make_pair(table[i][j].first,table[i][j].second));
        }
    sort(sortedVec.begin(), sortedVec.end() );//, lesser<pair<string, int> >());    
    
    
    for(size_t k=0; k<sortedVec.size();k++){
        if( (sortedVec[k].first).compare(begin)>=0 && (sortedVec[k].first).compare(end)<=0){
            cout<< sortedVec[k].first<<endl;
            }
            }
    }

