#include <iostream>
#include <string>
#include <vector>
#define INF 1e6

int solution(int n, int s, int a, int b, std::vector<std::vector<int>> fares) {
    int answer;
    // graph 정보 입력
    int graph[n+1][n+1];
    for(int i=0; i<n+1; i++)
        std::fill(graph[i],graph[i]+n+1,INF);
    
    for(int i=0; i<n+1; i++)
        for(int j=0; j<n+1; j++)
            if(i==j) graph[i][j] = 0;

    for(auto data : fares){
        graph[data[0]][data[1]] = data[2];
        graph[data[1]][data[0]] = data[2];
    }

    for(int i=0; i<n+1; i++)
        for(int j=0; j<n+1; j++)
            for(int k=0; k<n+1; k++)
                graph[j][k] = std::min(graph[j][k],graph[j][i]+graph[i][k]);

    answer = graph[s][a] + graph[s][b];
    for(int i=1; i<=n; i++){
        answer = std::min(answer,graph[s][i] + graph[i][a] + graph[i][b]);
    }
    return answer;
}

int main(){
    int n = 6, s = 4, a = 5, b = 6;
    std::vector<std::vector<int>> fares = {{2, 6, 6},{6, 3, 7},{4, 6, 7},{6, 5, 11},{2, 5, 12},{5, 3, 20},{2, 4, 8},{4, 3, 9}};
    std::cout << solution(n,s,a,b,fares);
}