#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<short> colors;
vector<short> colorsInProcess;
vector<vector<short>> graph;
short answer;

void deep_search(short top){
    colorsInProcess[top] = 1;
    for (auto i : graph[top]){
        if (colors[i] == 2){
            continue;
        }
        if (colorsInProcess[i] == 1){
            answer+=1;
            continue;
        }
        deep_search(i);
    }
    colorsInProcess[top] = 0;
    colors[top] = 2;
}

int main(){
    //Ввод данных
    short n;
    cin >> n;
    colors.assign(n, 0);
    graph.assign(n, {});
    for (short i = 0; i < n; i++){
        short temp;
        cin >> temp;
        graph[temp-1].push_back(i);
    }

    //Тело программы
    for (short i = 0; i < n; i++){
        if (colors[i] != 2) {
            colorsInProcess.assign(n, 0);
            deep_search(i);
        }
    }

    //Вывод данных
    cout << answer;
    return 0;
}