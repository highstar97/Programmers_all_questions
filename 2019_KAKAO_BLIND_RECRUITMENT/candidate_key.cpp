#include <iostream>
#include <string>
#include <vector>
#include <set>

int solution(std::vector<std::vector<std::string>> relation) {
    int size = relation.size();
    int answer = 0;
    int arr[4] = {0,0,0,0};
    std::set<std::string> set; 
    // 단일로 후보키가 되는 경우
    for(int i=0; i<4; i++){
        set.clear();
        for(auto data : relation)
            set.emplace(data[i]);
        if(set.size() == size){
            arr[i] = 1;
            answer++;
        }
    }

    


    return answer;
}

int main(){
    std::vector<std::vector<std::string>> relation = {{"100","ryan","music","2"},{"200","apeach","math","2"},{"300","tube","computer","3"},{"400","con","computer","4"},{"500","muzi","music","3"},{"600","apeach","music","2"}};
    std::cout << solution(relation);
}