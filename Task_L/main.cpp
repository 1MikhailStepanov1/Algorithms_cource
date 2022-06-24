#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int main() {

    //Ввод данных
    int n, k;
    stack<pair<int, int>> window1, window2;
    cin >> n >> k;

    //Тело программы
    for (int i = 0; i < k; i++){
        int element;
        cin >> element;
        int minimal = window1.empty() ? element : min(element, window1.top().second);
        window1.push(make_pair(element, minimal));
    }

    if (window1.empty() || window2.empty()){
        int temp = window1.empty() ? window2.top().second : window1.top().second;
        cout << temp << " ";
    } else {
        int temp = min(window1.top().second, window2.top().second);
        cout << temp << " ";
    }

    n = n - k;
    while (n != 0){
        if (window2.empty()) {
            while (!window1.empty()) {
                int element = window1.top().first;
                window1.pop();
                int tempMin = window2.empty() ? element : min(element, window2.top().second);
                window2.push(make_pair(element, tempMin));
            }
        }
        window2.pop();

        int temp;
        cin >> temp;

        int minimal = window1.empty() ? temp : min(temp, window1.top().second);
        window1.push(make_pair(temp, minimal));

        if (window1.empty() || window2.empty()){
            temp = window1.empty() ? window2.top().second : window1.top().second;
            cout << temp << " ";
        } else {
            temp = min(window1.top().second, window2.top().second);
            cout << temp << " ";
        }
        n--;
    }
    return 0;
}
