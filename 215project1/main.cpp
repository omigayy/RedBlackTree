//
//  main.cpp
//  project1
//
//  Created by Yingying Wu on 12/9/14.
//  Copyright (c) 2014 Yingying Wu. All rights reserved.
//  status: 16 done || fout in two trees


#include <iostream>
#include <string>
#include <fstream>
#include "dictionary.h"
#include "binarySearchTree.h"
#include "RBSearchTree.h"

using namespace std;

int main(){
    // choose tree
    cout << "Do you want to 1, use a binary search tree or 2, use a Red-Black tree?";
    char treeType;
    cin >> treeType;
    cout << endl << endl;
    searchTree *dictStore;
    if (treeType=='1')
        dictStore = new binarySearchTree;
    else if (treeType == '2')
        dictStore = new RBSearchTree;
    
    dictionary *dict=new dictionary(dictStore);     //initialize dictionary
    
    
    string w,def;
    char choice,traversalC;
    string filename;
    do{
        cout << "make a choice among these:\n1,read a file\n2,manually add an entry\n3,search for a word\n4,remove a word\n5,write the dictionary on file\n0,end the program\n";
        cin >> choice;
        cout << endl << endl;
        switch (choice) {
            case '1':{
                cout << "Enter filename: ";
                cin >> filename;
                cout << endl << endl;
                dict->readFile(filename);
                break;}
            case '2':{
                cout << "Enter word: ";
                cin >> w;
                cout << "\nEnter definition: ";
                cin >> def;
                cout << endl << endl;
                for (int i = 0; i<w.length(); i++) {
                    w[i]=tolower(w[i]);
                }
                dictEntry *in = new dictEntry(w,def);
                dict->add(in);
                break;}
            case '3':{
                cout << "What are you looking for(word): ";
                cin >> w;
                cout << "\n\n";
                dict->search(w);
                break;}
            case '4':{
                cout << "What are you deleting(word): ";
                cin >> w;
                cout << "\n\n";
                cout << dict->search(w);
                break;}
            case '5':{
                cout << "which traversal? a,pre-order; b, post-order; c,in-order: ";
                cin >> traversalC;
                cout << "\nfilename: ";
                cin >> filename;
                cout << "\n\n";
                switch (traversalC) {
                    case 'a':
                        dict->writeFilePreorder(filename);
                        break;
                    case 'b':
                        dict->writeFilePostorder(filename);
                        break;
                    case 'c':
                        dict->writeFileInorder(filename);
                        break;
                    default:
                        break;
                }
                break;}
            case '0':{
                delete dict;
                return 0;}

            default:{
                break;}
        }
    }while (choice!='0');
    
}
