#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n = 0;
    string input;
    vector<string> answer;
    while (n != 4){
        cin >> input;
        answer.push_back(input);
        n +=1;
    }

//    for (int i = 0; i < answer.size(); i++){
//        for (int j = 0; j<answer.size(); j++){
//            if (answer[j-1] + answer[j] < answer[j] + answer[j-1]){
//                string temp = answer[j];
//                answer[j] = answer[j-1];
//                answer[j-1] = temp;
//            }
//        }
//    }

    for (auto it = answer.begin(); it != answer.end(); it++){
        for (auto iter = answer.begin()+1; iter != answer.end(); iter++){
            if ((*iter + *(iter-1)) > (*(iter-1) + *iter)){
                string temp = *iter;
                *iter = *(iter-1);
                *(iter-1) = temp;
            }
        }
    }

    for (auto & it : answer){
        cout << it;
    }
    return 0;
}
