#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    // Matrix 구현
    vector<vector<int>> matrix(rows,vector<int>(columns,0));
    for(int i=1; i<=rows; i++){
        for(int j=1; j<=columns; j++){
            matrix[i-1][j-1] = (i-1)*columns + j;
        }
    }

    // 회전
    for(int i=0; i<queries.size(); i++){
        int x1 = queries[i][0], y1 = queries[i][1], x2 = queries[i][2], y2 = queries[i][3];
        
        // num에 움직일 숫자들 저장
        vector<int> num;    
        // 오른쪽 -> 아래
        int x = x1, y = y1, temp;
        for(; x<x2; x++){
            for(; y<y2; y++){
                num.emplace_back(matrix[x-1][y-1]);
            }
            num.emplace_back(matrix[x-1][y-1]);
        }
        // 왼쪽 -> 위
        x = x2; y = y2;
        for(; x> x1; x--){
            for(; y> y1; y--){
                num.emplace_back(matrix[x-1][y-1]);
            }
            num.emplace_back(matrix[x-1][y-1]);
        }

        // num에 있는 값들로 바꾸어 저장
        int count = 0;
        x = x1; y = y1+1;
        for(; x<x2; x++){
            for(; y<y2; y++){
                matrix[x-1][y-1] = num[count];
                count++;
            }
            matrix[x-1][y-1] = num[count];
            count++;
        }
        x = x2; y = y2;
        for(; x> x1; x--){
            for(; y> y1; y--){
                matrix[x-1][y-1] = num[count];
                count++;
            }
            matrix[x-1][y-1] = num[count];
            count++;
        }
        matrix[x1-1][y1-1] = num[count];

        // num에 저장된 값들 중 가장 작은 값 찾기
        sort(num.begin(),num.end());
        answer.emplace_back(num[0]);
    }

    return answer;
}

int main(){
    for(auto data : solution(6,6,{{2,2,5,4},{3,3,6,6},{5,1,6,3}}))
        cout << data << " ";
}