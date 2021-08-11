#include <iostream>
#include <vector>
#include <queue>
#define INF 1e9

int solution(int N, std::vector<std::vector<int>> road, int K) {
    int answer = 0;
    std::vector<int> d(N+1,INF);    // 최단거리 정보
    std::vector<bool> visited(N+1,false);   // 방문 정보
    std::vector<std::pair<int,int>> graph[N+1]; // 그래프 정보
    // 그래프 정보 입력
    for(auto data : road){
        graph[data[0]].emplace_back(std::make_pair(data[1],data[2]));
        graph[data[1]].emplace_back(std::make_pair(data[0],data[2]));
    }
    // 다익스트라
    std::priority_queue<std::pair<int,int>,std::vector<std::pair<int,int>>, std::greater<std::pair<int,int>>> pq;
    pq.emplace(std::make_pair(0,1));    // 최소 힙 <거리, 노드>
    d[1] = 0;
    while(!pq.empty()){
        int dist = pq.top().first;
        int now = pq.top().second;
        pq.pop();
        if(d[now] < dist)
            continue;
        for(int i=0; i<graph[now].size(); i++){
            int cost = dist + graph[now][i].second;
            if(cost < d[graph[now][i].first]){
                d[graph[now][i].first] = cost;
                pq.push(std::make_pair(cost, graph[now][i].first));
            }
        }
    }
    for(auto data : d){
        if(data <= K)
            answer++;
    }
    return answer;
}

int main(){
    int N = 5, K = 3;
    std::vector<std::vector<int>> road = {{1,2,1},{2,3,3},{5,2,2},{1,4,2},{5,3,1},{5,4,2}};
    std::cout << solution(N,road,K);
}