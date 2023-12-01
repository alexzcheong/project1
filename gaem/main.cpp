#include <iostream>
#include <stack>
#include <queue>
#include <fstream>
#include "player.h"
#include "leaderboardQuickSort.h"
#include "US_trivia.h"
#include "blackJack.h"
#include "numGuess.h"
using namespace std;
int main() {
    stack<Player> playerStack;
    queue<Player> playerQueue;
    vector<Player> playerIdx;
    bool gameState = true;
    while(gameState) {
        int gameMode;
        cout << "Welcome to Alexzander's Arcade" << endl;
        cout << "choose a game mode (0/1/2/3/4)" << endl;
        cout << "0: end game" << endl << "1: player select(do this first)" << endl << "2: BlackJack" << endl;
        cout << "3: Trivia" << endl << "4: Number Guessing" << endl << "5: Leaderboards" << endl;
        cout << "6: Spot in line" << endl;

        cin >> gameMode;//can code safeguards, but not the point of this lab

        switch (gameMode) {
            case 0: //end game
                playerQueue.pop();
                cout << "Thanks for Playing" << endl;
                gameState = false;
                break;

            case 1: //make new player
            {
                string option = "n", name = "john";
                cout << "are you a new player? y/n" << endl;
                cin >> option;//can code safeguards if time allows
                if (option == "y") {
                    cout << "enter name" << endl;
                    cin >> name;
                    playerIdx.push_back(new Player(name));
                }
                else{
                    cout << "enter name" << endl;//case sensitive
                    cin >> name;
                }
                bool isThere = false;
                for (Player p: playerIdx) {
                    if (p.getName() == name) {
                        isThere = true;
                        playerQueue.push(p);
                    }
                }
                cout << "checking for player..." << endl;
                if (!isThere) {
                    gameMode = 0;
                    cout << "no player of specified name detected" << endl;
                }
                break;
            }
            case 2: {   //blackjack game should work
                Player current = playerQueue.front();
                playerQueue.pop();
                playerStack.push(current);
                current.addScore(current.getScore()*playBlackJack());
                current.incrementGame();
                playerQueue.push(current); //keep playing until chooses end
                break;
            }


            case 3: //trivia game works
            {
                Player current = playerQueue.front();
                playerQueue.pop();
                playerStack.push(current);
                current.addScore(playTrivia());
                current.incrementGame();
                playerQueue.push(current); //keep playing until chooses end
                break;
            }
            case 4:
            {
                Player current = playerQueue.front();
                playerQueue.pop();
                playerStack.push(current);
                current.addScore(numGuess());
                current.incrementGame();
                playerQueue.push(current); //keep playing until chooses end
                break;
            }
            case 5://leaderboard works
            {
                //ofstream fout("leaderboard.txt"); //optional save file
                leaderboardQuickSort(playerIdx, 0, playerIdx.size() - 1);//sorts lowest to highest
                cout << "*TOP 5 PLAYERS*" << endl;
                for(int i = playerIdx.size() - 1; i >= 0; i--){
                    Player* ptr = &playerIdx[i];
                    cout << "NAME: " << ptr->getName() << " GAMES PLAYED: "<< ptr->numPlayed() <<" SCORE: " << ptr->getScore() << endl;
                    //fout << "NAME: " << ptr->getName() << " GAMES PLAYED: "<< ptr->numPlayed() <<" SCORE: " << ptr->getScore() << endl;
                    if (playerIdx.size() - i >= 5){
                        break;//only show top 5
                    }
                }
                break;
            }
            case 6:
            {
                string name, compare;
                int pos = 0;
                cout << "what is your username?" << endl;
                cin >> name;
                queue<Player> temp = playerQueue;
                while (!temp.empty()){
                    compare = temp.front().getName();
                    temp.pop();
                    if(compare == name){
                        cout << "there are " << pos << " people ahead of you in line" << endl;
                        break;
                    }
                    pos++;
                }
                break;
            }
        }
    }
    return 0;
}

