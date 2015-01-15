//
//  dictionary.cpp
//  project1
//
//  Created by Yingying Wu on 12/10/14.
//  Copyright (c) 2014 Yingying Wu. All rights reserved.
//  status: search should print or return?

#include "dictionary.h"
#include <iostream>
#include <fstream>

using namespace std;

dictionary::dictionary(searchTree *p){
// initializes dict to that pointer
// this will let the user choose the type of search tree he wants the dict to use
    dict = p;
}

dictionary::~dictionary(){
    delete dict;
}

string dictionary::search(string w){
    string key = w;
    for (int i = 0; i<key.length(); i++) {
        key[i]=tolower(key[i]);
    }
    treeNode *result;
    
    result = dict->search(key);
    string print;
    
    if (result == NULL){
        print = "The word [" + w + "] was not found in the dictionary.\n\n";
        cout << print;
        return print;
    }
    else{
        string word,def;
        word = result->data->getWord();
        def = result->data->getDefinition();
        print = '[' + word + "] : [" + def + "]\n\n";
        cout << print;
        return print;
    }
}

void dictionary::add(dictEntry *in){
    dict->insert(in);
}

void dictionary::remove(string w){
    dict->remove(w);
}

void dictionary::readFile(string filename){
    ifstream fin;
    fin.clear();
    fin.open(filename.c_str());
    if (fin.fail()){
        cout << "ERROR: file called " << filename << " did NOT open." << endl;
        exit(-1);
    }
    
    string word, def;
    dictEntry *temp;
    while (!fin.eof()){
        getline(fin,word,':');
        getline(fin, def,'\n');
        def.erase(def.begin());
        def.pop_back();
        for (int i = 0; i<word.length(); i++) {
            word[i]=tolower(word[i]);
        }
        temp = new dictEntry(word,def);
        dict->insert(temp);
        getline(fin,word);
    }
    
    fin.close();
    
}

void dictionary::writeFilePreorder(string filename){
    dict->preOrder(filename);
}
void dictionary::writeFileInorder(string filename){
    dict->inOrder(filename);
}
void dictionary::writeFilePostorder(string filename){
    dict->postOrder(filename);
}





