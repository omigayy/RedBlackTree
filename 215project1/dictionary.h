//
//  dictionary.h
//  project1
//
//  Created by Yingying Wu on 12/10/14.
//  Copyright (c) 2014 Yingying Wu. All rights reserved.
//

#ifndef __project1__dictionary__
#define __project1__dictionary__

#include <stdio.h>
#include "searchTree.h"
#include <string>

class dictionary{
protected:
    searchTree *dict;
public:
    
    dictionary(searchTree *p);
    // initializes dict to that pointer
    // this will let the user choose the type of search tree he wants the dict to use
    ~dictionary();
    
    string search(string w);
    void add(dictEntry *in);
    void remove(string w);
    void readFile(string filename);
    void writeFilePreorder(string filename);
    void writeFileInorder(string filename);
    void writeFilePostorder(string filename);
    
};

#endif /* defined(__project1__dictionary__) */
