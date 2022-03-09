#include <iostream>
#include <map>
#include <vector>
#include <set>

using namespace std;
int main() {
    string input;
    string delimiter = "=";
    string leftPart;
    string rightPart;
    map<string, vector<int>> variableMap;
    vector<map<string, int>> changedVariables;
    while (cin >> input) {
        if (input[0] == '{') {
            map<string, int> newPart;
            changedVariables.push_back(newPart);
        } else if (input[0] == '}') {
            for (auto it = changedVariables.back().begin(); it != changedVariables.back().end(); it++) {
                if (variableMap.find(it->first) != variableMap.end()) {
                    for (int i = 0; i < it->second; i++) {
                        variableMap[it->first].pop_back();
                    }
                }
            }
            changedVariables.pop_back();
        } else {
            leftPart = input.substr(0, input.find(delimiter));
            rightPart = input.substr(input.find(delimiter)+1, input.length());
            try {
                int i = stoi(rightPart);
                if (variableMap.find(leftPart) == variableMap.end()){
                    vector<int> tempVector;
                    tempVector.push_back(i);
                    variableMap.insert(make_pair(leftPart, tempVector));
                    if (!changedVariables.empty()) {
                        if (changedVariables.back().find(leftPart) != changedVariables.back().end()){
                            changedVariables.back()[leftPart] +=1;
                        }else changedVariables.back().insert(make_pair(leftPart, 1));
                    }
                } else {
                    if (!changedVariables.empty()) {
                        if (changedVariables.back().find(leftPart) != changedVariables.back().end()){
                            changedVariables.back()[leftPart] +=1;
                        }else changedVariables.back().insert(make_pair(leftPart, 1));
                    }
                    variableMap[leftPart].push_back(i);
                }
            } catch (invalid_argument const& exception){
                if (variableMap.find(rightPart) != variableMap.end()) {
                    if (!changedVariables.empty()) {
                        if (changedVariables.back().find(leftPart) != changedVariables.back().end()){
                            changedVariables.back()[leftPart] +=1;
                        }else changedVariables.back().insert(make_pair(leftPart, 1));
                    }
                    variableMap[leftPart].push_back(variableMap[rightPart].back());
                    cout << variableMap[leftPart].back() << endl;
                }else if (variableMap.find(leftPart) != variableMap.end()){
                    variableMap[leftPart].push_back(0);
                    if (!changedVariables.empty()) {
                        if (changedVariables.back().find(leftPart) != changedVariables.back().end()){
                            changedVariables.back()[leftPart] +=1;
                        }else changedVariables.back().insert(make_pair(leftPart, 1));
                    }
                    cout << 0 << endl;
                } else cout << 0 << endl;
            }
        }
    }
    return 0;
}
