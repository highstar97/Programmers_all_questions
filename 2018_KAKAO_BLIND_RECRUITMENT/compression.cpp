#include <iostream>
#include <string>
#include <vector>
#include <map>

std::vector<int> solution(std::string msg) {
    int index = 27;
    std::vector<int> answer;
    std::map<std::string, int> dictionary;
    // 기본 알파벳 사전에 입력
    std::string str = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for(int i=1; i<=26; i++){
        std::string temp;
        temp += str[i-1];
        dictionary.emplace(temp,i);
    }
    // msg 읽으면서 사전 추가 및 answer 입력
    for(int i=0; i<msg.length(); i++){
        int len = msg.length() - i;
        // msg를 뒤에서부터 한글자씩 지웠을 때 사전에 있을 때까지 while문
        while(dictionary.find(msg.substr(i,len)) == dictionary.end()){
            len--;
        }
        // 현재 글자 w 를 answer에 출력 && w + 다음글자 c 를 사전에 등록
        answer.emplace_back(dictionary[msg.substr(i,len)]);
        dictionary.emplace(msg.substr(i,len+1),index);
        index++;
        i += len-1;
    }

    return answer;
}

int main(){
    std::string msg = "KAKAO";
    for(auto data : solution(msg))
        std::cout << data << ", ";
}