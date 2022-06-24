#include <iostream>
#include <vector>

using namespace std;

int main() {
    //Ввод данных
    int n;
    cin >> n;
    vector<int> goblinsQueue;

    //Тело программы
    while (n != 0){
        char mark;
        int orderNumber;
        int temp;
        if (goblinsQueue.size() % 2 == 0){
            temp = goblinsQueue.size()/2;
        } else temp = goblinsQueue.size()/2+1;
        cin >> mark;
        switch (mark) {
            case '*':
                cin >> orderNumber;
                if (goblinsQueue.empty()){
                    goblinsQueue.push_back(orderNumber);
                }else {
                    goblinsQueue.insert(goblinsQueue.begin() + temp, orderNumber);
                }
                break;
            case '+':
                cin >> orderNumber;
                goblinsQueue.push_back(orderNumber);
                break;
            default:
                cout << *(goblinsQueue.begin()) << endl;
                goblinsQueue.erase(goblinsQueue.begin());
                break;
        }
        n--;
    }
    return 0;
}
