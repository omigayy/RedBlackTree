//
//  dictEntry.h
//  project1
//
//  Created by Yingying Wu on 12/9/14.
//  Copyright (c) 2014 Yingying Wu. All rights reserved.
//

#ifndef project1_dictEntry_h
#define project1_dictEntry_h

#include <string>

using namespace std;

class dictEntry{
    
protected:
    string word;
    string definition;
    
public:
    
    dictEntry(string w, string d);
    //initializes word and definition respectively
    
    string getWord();
    //returns the word string
    
    string getDefinition();
    //returns the definition string
    
    void updateDefinition(string def);
    //updates the definition string
    
    /*Each operator should take a string
     as input and compare that string (using lexicographic order – the order given by the
     usual string comparison function) to the word string of this*/
    void operator= (dictEntry *a);
    bool operator== (string a);
    bool operator< (string a);
    bool operator> (string a);
    bool operator<= (string a);
    bool operator>= (string a);
};

#endif
