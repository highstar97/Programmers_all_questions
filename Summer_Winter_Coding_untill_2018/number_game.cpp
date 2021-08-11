#include <iostream>
#include <vector>
#include <algorithm>

int solution(std::vector<int> A, std::vector<int> B) {
    int i=0,j=0;
    int answer = 0;
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    for(; i<A.size(); i++){
        for(j; j<B.size(); j++){
            if(A[i] < B[j]){
                j++;
                answer++;
                break;
            }
        }
    }
    return answer;
}

int main(){
    std::vector<int> A = {5,1,3,7};
    std::vector<int> B = {2,2,6,8};
    std::cout << solution(A,B);
}