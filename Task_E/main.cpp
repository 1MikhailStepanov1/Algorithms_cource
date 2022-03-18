#include <iostream>
#include <vector>

using namespace std;
int main() {
    int cowsAmount;
    int stallsAmount;
    vector<int> coordinates;
    //Ввод данных
    cin >> stallsAmount;
    cin >> cowsAmount;
    int k = 0;
    while (k != stallsAmount){
        int temp;
        cin >> temp;
        coordinates.push_back(temp);
        k++;
    }

    //Тело программы
    int l1 = 0;
    int r1 = coordinates[stallsAmount-1]+1;
    while (l1 < r1-1){
        int m = (r1+l1)/2;
        int amount = 1;
        int prevElement = coordinates[0];
        for (int i = 1; i < coordinates.size(); i++){
            if (coordinates[i] - prevElement >= m){
                amount+=1;
                prevElement = coordinates[i];
            }
        }
        if (amount < cowsAmount){
            r1 = m;
        } else l1 = m;
    }
    //Вывод данных
    cout << l1;
    return 0;
}
