#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>  // transform

int solution(int cacheSize, std::vector<std::string> cities) {
    int answer = 0;
    std::map<std::string,int> cache;

    for(auto city : cities){
        std::transform(city.begin(), city.end(), city.begin(), ::toupper);
        // 캐쉬에 존재하지 않으면
        if(cache.find(city) == cache.end()){
            if(cache.size() < cacheSize){
                for(auto it = cache.begin(); it != cache.end(); it++){
                    it->second++;
                }
                cache.emplace(std::make_pair(city,0));
                answer += 5;
            }
            else{
                // 가장 큰 값을 찾아서 삭제
                int max = cache.begin()->second;
                std::string delete_city;
                for(auto data : cache){
                    if(max < data.second){
                        max = data.second;
                        delete_city = data.first;
                    }
                }
                cache.erase(delete_city);
                for(auto it = cache.begin(); it != cache.end(); it++){
                    it->second++;
                }
                cache.emplace(std::make_pair(city,0));
                answer += 5;
            }
        }
        // 캐쉬에 존재하면
        else{
            for(auto it = cache.begin(); it != cache.end(); it++){
                it->second++;
            }
            cache[city] = 0;
            answer += 1;
        }
    }
    return answer;
}

int main(){
    int cacheSize = 0;
    std::vector<std::string> cities = {"Jeju", "Pangyo", "NewYork", "newyork"};
    std::cout << solution(cacheSize,cities);
}