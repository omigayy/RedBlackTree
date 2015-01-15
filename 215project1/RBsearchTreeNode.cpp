//
//  RBsearchTreeNode.cpp
//  project1
//
//  Created by Yingying Wu on 12/10/14.
//  Copyright (c) 2014 Yingying Wu. All rights reserved.
//

#include "RBsearchTreeNode.h"

RBsearchTreeNode::RBsearchTreeNode(dictEntry *d){
//initializes data to d and set all pointer to NULL, color to red
    data = d;
    left = right = parent = NULL;
    nodeColor = RED;
}

RBsearchTreeNode::RBsearchTreeNode(dictEntry *d, RBsearchTreeNode *p){
//initializes data to d and, parent to p and left, right to NULL, color to red
    data = d;
    parent = p;
    left = right = NULL;
    nodeColor = RED;
}

RBsearchTreeNode::RBsearchTreeNode(dictEntry *d, RBsearchTreeNode *p, RBsearchTreeNode *l, RBsearchTreeNode *r){
// data to d, parent to p, left to l, right to r, color to red
    data = d;
    parent = p;
    left = l;
    right = r;
    nodeColor = RED;
}