//
// Created by me on 11/2/2023.
//

#ifndef GAEM_PLAYER_H
#define GAEM_PLAYER_H
#include <iostream>
class Player{
private:
    std::string name;
    int score;
    int gamesPlayed;
public:
    Player();
    Player(std::string n);
    int getScore();
    int numPlayed();
    std::string getName();
    void addScore(int s);
    void incrementGame();

    Player(Player *pPlayer);
};
Player::Player(){
    name = "john";
    score = 0;
    gamesPlayed = 0;
}
Player::Player(std::string n){
    name = n;
    score = 0;
    gamesPlayed = 0;
}
int Player::getScore(){
    return score;
}
int Player::numPlayed(){
    return gamesPlayed;
}
std::string Player::getName(){
    return name;
}
void Player::addScore(int s){
    score += s;
}
void Player::incrementGame() {
    gamesPlayed++;
}

Player::Player(Player *pPlayer) {
    name = pPlayer->name;
    score = pPlayer->score;
    gamesPlayed = pPlayer->gamesPlayed;
}

#endif //GAEM_PLAYER_H
