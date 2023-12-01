#ifndef _DECK_H_
#define _DECK_H_

#include <iostream>
#include <vector>
#include "card.h"
#include <ctime>
#include <cstdlib>
using namespace std;

class Deck
{
public:
    Deck();
    void shuffle();
    Card deal();
    Card top();

private:
    string unicode_suite[4] =  {"\u2660", "\u2661", "\u2662", "\u2663"}; //spade, heart, diamond, club, brrb <-color order
    string card_rank[13] = {"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
    vector<Card> deckofCards;
};

Deck::Deck(){
    for(const string& s: unicode_suite){
        for (int i = 0; i < 13; i++) {
            deckofCards.emplace_back(       card_rank[i], s, (i < 8)*(i + 2) + (i < 12 && i >= 8)*10 + (i == 12)*11        );
            //product of sums to set cards to correct values (in blackjack there is no 12-13 for values)
        }
    }
}
void Deck::shuffle(){
    srand(time(NULL));
    for (int i = 0; i < deckofCards.size(); i++) {
        int j = rand() % deckofCards.size();
        swap(deckofCards[i], deckofCards[j]);
    }
}
Card Deck::deal(){
    Card temp = deckofCards.back();
    deckofCards.pop_back();
    return temp;
}
Card Deck::top(){
    return deckofCards.back();
}
#endif