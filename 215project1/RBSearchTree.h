//
//  RBSearchTree.h
//  project1
//
//  Created by Yingying Wu on 12/10/14.
//  Copyright (c) 2014 Yingying Wu. All rights reserved.
//

#ifndef __project1__RBSearchTree__
#define __project1__RBSearchTree__

#include <stdio.h>
#include "searchTree.h"
#include "RBsearchTreeNode.h"
#include <fstream>


class RBSearchTree:public searchTree{
    
protected:
    RBsearchTreeNode *root;
    ofstream fout;
    
    //helpers
    void rotate_left(RBsearchTreeNode *x);
    void rotate_right(RBsearchTreeNode *y);
    RBsearchTreeNode* uncle(RBsearchTreeNode *z);
    RBcolor color(RBsearchTreeNode *n);
    RBsearchTreeNode* sibling(RBsearchTreeNode *n);
    
    RBsearchTreeNode* insert_h(dictEntry *in, RBsearchTreeNode *current);
    void insert_fixup(RBsearchTreeNode *n);
    
    RBsearchTreeNode* search_h(string w, RBsearchTreeNode *current);
    
    void delete_fixup(RBsearchTreeNode *n);
    
    void preOrder_h(RBsearchTreeNode *n);
    void postOrder_h(RBsearchTreeNode *n);
    void inOrder_h(RBsearchTreeNode *n);
    RBsearchTreeNode* successor(RBsearchTreeNode *n);
    
    void visit(RBsearchTreeNode *p);
    
    void destroy_RBtree(RBsearchTreeNode *leaf);
    
public:
    RBSearchTree();
    // set root to NULL
    
    ~RBSearchTree();
    
    virtual void insert(dictEntry *in);
    // insert in in the tree
    
    virtual RBsearchTreeNode* search(string w);
    // return a pointer to the node whose dictEntry's word member is equal to w
    
    virtual void remove(string w);
    // remove the node in the tree whose dictEntry's word member is equal to w
    // or do nothing when no such node exists
    
    virtual void preOrder(string filename);
    
    virtual void postOrder(string filename);
    
    virtual void inOrder(string filename);
};

#endif /* defined(__project1__RBSearchTree__) */
