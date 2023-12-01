//
// Created by me on 11/25/2023.
//

#ifndef CLIONPROJECTS_CARD_H
#define CLIONPROJECTS_CARD_H
#include<iostream>
using namespace std;
class Card {
    string rank, suite;
    int value;
public:
    Card(string r, string s, int val);
    int getVal();//no need for getrank and getsuite bc this is only for blackjack
    friend ostream &operator << (ostream & out, const Card &card);
};
Card::Card(string r, string s, int val){
    rank = r;
    suite = s;
    value = val;
}
int Card::getVal(){
    return value;
}
ostream& operator <<(ostream &out, const Card &card){
    out << card.rank << card.suite << endl;
    return out;
}
#endif //CLIONPROJECTS_CARD_H
