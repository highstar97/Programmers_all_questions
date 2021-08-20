#include <iostream>
#include <string>

#include <vector>

            // ╩С го аб ©Л
int dx[4] = { -1, 1, 0, 0};
int dy[4] = {  0, 0,-1, 1};

int rx[4] = {};
int ry[4] = {};

int solution(std::vector<std::vector<int>> board) {
    int answer = 0;
    return answer;
}

int main(){
    std::vector<std::vector<int>> board = {{0, 0, 0, 1, 1},{0, 0, 0, 1, 0},{0, 1, 0, 1, 1},{1, 1, 0, 0, 1},{0, 0, 0, 0, 0}};
    std::cout << solution(board);
}