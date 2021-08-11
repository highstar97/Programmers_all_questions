#include <iostream>
#include <vector>
#include <algorithm>

int solution(std::vector<int> d, int budget) {
    int answer = 0;
    int sum = 0;
    sort(d.begin(),d.end());
    for(auto data : d){
        sum += data;
        answer++;
        if(sum > budget){
            answer--;
            break;
        }
    }
    return answer;
}

int main(){
    std::vector<int> d = {1,3,2,5,4};
    int budget = 9;
    std::cout << solution(d,budget);
}