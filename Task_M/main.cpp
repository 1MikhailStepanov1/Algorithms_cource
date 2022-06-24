#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
#include <unordered_map>

struct Point{
    short x;
    short y;
    short weight;

    bool operator==(const Point& item) const{
        return item.x == x && item.y == y;
    }

    bool operator!=(const Point& item) const{
        return item.x != x || item.y != y;
    }
};

namespace std{
    template <> struct hash<Point> {
        std::size_t operator()(const Point& id) const noexcept {
            return std::hash<int>()(id.x ^ (id.y << 16));
        }
    };
}
using namespace std;
std::vector<std::vector<Point>> graph;
short n, m;



bool inBounds(short inX, short inY){
    return (0 <= inX) && (inX < n) && (0 <= inY) && (inY < m);
}

std::vector<Point> neighbours(Point point){
    std::vector<Point> result = {};
    int tempX = point.x;
    short tempY = point.y;
    if (inBounds(tempX-1, tempY) && graph[tempX-1][tempY].weight != -1){
        result.push_back(graph[tempX-1][tempY]);
    }
    if (inBounds(tempX, tempY-1) && graph[point.x][tempY-1].weight != -1){
        result.push_back(graph[point.x][tempY-1]);
    }
    if (inBounds(tempX+1, tempY) && graph[tempX+1][tempY].weight != -1){
        result.push_back(graph[tempX+1][tempY]);
    }
    if (inBounds(tempX, tempY+1) && graph[tempX][tempY+1].weight != -1){
        result.push_back(graph[tempX][tempY+1]);
    }
    return result;
}



short charToWeight(char input){
    switch (input){
        case '.':
            return 1;
        case 'W':
            return 2;
        case '#':
            return -1;
        default:
            return 0;
    }
}

typedef std::pair<short, Point> elWithPrior;

struct customComparator{
    bool operator()(elWithPrior p1, elWithPrior p2){
        return p1.first > p2.first;
    }
};

struct PriorityQueue{
    std::priority_queue<elWithPrior, std::vector<elWithPrior>, customComparator> elements;

    inline bool empty(){
        return elements.empty();
    }

    inline void put(short prior, Point item){
        elements.emplace(prior, item);
    }

    Point get(){
        Point item = elements.top().second;
        elements.pop();
        return item;
    }
};

std::pair<short, std::vector<Point>> path(Point start, Point end, std::unordered_map<Point, Point> cameFrom){
    short result = 0;
    std::vector<Point> path;
    Point current = end;
    path.push_back(end);
    while (current != start){
        if (cameFrom.count(current) == 0)
            return std::pair<int, std::vector<Point>>{-1, std::vector<Point>{}};
        current = cameFrom[current];
        result += current.weight;
        path.push_back(current);
    }
    std::reverse(path.begin(), path.end());
    return std::make_pair(result, path);
}

void coorToOut(Point prev, Point cur){
    if (prev.x - cur.x < 0){
        std::cout << "S";
    } else if (prev.x - cur.x > 0){
        std::cout << "N";
    }
    if (prev.y - cur.y < 0){
        std::cout << "E";
    } else if (prev.y - cur.y > 0){
        std::cout << "W";
    }
}

int main() {
    //Ввод данных
    short x1, y1, x2, y2;
    std::cin >> n >> m >> x1 >> y1 >> x2 >> y2;


    for (short i = 0; i < n; i++){
        std::vector<Point> tempVec = {};
        for (short j = 0; j < m; j++){
            char temp;
            std::cin >> temp;
            tempVec.push_back({i,j, charToWeight(temp)});
        }
        graph.push_back(tempVec);
    }
    Point goal = graph[x2 - 1][y2 - 1];

    //Тело программы
    PriorityQueue startPoint;
    startPoint.put(0,graph[x1-1][y1-1]);
    std::unordered_map<Point, Point> cameFrom;
    std::unordered_map<Point, short> costSoFar;
    cameFrom[graph[x1-1][y1-1]] = graph[x1-1][y1-1];
    costSoFar[graph[x1-1][y1-1]] = 0;

    while (!startPoint.empty()){
        auto cur = startPoint.get();

        if (cur == goal){
            break;
        }
        std::vector<Point> temp = neighbours(cur);
        for (auto next : temp){
            short newCost = costSoFar[cur] + next.weight;
            if (!costSoFar.count(next) || newCost < costSoFar[next]){
                costSoFar[next] = newCost;
                cameFrom[next] = cur;
                startPoint.put(newCost, next);
            }
        }
    }
    std::pair<short, std::vector<Point>> answer = path(graph[x1-1][y1-1], goal, cameFrom);

    //Вывод программы

    std::cout << answer.first << std::endl;
    if (answer.first != -1){
        for (short i = 0; i < answer.second.size(); i++) {
            if (i != 0) {
                coorToOut(answer.second[i - 1], answer.second[i]);
            }
        }
    }
    return 0;
}
