
//
//  searchTreeNode.h
//  project1
//
//  Created by Yingying Wu on 12/9/14.
//  Copyright (c) 2014 Yingying Wu. All rights reserved.
//

#ifndef project1_searchTreeNode_h
#define project1_searchTreeNode_h

#include <stdio.h>
#include "treeNode.h"
#include "dictEntry.h"

class searchTreeNode : public treeNode{
    
public:
    
    searchTreeNode *left, *right, *parent;
    
    searchTreeNode(dictEntry *d);
    //initializes data to d and set all pointer to NULL
    
    searchTreeNode(dictEntry *d, searchTreeNode *p);
    //initializes data to d and, parent to p and left, right to NULL
    
    searchTreeNode(dictEntry *d, searchTreeNode *p, searchTreeNode *l, searchTreeNode *r);
    // data to d, parent to p, left to l, right to r
};

#endif
