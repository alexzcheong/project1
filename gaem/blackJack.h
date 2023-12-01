//
// Created by me on 11/25/2023.
//

#ifndef CLIONPROJECTS_BLACKJACK_H
#define CLIONPROJECTS_BLACKJACK_H
#include "deck.h"
int getScore(const vector<Card>& hand){
    int sum = 0;
    int ace_sum = 0;
    for(Card c : hand){
        if (c.getVal() == 11){
            ace_sum += 11;//ace can be 1 or 11
        }
        else{
            sum += c.getVal();
        }
    }
    if (sum > 10){
        ace_sum /= 11; // ace will have value of 1 above 10 sum
    }
    return sum + ace_sum;
}
float playBlackJack() {
    Deck deck;
    vector<Card> playerHand;
    vector<Card> dealerHand;
    int playerSum, dealerSum;
    cout << "Now playing: BlackJack against dealer" << endl;
    cout << "if you win, you get .5x your current points" << endl;
    cout << "if you lose, you lose .1x your current points" << endl;
    cout << "if you draw, your points remain the same" << endl;
    cout << "if you win with blackjack, you triple your current points" << endl;

    deck.shuffle();
    playerHand.push_back(deck.deal());
    dealerHand.push_back(deck.deal());
    playerHand.push_back(deck.deal());
    dealerHand.push_back(deck.deal());

    cout << "your current hand" << endl;
    for (Card c: playerHand) {
        cout << c << " ";
    }
    cout << endl;
    cout << "dealer revealed card" << endl;
    cout << dealerHand[0];

    string choice;
    while (true) {
        cout << "Do you want to hit or stand? (h/s): ";
        cin >> choice;
        if (choice == "h") {
            playerHand.push_back(deck.deal()); //deal and print hand
            cout << "player hand: ";
            for (const Card& c: playerHand) {
                cout << c << " ";
            }
            cout << endl;
            // Check if the player has busted
            if (getScore(playerHand) > 21) {
                cout << "Busted!" << endl;
                break;
            }
        }
        else if (choice == "s") {
            break;
        }
        else {
            cout << "Invalid choice. Please enter 'h' or 's'." << endl;
        }
    }

    //dealer turn
    cout << "Dealer's turn" << endl << "dealers hand: ";
    cout << dealerHand[0] << " " << dealerHand[1] << " ";
    dealerSum = getScore(dealerHand);
    while(dealerSum < 17){
        dealerSum += deck.top().getVal();
        cout << deck.top() << " ";
        dealerHand.push_back(deck.deal());
    }
    cout << endl;
    playerSum = getScore(playerHand);
    dealerSum = getScore(dealerHand);
    cout << "player score: " << playerSum << " dealer score: " << dealerSum << endl;

    if( (playerSum > 21 && dealerSum > 21) || (playerSum == dealerSum) ){
        cout << "It's a draw!" << endl;
        return 0;
    }
    else if (playerSum == 21 ){
        cout << "You win via BlackJack!" << endl;
        return 2;
    }
    else if (playerSum > dealerSum || (dealerSum > 21) ){
        cout << "You win!" << endl;
        return .5;
    }
    else{
        cout << "You lost..." << endl;
        return -.1;
    }

}
#endif //CLIONPROJECTS_BLACKJACK_H
