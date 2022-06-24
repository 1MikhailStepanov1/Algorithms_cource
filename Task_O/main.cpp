#include <iostream>
#include <unordered_map>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

bool answer = true;
unordered_map<short, vector<short>> neighbours;
unordered_map<short, short> color;

short invert(short c) {
    return c == 1 ? 2 : 1;
}

void search(short v, short vColor) {
    color[v] = vColor;

    for (short u: neighbours[v]) {
        if (color[u] == 0) {
            search(u, invert(vColor));
        } else if (color[u] == vColor) {
            answer = false;
            return;
        }
    }
}

int main() {
    //Ввод данных
    short n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        short temp1, temp2;
        cin >> temp1 >> temp2;

        if (color.count(temp1) == 0) {
            color.insert(make_pair(temp1, 0));
        }
        if (color.count(temp2) == 0) {
            color.insert(make_pair(temp2, 0));
        }

        if (neighbours.count(temp1) == 0){
                vector<short> top = {};
                top.push_back(temp2);
                neighbours.insert(make_pair(temp1, top));
        } else {
            neighbours[temp1].push_back(temp2);
        }
        if (neighbours.count(temp2) == 0) {
            vector<short> top = {};
            top.push_back(temp1);
            neighbours.insert(make_pair(temp2, top));
        } else neighbours[temp2].push_back(temp1);
    }

    //Тело программы
    for (short i = 1; i <= color.size(); i++) {
        if (color[i] == 0) {
            search(i, 1);
        }
    }

    //Вывод ответа
    if (answer){
        cout << "YES";
    } else cout << "NO";
    return 0;
}
