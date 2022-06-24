#include <iostream>
#include <bits/stdc++.h>
using namespace std;

short n, visitedAmount, revVisitedAmount;
vector<bool> visited;
vector<vector<int>> graph_for_search;

void deep_search (int topInd, int size, bool isReverse) {
    visited[topInd] = true;
    if (!isReverse) {
        visitedAmount +=1;
        for (int i = 0; i < graph_for_search[topInd].size(); i++) {
            if (!visited[i] && graph_for_search[topInd][i] != 0 && graph_for_search[topInd][i] <= size) {
                deep_search(i, size, isReverse);
            }
        }
    } else {
        revVisitedAmount +=1;
        for (int i = 0; i < n; i++) {
            if (!visited[i] && graph_for_search[i][topInd] != 0 && graph_for_search[i][topInd] <= size) {
                deep_search(i, size, isReverse);
            }
        }
    }
}

int main() {
    //Ввод данных
    cin >> n;
    int min = 0;
    int max = -1;

    for (short i = 0; i < n; i++){
        vector<int> tempvect = {};
        for (short j = 0; j < n; j++){
            int temp;
            cin >> temp;
            tempvect.push_back(temp);
            if (temp > max){
                max = temp;
            }
        }
        graph_for_search.push_back(tempvect);
    }

    //Тело программы
    while (min < max){
        int mid = (max + min) / 2;
        visited = {};
        visited.assign(n, false);
        visitedAmount = 0;
        deep_search(0, mid, false);
        visited = {};
        visited.assign(n, false);
        revVisitedAmount = 0;
        deep_search(0, mid, true);
        if (visitedAmount == n && revVisitedAmount == n){
            max = mid;
        } else min = mid + 1;
    }

    //Вывод данных
    cout << max;
    return 0;
}
