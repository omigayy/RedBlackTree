//
//  RBsearchTreeNode.h
//  project1
//
//  Created by Yingying Wu on 12/10/14.
//  Copyright (c) 2014 Yingying Wu. All rights reserved.
//

#ifndef __project1__RBsearchTreeNode__
#define __project1__RBsearchTreeNode__

#include <stdio.h>
#include "treeNode.h"


enum RBcolor{RED,BLACK};


class RBsearchTreeNode:public treeNode{
public:
    
    RBsearchTreeNode *left, *right, *parent;
    RBcolor nodeColor;
    
    RBsearchTreeNode(dictEntry *d);
    //initializes data to d and set all pointer to NULL, color to red
    
    RBsearchTreeNode(dictEntry *d, RBsearchTreeNode *p);
    //initializes data to d and, parent to p and left, right to NULL, color to red
    
    RBsearchTreeNode(dictEntry *d, RBsearchTreeNode *p, RBsearchTreeNode *l, RBsearchTreeNode *r);
    // data to d, parent to p, left to l, right to r, color to red
};

#endif /* defined(__project1__RBsearchTreeNode__) */
