#include "WordCount.h"
#include <iostream>
#include "tddFuncs.h"

using namespace std;

int main() {
    cout<<"Testing dumpWordsSortedByWord: "<<endl;
    
    WordCount w;
    cout<<"Test Case 1:"<<endl;
    w.addAllWords("Sentence is a sentence");
    
    ASSERT_EQUALS(2,w.getWordCount("sentence"));
