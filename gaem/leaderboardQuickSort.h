//
// Created by me on 11/4/2023.
//

#ifndef SORTING_QUICKSORT_H
#define SORTING_QUICKSORT_H
#include<iostream>
#include <vector>
using namespace std;


void swap(vector<Player>& v, int x, int y) {
    Player temp = v[x];
    v[x] = v[y];
    v[y] = temp;

}

void leaderboardQuickSort(vector<Player> &vec, int left, int right) {
    int i, j, mid, piv;
    i = left;
    j = right;
    mid = left + (right - left) / 2;
    piv = vec[mid].getScore();

    while (i < right || j > left) {
        while (vec[i].getScore() < piv)
            i++;
        while (vec[j].getScore() > piv)
            j--;

        if (i <= j) {
            swap(vec, i, j); //error=swap function doesnt take 3 arguments
            i++;
            j--;
        }
        else {
            if (i < right)
                leaderboardQuickSort(vec, i, right);
            if (j > left)
                leaderboardQuickSort(vec, left, j);
            return;
        }
    }
}



#endif //SORTING_QUICKSORT_H
