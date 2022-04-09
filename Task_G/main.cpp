#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<char, int> letterWithWeight;

int main() {

    //Ввод данных
    map<char, int> lettersWeight;
    map<char, int> lettersAmount;
    string input;
    string answer;
    cin >> input;
    char key = 'a';
    while (key - 1 != 'z') {
        int temp;
        cin >> temp;
        lettersAmount.insert(make_pair(key, 0));
        lettersWeight.insert(make_pair(key, temp));
        key += 1;
    }

    //Тело программы
    for (auto i: input) {
        lettersAmount[i] = lettersAmount[i] + 1;
    }

    for (auto i: input) {
        if (lettersAmount[i] % 2 != 0) {
            answer.insert(answer.end(), i);
            lettersAmount[i] = lettersAmount[i] - 1;
        }
    }

    vector<letterWithWeight> letters;
    copy(lettersWeight.begin(), lettersWeight.end(), back_inserter<vector<letterWithWeight>>(letters));
    sort(letters.begin(), letters.end(),
         [](const letterWithWeight &l, const letterWithWeight &r)
         {
             if (l.second != r.second) {
                 return l.second < r.second;
             }

             return l.first < r.first;
         });

    string partOfAnswer;
    for (auto p: letters) {
        if (lettersAmount[p.first] > 0) {
            partOfAnswer.insert(partOfAnswer.begin(), p.first);
            lettersAmount[p.first] = lettersAmount[p.first] - 2;
        }
    }

    for (auto & letter : letters) {
        while (lettersAmount[letter.first] > 0){
            answer.insert(answer.begin(), letter.first);
            lettersAmount[letter.first] = lettersAmount[letter.first] - 1;
        }
    }


    for (auto it = partOfAnswer.rbegin(); it != partOfAnswer.rend(); it++){
        answer.insert(answer.begin(), *(it));
        answer.insert(answer.end(), *(it));
    }

    //Вывод данных
    cout << answer << endl;
    return 0;
}
