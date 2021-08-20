#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

bool cmp(std::pair<double,int> v1, std::pair<double,int> v2){
    if(v1.first > v2.first){
        return true;
    }
    else return false;
}

std::vector<int> solution(int N, std::vector<int> stages) {
    std::map<int,int> map;
    std::vector<std::pair<double,int>> failure_rate;
    std::vector<int> answer;

    // 스테이지별 유저 수 입력
    for(auto data : stages){
        if(map.find(data) == map.end())
            map.emplace(data,1);
        else
            map[data]++;
    }

    // 실패율 계산
    int person = stages.size();
    for(int i=1; i<=N; i++){
        failure_rate.emplace_back(std::make_pair(static_cast<double>(map[i])/person,i));
        person -= map[i];
    }

    stable_sort(failure_rate.begin(),failure_rate.end(),cmp);

    for(auto data : failure_rate)
        answer.emplace_back(data.second);
    
    return answer;
}

int main(){
    int N = 5;
    std::vector<int> stages = {2, 1, 2, 6, 2, 4, 3, 3};
    for(auto data : solution(N, stages))
        std::cout << data << " ";
}