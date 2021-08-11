#include <iostream>
#include <vector>
#include <set>

std::vector<int> solution(int n, std::vector<std::string> words) {
    char c = words[0].back();   // 첫 단어 끝 문자 c 저장
    std::set<std::string> set;
    set.emplace(words[0]);      // 첫 단어 추가

    for(int i=1; i<words.size(); i++){
        // 끝말잇기 실패
        if( c != words[i].front()){
            return std::vector<int> {(i%n)+1, (i/n)+1};
        }
        else    c = words[i].back();
        // 중복 단어
        if(set.find(words[i]) == set.end()){
            set.emplace(words[i]);
        }
        else{
            return std::vector<int> {(i%n)+1, (i/n)+1};
        }
    }
    // 탈락자가 없다.
    return std::vector<int> (2,0);
}

int main(){
    int n = 2;
    std::vector<std::string> words = {"hello", "one", "even", "never", "now", "world", "draw"};
    for(auto data : solution(n,words))
        std::cout << data << " ";
}