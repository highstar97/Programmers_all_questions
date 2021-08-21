#include <iostream>
#include <string>
#include <set>

int solution(std::string str1, std::string str2) {
    double answer = 0;
    std::string temp;
    std::multiset<std::string> s1, s2, s3;
    // s1, s2 에 각각 문자열 잘라서 넣기
    for(int i=0; i<str1.length()-1; i++){
        bool signal = false;
        if('a' <=  str1[i] && str1[i] <= 'z' ){
            temp += str1[i];
        }
        else if('A' <=  str1[i] && str1[i] <= 'Z' ){
            temp += tolower(str1[i]);
        }
        else{
            signal = true;
        }

        if('a' <=  str1[i+1] && str1[i+1] <= 'z' ){
            temp += str1[i+1];
        }
        else if('A' <=  str1[i+1] && str1[i+1] <= 'Z' ){
            temp += tolower(str1[i+1]);
        }
        else{
            signal = true;
        }
        if(signal == false)
            s1.emplace(temp);
        temp.clear();
    }

    for(int i=0; i<str2.length()-1; i++){
        bool signal = false;
        if('a' <=  str2[i] && str2[i] <= 'z' ){
            temp += str2[i];
        }
        else if('A' <=  str2[i] && str2[i] <= 'Z' ){
            temp += tolower(str2[i]);
        }
        else{
            signal = true;
        }

        if('a' <=  str2[i+1] && str2[i+1] <= 'z' ){
            temp += str2[i+1];
        }
        else if('A' <=  str2[i+1] && str2[i+1] <= 'Z' ){
            temp += tolower(str2[i+1]);
        }
        else{
            signal = true;
        }
        if(signal == false)
            s2.emplace(temp);
        temp.clear();
    }

    // s1, s2 겹치는 거 찾기
    int count = 0;
    for(auto data : s1){
        std::multiset<std::string>::iterator it = s2.find(data);
        if(it != s2.end()){
            count++;
            s2.erase(it);
        }
    }

    // s1과 중복된 s2 제외한 나머지를s3 넣기
    for(auto data : s1)
        s3.emplace(data);
    for(auto data : s2)
        s3.emplace(data);
        
    // s1, s2 둘 다 공집합인 경우
    if(s3.size() == 0)
        return 65536;

    answer = static_cast<double>(count)/s3.size()*65536;
    return answer;
}

int main(){
    std::string str1 = "E=M*C^2";
    std::string str2 = "e=m*c^2";
    std::cout << solution(str1, str2) << std::endl;
}