//
//  searchTree.h
//  project1
//
//  Created by Yingying Wu on 12/9/14.
//  Copyright (c) 2014 Yingying Wu. All rights reserved.
//

#ifndef project1_searchTree_h
#define project1_searchTree_h


#include <stdio.h>
#include "dictEntry.h"
#include "treeNode.h"

class searchTree{
public:
    virtual void insert(dictEntry *key)=0;
    
    virtual treeNode* search(string key)=0;
    
    virtual void remove(string key)=0;
    
    virtual void preOrder(string key)=0;
    
    virtual void postOrder(string key)=0;
    
    virtual void inOrder(string key)=0;
};

#endif
