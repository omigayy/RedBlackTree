//
//  RBSearchTree.cpp
//  project1
//
//  Created by Yingying Wu on 12/10/14.
//  Copyright (c) 2014 Yingying Wu. All rights reserved.
//  status: 283 not so sure

#include "RBSearchTree.h"
#include <iostream>
#include <queue>

using namespace std;

RBSearchTree::RBSearchTree(){
// set root to NULL
    root = NULL;
}

RBSearchTree::~RBSearchTree(){
    destroy_RBtree(root);
}

void RBSearchTree::insert(dictEntry *in){
// insert in in the tree
    RBsearchTreeNode *z;
    if (root==NULL){
        root = new RBsearchTreeNode(in);
        z=root;
    }
    else
        z = insert_h(in,root);
    if (z!=NULL)
        insert_fixup(z);
}

RBsearchTreeNode* RBSearchTree::search(string w){
// return a pointer to the node whose dictEntry's word member is equal to w
    return search_h(w,root);
}


void RBSearchTree::remove(string w){
// remove the node in the tree whose dictEntry's word member is equal to w
// or do nothing when no such node exists
    RBsearchTreeNode *z, *todelete;
    z = search(w);
    if (z==NULL)
        return;
    if (z->left==NULL or z->right == NULL)
        todelete=z;
    else{
        todelete = successor(z);
        z->data = todelete ->data;
    }
    /* now todelete has at most 1 child && if it has non-null child, it must be black and the child is red*/
    if (todelete->left!=NULL){
        todelete->data = todelete->left->data;
        delete todelete->left;
        todelete->left = NULL;
        return;
    }
    if (todelete->right!=NULL){
        todelete->data = todelete->right->data;
        delete todelete->right;
        todelete->right = NULL;
        return;
    }
    if (todelete->nodeColor == BLACK) // now left and right of todelete both NULL
        delete_fixup(todelete);
    if (todelete->parent==NULL)
        root = NULL;
    else if (todelete == todelete->parent->left)
        todelete->parent->left = NULL;
    else
        todelete->parent->right = NULL;
    delete todelete;
}


void RBSearchTree::preOrder(string filename){
    fout.open(filename.c_str());
    preOrder_h(root);
    fout.close();
}

void RBSearchTree::postOrder(string filename){
    fout.open(filename.c_str());
    postOrder_h(root);
    fout.close();
}

void RBSearchTree::inOrder(string filename){
    fout.open(filename.c_str());
    inOrder_h(root);
    fout.close();
}

