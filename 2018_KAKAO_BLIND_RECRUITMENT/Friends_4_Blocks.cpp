#include <iostream>
#include <string>
#include <vector>

void move_down(int m, int n, std::vector<std::string>& board){
    for(int i=m-2; i>=0; i--){
        for(int j=n-1; j>=0; j--){
            if(board[i][j] != ' ' && board[i+1][j] == ' '){
                int a = i+1;
                for(; a < m; a++)
                    if(board[a][j] != ' ')
                        break;
                board[a-1][j] = board[i][j];
                board[i][j] = ' ';
            }
        }
    }
}

bool erase_block(int m, int n, std::vector<std::string>& board){
    std::vector<std::pair<int,int>> erase_number;
    // 삭제할 블록 탐색
    for(int i=0; i<m-1; i++){
        for(int j=0; j<n-1; j++){
            bool isSame = true;
            char key = board[i][j];
            if(key == ' ') isSame = false;
            if(board[i][j+1] != key) isSame = false;
            if(board[i+1][j] != key) isSame = false;
            if(board[i+1][j+1] != key) isSame = false;
            if(isSame)
                erase_number.emplace_back(i,j);
        }
    }
    // 블록 삭제
    for(auto data : erase_number){
        board[data.first][data.second] = ' ';
        board[data.first][data.second+1] = ' ';
        board[data.first+1][data.second] = ' ';
        board[data.first+1][data.second+1] = ' ';
    }

    if(erase_number.size() == 0)
        return false;
    return true;
}

int solution(int m, int n, std::vector<std::string> board) {
    while(erase_block(m,n,board)){
        move_down(m,n,board);
    }

    // answer 구하기
    int answer = 0;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(board[i][j] == ' ')
                answer++;
        }
    }
    return answer;
}

int main(){
    int m = 4, n = 5;
    std::vector<std::string> board = {"CCBDE", "AAADE", "AAABF", "CCBBF"};
    std::cout << solution(m,n,board);
}