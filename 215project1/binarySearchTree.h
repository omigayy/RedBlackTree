//
//  binarySearchTree.h
//  project1
//
//  Created by Yingying Wu on 12/9/14.
//  Copyright (c) 2014 Yingying Wu. All rights reserved.
//

#ifndef __project1__binarySearchTree__
#define __project1__binarySearchTree__

#include <stdio.h>
#include "searchTree.h"
#include "searchTreeNode.h"
#include <fstream>


class binarySearchTree : public searchTree{
    
protected:
    searchTreeNode *root;
    ofstream fout;
    
    //helpers
    void insert_h(dictEntry *in, searchTreeNode *current);
    searchTreeNode* search_h(string w, searchTreeNode *current);
    void preOrder_h(searchTreeNode *n);
    void postOrder_h(searchTreeNode *n);
    void inOrder_h(searchTreeNode *n);
    searchTreeNode* successor(searchTreeNode *n);
    
    void visit(searchTreeNode *p);
    
    void destroy_tree(searchTreeNode *leaf);

public:
    
    binarySearchTree();
    // set the root to NULL
    
    ~binarySearchTree();
    
    virtual void insert(dictEntry *in);
    // insert in in the tree
    
    virtual searchTreeNode* search(string w);
    // return a pointer to the node whose dictEntry's word member is equal to w
    
    virtual void remove(string w);
    // remove the node in the tree whose dictEntry's word member is equal to w
    // or do nothing when no such node exists
    
    virtual void preOrder(string filename);
    
    virtual void postOrder(string filename);
    
    virtual void inOrder(string filename);
    
    
};

#endif /* defined(__project1__binarySearchTree__) */
