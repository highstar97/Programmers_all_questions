#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    // Matrix ����
    vector<vector<int>> matrix(rows,vector<int>(columns,0));
    for(int i=1; i<=rows; i++){
        for(int j=1; j<=columns; j++){
            matrix[i-1][j-1] = (i-1)*columns + j;
        }
    }

    // ȸ��
    for(int i=0; i<queries.size(); i++){
        int x1 = queries[i][0], y1 = queries[i][1], x2 = queries[i][2], y2 = queries[i][3];
        
        // num�� ������ ���ڵ� ����
        vector<int> num;    
        // ������ -> �Ʒ�
        int x = x1, y = y1, temp;
        for(; x<x2; x++){
            for(; y<y2; y++){
                num.emplace_back(matrix[x-1][y-1]);
            }
            num.emplace_back(matrix[x-1][y-1]);
        }
        // ���� -> ��
        x = x2; y = y2;
        for(; x> x1; x--){
            for(; y> y1; y--){
                num.emplace_back(matrix[x-1][y-1]);
            }
            num.emplace_back(matrix[x-1][y-1]);
        }

        // num�� �ִ� ����� �ٲپ� ����
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

        // num�� ����� ���� �� ���� ���� �� ã��
        sort(num.begin(),num.end());
        answer.emplace_back(num[0]);
    }

    return answer;
}

int main(){
    for(auto data : solution(6,6,{{2,2,5,4},{3,3,6,6},{5,1,6,3}}))
        cout << data << " ";
}