#include <iostream>
#include <vector>
#include <map>


using namespace std;
int main() {
    //Ввод данных
    string input;
    cin >> input;

    //Тело программы
    vector<int> temp;
    map<int,int> animalMap;
    int number = 1;
    for (int i = 0; i < input.length(); i++){
        if (islower(input[i])){
            animalMap.insert(make_pair(i, number));
            number+=1;
        }
    }
    for (int i = 0; i < input.length(); i++){
        if (!temp.empty()){
            if (isupper(input[i])){
                if (islower(input[temp.back()]) && input[temp.back()] == tolower(input[i])){
                    animalMap.insert(make_pair(i,animalMap.find(temp.back())->second));
                    animalMap.extract(temp.back());
                    //input[i] = animalMap.find(temp.back())->second + '0';
                    temp.pop_back();
                } else temp.push_back(i);
            } else {
                if (isupper(input[temp.back()]) && input[temp.back()] == toupper(input[i])){
                    animalMap.insert(make_pair(temp.back(),animalMap.find(i)->second));
                    animalMap.extract(i);
                    //input[temp.back()] = animalMap.find(i)->second + '0';
                    temp.pop_back();
                } else temp.push_back(i);
            }
        }else {
            temp.push_back(i);
        }
    }

    //Вывод данных
    if (!temp.empty()){
        cout << "Impossible" << endl;
    } else {
        cout << "Possible" << endl;
        for (int i = 0; i < input.length(); i++){
            int znachenie = animalMap.find(i)->second;
            if (znachenie !=0){
                cout << znachenie << " ";
            }
        }
    }
    return 0;
}
