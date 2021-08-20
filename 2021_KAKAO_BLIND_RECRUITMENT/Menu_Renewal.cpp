#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

std::vector<std::string> Combination(std::string order, int r){
    std::vector<std::string> result;
    std::string bitmask = "";
    std::vector<char> v;

    if(order.length() < r)
        return std::vector<std::string>();

    sort(order.begin(),order.end());

    for(int i=0; i<order.length(); i++)
        v.emplace_back(order[i]);

    for(int i=0; i<r; i++)
        bitmask += "1";
    bitmask.resize(order.length(),'0');

    do{
        std::string temp = "";
        for(int i=0; i<v.size(); i++)
            if(bitmask[i] == '1')
                temp += v[i];
        result.emplace_back(temp);
    }while(prev_permutation(bitmask.begin(),bitmask.end()));

    return result;
}

std::vector<std::string> solution(std::vector<std::string> orders, std::vector<int> course) {
    int Max_order = 0;
    std::vector<std::string> answer;

    for(auto r : course){
        std::map<std::string,int> map;
        // r 개수 만큼 Combination -> Count map에 저장
        for(int i=0; i<orders.size(); i++){
            for(auto data : Combination(orders[i],r)){
                if(map.find(data) == map.end())
                    map.emplace(data,1);
                else
                    map[data]++;
            }
        }
        for(auto data : map)
            std::cout << data.first << " " << data.second << std::endl;
        // map에서 가장 많은 조합 answer에 추가
        int count = 0;
        for(auto data : map)
            if(count < data.second)
                count = data.second;
        
        if(count >= 2){
            for(auto data : map)
                if(count == data.second)
                    answer.emplace_back(data.first);
        }
    }
    sort(answer.begin(),answer.end());

    return answer;
}

int main(){
    std::vector<std::string> orders = {"XYZ", "XWY", "WXA"};
    std::vector<int> course = {2,3,4};
    for(auto data : solution(orders,course))
        std::cout << data << " ";
}