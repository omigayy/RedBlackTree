//
//  dictEntry.cpp
//  project1
//
//  Created by Yingying Wu on 12/9/14.
//  Copyright (c) 2014 Yingying Wu. All rights reserved.
//

#include "dictEntry.h"

dictEntry::dictEntry(string w, string d){
    //initializes word and definition respectively
    word = w;
    definition = d;
}

string dictEntry::getWord(){
    //returns the word string
    return word;
}

string dictEntry::getDefinition(){
    //returns the definition string
    return definition;
}

void dictEntry::updateDefinition(string def){
    //updates the definition string
    definition = def;
}

/*Each operator should take a string
as input and compare that string (using lexicographic order – the order given by the
usual string comparison function) to the word string of this*/
void dictEntry::operator= (dictEntry *a){
    this->word = a->word;
    this->definition = a->definition;
}

bool dictEntry::operator== (string a){
    return (this->word==a);
}

bool dictEntry::operator< (string a){
    return (this->word<a);
}

bool dictEntry::operator> (string a){
    return (this->word>a);
}

bool dictEntry::operator<= (string a){
    return (this->word<=a);
}

bool dictEntry::operator>= (string a){
    return (this->word>=a);
}