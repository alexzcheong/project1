//
// Created by me on 11/26/2023.
//

#ifndef CLIONPROJECTS_NUMGUESS_H
#define CLIONPROJECTS_NUMGUESS_H

#include<iostream>
#include "binTree.h"
using namespace std;

int numGuess(){
    treeNode* root = NULL;
    treeNode* pos;
    int num[100];
    string check;
    for(int i = 0; i < 100; i++){
        num[i] = i;
    }
    root = sortedArrBST(num, 0, 99);
    pos = root;
    inOrder(root);
    cout << "Think of a number. If I can't guess it in 6 tries, you win 2 points" << endl;
    for(int i = 0; i < 6; i++){
        cout << "is your number: " << pos-> data << " (y/n)" << endl;
        cin >> check;
        if (check == "y"){
            cout << "gottem" << endl;
            return 0;
        }
        cout << "Is your number greater than: " << pos->data << " (y/n)" <<endl;
        cin >> check;
        if(check == "y" && pos->right != NULL){
            pos = pos->right;
        }
        else if (check == "n" && pos->left != NULL){
            pos = pos->left;
        }
    }
    cout << "wow I couldn't guess your number, you get 2 points wooo" << endl;
    return 2;
}
#endif //CLIONPROJECTS_NUMGUESS_H
