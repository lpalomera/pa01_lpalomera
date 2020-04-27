//hashtable.h

//(a) a constructor and a destructor.
//(b) a function for searching a word in the BST/Hash Table (the word may not be exist)
//(c) a function for inserting a new word into the BST/Hash Table or increment its counter 
//(d) a function for deleting a word from the BST/Hash Table or decrement its counter
//(e) a function for doing a range search

#include <iostream>
#include <string>
#include <utility>
//#include <alorithm>
#include <vector>

using namespace std;
class Hashtable {
public:
   //constructor
   Hashtable();
   
   //destructor
   ~Hashtable();

   //search
   void hashSearch(std::string word);
   
   //insert (no output)
   void hashInsert2(std::string word);

   //insert
   void hashInsert(std::string word);
   
   //delete
   void hashDelete(std::string word);
   
   //range search
   void hashRangeSearch(std::string begin, std::string end);

private:
   const static size_t CAPACITY = 100;

   std::vector<std::pair<std::string, int> > table[CAPACITY];
   
   size_t hash(std::string word) const;
};
