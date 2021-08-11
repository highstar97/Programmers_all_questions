#include <iostream>
#include <string>
#include <vector>

int solution(std::string skill, std::vector<std::string> skill_trees) {
    int answer = skill_trees.size();
    for(auto data : skill_trees){
        std::vector<int> v;
        for(int i=0; i<skill.length(); i++){
            if(data.find(skill[i]) == std::string::npos)
                v.emplace_back(1e9);
            else
                v.emplace_back(data.find(skill[i]));
        }
        for(int i=1; i<v.size(); i++){
            if(v[i-1] > v[i]){
                answer--;
                break;
            }
        }
    }
    return answer;
}

int main(){
    std::string skill = "CBD";
    std::vector<std::string> skill_trees = {"BACDE", "CBADF", "AECB", "BDA"};
    std::cout << solution(skill, skill_trees);
}