void RBSearchTree::rotate_left(RBsearchTreeNode *x){
    RBsearchTreeNode *y;
    y = x->right;
    x->right = y->left;
    if (y->left!=NULL)
        y->left->parent = x;
    y->parent = x->parent;
    if (x->parent == NULL)
        root = y;
    else if ( x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;
    y->left = x;
    x->parent = y;
}

void RBSearchTree::rotate_right(RBsearchTreeNode *y){
    RBsearchTreeNode *x;
    x = y->left;
    y->left = x->right;
    if (x->right!=NULL)
        x->right->parent = y;
    x->parent = y->parent;
    if(y->parent==NULL)
        root = x;
    else if (y==y->parent->left)
        y->parent->left = x;
    else
        y->parent->right = x;
    x->right = y;
    y->parent = x;
}

RBsearchTreeNode* RBSearchTree::uncle(RBsearchTreeNode *z){
    RBsearchTreeNode *p, *g;
    if (z->parent!=NULL){
        p = z->parent;
        if (p->parent!=NULL){
            g=p->parent;
            if (p == g->left)
                return g->right;
            else
                return g->left;
        }
    }//z is not root
    return NULL;
}

RBcolor RBSearchTree::color(RBsearchTreeNode *n){
    if(n==NULL)
        return BLACK;
    else
        return n->nodeColor;
}

RBsearchTreeNode* RBSearchTree::sibling(RBsearchTreeNode *n){
    if (n==NULL)
        return NULL;
    else if (n->parent==NULL)
        return NULL;
    else if (n==n->parent->left)
        return n->parent->right;
    else
        return n->parent->left;
}

RBsearchTreeNode* RBSearchTree::successor(RBsearchTreeNode *n){
    if (n == NULL)
        return NULL;
    else if (n->right == NULL)
        return NULL;
    else{
        RBsearchTreeNode *current;
        current = n->right;
        while (current->left!=NULL){
            current = current -> left;
        }
        return current;
    }
}


RBsearchTreeNode* RBSearchTree::insert_h(dictEntry *in, RBsearchTreeNode *current){
    if (*in < current->data->getWord() && current->left!=NULL)
        return insert_h(in, current->left);
    else if (*in < current->data->getWord()){
        current->left = new RBsearchTreeNode(in,current);
        return current->left;
    }
    
    else if (*in > current->data->getWord() && current->right!=NULL)
        return insert_h(in,current->right);
    else if (*in > current->data->getWord()){
        current->right = new RBsearchTreeNode(in,current);
        return current->right;
    }
    else
        return NULL;
}

void RBSearchTree::insert_fixup(RBsearchTreeNode *n){
    // case 1
    if (n->parent == NULL)
        n->nodeColor = BLACK;
    // case 2
    else if (n->parent->nodeColor == BLACK){}
    else{
        RBsearchTreeNode *p,*g,*u,*temp;
        p = n->parent;
        g = p->parent;
        u = uncle(n);
        if (color(u)==BLACK){
            // case 3
            if (n == p->right && p == g->left){
                rotate_left(p);
                temp = p;
                p = n;
                n = temp;
            }
            if (n == p->left && p == g->right){
                rotate_right(p);
                temp = p;
                p = n;
                n = temp;
            }
            // case 4
            p->nodeColor = BLACK;
            g->nodeColor = RED;
            if (n==p->left)
                rotate_right(g);
            else
                rotate_left(g);
        }// uncle is black
        // case 5
        else{
            p->nodeColor = BLACK;
            u->nodeColor = BLACK;
            g->nodeColor = RED;
            insert_fixup(g);
        }
    }
}

RBsearchTreeNode* RBSearchTree::search_h(string w, RBsearchTreeNode *current){
    if (current==NULL)
        return NULL;
    
    else if (*(current->data) == w)
        return current;
    
    else if (*(current->data) > w)
        return search_h(w,current->left);
    
    else
        return search_h(w,current->right);
}

void RBSearchTree::delete_fixup(RBsearchTreeNode *n){
    if (n->parent == NULL)
        return;
    
    // if n->p != NULL, it has to have a sibling
    RBsearchTreeNode *s;
    s = sibling(n);
    
    if (s->nodeColor==RED){     // s1,s2 have to be not NULL and black
        n->parent->nodeColor = RED;
        s->nodeColor = BLACK;
        if (n==n->parent->left)
            rotate_left(n->parent);
        s = sibling(n);
    } // now n has a black sibling
    
    //one of S's child is red
    if (n==n->parent->left && color(s->right)==BLACK && color(s->left)==RED) {
        s->nodeColor = RED;
        s->left->nodeColor = BLACK;
        rotate_right(s);
    }
    else if(n==n->parent->right && color(s->left)==BLACK && color(s->right)==BLACK){
        s->nodeColor = RED;
        s->right->nodeColor = BLACK;
        rotate_left(s);
    }
    
    if (n==n->parent->left && color(s->right)==RED){
        s->nodeColor = n->parent->nodeColor;
        n->parent->nodeColor = BLACK;
        s->right->nodeColor = BLACK;
        rotate_left(n->parent);
        return;
    }
    else if(n==n->parent->right && color(s->left)==RED){
        s->nodeColor = n->parent->nodeColor;
        n->parent->nodeColor = BLACK;
        s->left->nodeColor = BLACK;
        rotate_right(n->parent);
        return;
    }
    
    // both S's children are black
    if (s->left->nodeColor == BLACK && s->right->nodeColor == BLACK){
        s->nodeColor = RED;
        n->parent->nodeColor = BLACK;
    }
}



void RBSearchTree::preOrder_h(RBsearchTreeNode *n){
    if(n!=NULL){
        preOrder_h(n->left);
        visit(n);
        preOrder_h(n->right);
    }
}
void RBSearchTree::postOrder_h(RBsearchTreeNode *n){
    if(n!=NULL){
        preOrder_h(n->right);
        visit(n);
        preOrder_h(n->left);
    }
}
void RBSearchTree::inOrder_h(RBsearchTreeNode *n){
    queue<RBsearchTreeNode> Q;
    Q.push(*n);
    RBsearchTreeNode *current;
    while (!Q.empty()){
        current = &Q.front();
        Q.pop();
        visit(current);
        if (current->left != NULL)
            Q.push(*current->left);
        if (current->right != NULL)
            Q.push(*current->right);
    }
}
void RBSearchTree::visit(RBsearchTreeNode *p){
    string word,definition;
    word = p->data->getWord();
    definition = p->data->getDefinition();
    fout << '[' << word << "]: [" << definition << "]\n\n";
}

void RBSearchTree::destroy_RBtree(RBsearchTreeNode *leaf){
    if(leaf!=0){
        destroy_RBtree(leaf->left);
        destroy_RBtree(leaf->right);
    }
    delete leaf;
}