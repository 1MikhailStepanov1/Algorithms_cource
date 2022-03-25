#include <iostream>
#include <vector>
#include <queue>
#include <list>

using namespace std;

int main() {

    string input;
    vector<string> answer;

	//Ввод данных
    while (cin >> input){
        answer.push_back(input);
    }
	
	//Тело программы
    for (auto it = answer.begin(); it != answer.end(); it++){
        for (auto iter = answer.begin()+1; iter != answer.end(); iter++){
            if ((*iter + *(iter-1)) > (*(iter-1) + *iter)){
                string temp = *iter;
                *iter = *(iter-1);
                *(iter-1) = temp;
            }
        }
    }
	
	//Вывод данных
    for (auto & it : answer){
        cout << it;
    }
    return 0;
}
