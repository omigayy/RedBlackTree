//
//  binarySearchTree.cpp
//  project1
//
//  Created by Yingying Wu on 12/9/14.
//  Copyright (c) 2014 Yingying Wu. All rights reserved.
//

#include "binarySearchTree.h"
#include <fstream>
#include <iostream>
#include <queue>

using namespace std;

binarySearchTree::binarySearchTree(){
    // set the root to NULL
    root = NULL;
}

binarySearchTree::~binarySearchTree(){
    destroy_tree(root);
}

void binarySearchTree::insert(dictEntry *in){
    // insert in in the tree
    if (root == NULL){
        root = new searchTreeNode(in);
    }
    else
        insert_h(in,root);
}

searchTreeNode* binarySearchTree::search(string w){
// return a pointer to the node whose dictEntry's word member is equal to w
    return search_h(w,root);
}

void binarySearchTree::remove(string w){
// remove the node in the tree whose dictEntry's word member is equal to w
// or do nothing when no such node exists
    searchTreeNode *todelete;
    todelete = search(w);
    if (todelete != NULL){
        
        if(todelete->parent != NULL){
            if (todelete->left==NULL){
                if(todelete == todelete->parent->left){
                    todelete->parent->left = todelete->right;
                    delete todelete;
                }
                else{
                    todelete->parent->right = todelete->right;
                    delete todelete;
                }
            }//left == NULL
            else if(todelete->right == NULL){
                if(todelete == todelete->parent->left){
                    todelete->parent->left = todelete->left;
                    delete todelete;
                }
                else{
                    todelete->parent->right = todelete->left;
                    delete todelete;
                }
            }//r == NULL
            else{
                searchTreeNode *todeleteSucc;
                todeleteSucc = successor(todelete);
                todelete->data = todeleteSucc->data;
                //apply same alg here
                if(todeleteSucc == todeleteSucc->parent->left){
                    todeleteSucc->parent->left = todeleteSucc->right;
                    delete todeleteSucc;
                }
                else{
                    todeleteSucc->parent->right = todeleteSucc->right;
                    delete todeleteSucc;
                }// I don't think this else is necessary because Succ will always be the left most one so it must be parent's left child but I'll just leave it here.
            }// two children
        }//not root
        
        else{    // tobedelete == root
            if (todelete->left == NULL){
                root = todelete->right;
                delete todelete;
            }
            else if (todelete->right == NULL){
                root = todelete->left;
                delete todelete;
            }
            else{
                searchTreeNode *todeleteSucc;
                todeleteSucc = successor(todelete);
                todelete->data = todeleteSucc->data;
                if(todeleteSucc == todeleteSucc->parent->left){
                    todeleteSucc->parent->left = todeleteSucc->right;
                    delete todeleteSucc;
                }
            }
        }// end root
        
    }//todelete in the tree
}

void binarySearchTree::preOrder(string filename){
    fout.open(filename.c_str());
    preOrder_h(root);
    fout.close();
}

void binarySearchTree::postOrder(string filename){
    fout.open(filename.c_str());
    postOrder_h(root);
    fout.close();
}

void binarySearchTree::inOrder(string filename){
    fout.open(filename.c_str());
    inOrder_h(root);
    fout.close();
}

void binarySearchTree::insert_h(dictEntry *in, searchTreeNode *current){
    if (*in == current->data->getWord())
        return;
    else if (*in < current->data->getWord()
             ){
        if (current->left == NULL){
            current->left = new searchTreeNode(in);
        }
        else
            insert_h(in,current->left);
    }
    else if(current->right==NULL){
        current->right = new searchTreeNode(in);
    }
    else
        insert_h(in,current->right);
}

searchTreeNode* binarySearchTree::search_h(string w, searchTreeNode *current){
    if (current==NULL)
        return NULL;
    
    else if (*(current->data) == w)
        return current;
    
    else if (*(current->data) > w)
        return search_h(w,current->left);
    
    else
        return search_h(w,current->right);
}

searchTreeNode* binarySearchTree::successor(searchTreeNode *n){
    if (n == NULL)
        return NULL;
    else if (n->right == NULL)
        return NULL;
    else{
        searchTreeNode *current;
        current = n->right;
        while (current->left!=NULL){
            current = current -> left;
        }
        return current;
    }
}


void binarySearchTree::preOrder_h(searchTreeNode *n){
    if(n!=NULL){
        preOrder_h(n->left);
        visit(n);
        preOrder_h(n->right);
    }
}
void binarySearchTree::postOrder_h(searchTreeNode *n){
    if(n!=NULL){
        preOrder_h(n->right);
        visit(n);
        preOrder_h(n->left);
    }
}
void binarySearchTree::inOrder_h(searchTreeNode *n){
    queue<searchTreeNode> Q;
    Q.push(*n);
    searchTreeNode *current;
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


void binarySearchTree::visit(searchTreeNode *p){
    string word,definition;
    word = p->data->getWord();
    definition = p->data->getDefinition();
    fout << '[' << word << "]: [" << definition << "]\n\n";
}

void binarySearchTree::destroy_tree(searchTreeNode *leaf){
    if(leaf!=0){
        destroy_tree(leaf->left);
        destroy_tree(leaf->right);
    }
    delete leaf;
}

