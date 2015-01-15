//
//  searchTreeNode.cpp
//  project1
//
//  Created by Yingying Wu on 12/9/14.
//  Copyright (c) 2014 Yingying Wu. All rights reserved.
//

#include "searchTreeNode.h"

searchTreeNode::searchTreeNode(dictEntry *d){
    //initializes data to d and set all pointer to NULL
    data = d;
    parent = NULL;
    left = NULL;
    right = NULL;
}

searchTreeNode::searchTreeNode(dictEntry *d, searchTreeNode *p){
    //initializes data to d and, parent to p and left, right to NULL
    data = d;
    parent = p;
    left = right = NULL;
}

searchTreeNode::searchTreeNode(dictEntry *d, searchTreeNode *p, searchTreeNode *l, searchTreeNode *r){
    // data to d, parent to p, left to l, right to r
    data = d;
    parent = p;
    left = l;
    right = r;
}