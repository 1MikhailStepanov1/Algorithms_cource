#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int n, k;
    int answer = 0;
    vector<int> data;
    cin >> n >> k;
    while (n){
        int temp;
        cin >> temp;
        data.push_back(temp);
        n--;
    }
    sort(data.begin(), data.end(), greater<int>());
    for (int i = 1; i <= data.size(); i++){
        if (i % k != 0){
            answer += data[i-1];
        }
    }
    cout << answer;
    return 0;
}
