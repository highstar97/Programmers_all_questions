#include <iostream>
#include <string>
#include <vector>

std::string solution(std::string m, std::vector<std::string> musicinfos) {
    std::pair<std::string,int> answer = std::make_pair("(None)",0);
    std::vector<int> time;
    // 라디오에서 재생 시간 저장
    for(auto data : musicinfos){
        int hours = stoi(data.substr(6,2)) - stoi(data.substr(0,2));
        int minutes = stoi(data.substr(9,2)) - stoi(data.substr(3,2));
        if(minutes < 0){
            hours--;
            minutes += 60;
        }
        time.emplace_back(hours*60+minutes);
    }
    // 문자열 m # 제거
    for(int i=1; i<m.length(); i++){
        if(m[i] == '#'){
            m.erase(i,1);
            m[i-1] = tolower(m[i-1]);
            i--;
        }
    }
    for(int i=0; i<musicinfos.size(); i++){
        for(int j=12; j<musicinfos[i].length(); j++){
            if(musicinfos[i][j] == '#'){
                musicinfos[i].erase(j,1);
                musicinfos[i][j-1] = tolower(musicinfos[i][j-1]);
                j--;
            }
        }
    }
    // 멜로디 정보 추출
    for(int i=0; i<musicinfos.size(); i++){
        std::string melody = musicinfos[i].substr(musicinfos[i].find(',',12)+1);
        std::string full_song = "";
        for(int j=0; j < time[i]/melody.length(); j++){
            full_song += melody;
        }
        for(int j=0; j < time[i]%melody.length(); j++){
            full_song += melody[j];
        }
        if(full_song.find(m) < full_song.length()){
            if(answer.second < time[i]){
                answer.first = musicinfos[i].substr(musicinfos[i].find(',',10)+1,musicinfos[i].find(',',12)-musicinfos[i].find(',',10)-1);
                answer.second = time[i];
            }
        }       
    }
    return answer.first;
}

int main(){
    std::string m = "ABC";
    std::vector<std::string> musicinfos = {"12:00,12:14,HELLO,C#DEFGAB", "13:00,13:05,WORLD,ABCDEF"};
    std::cout << solution(m, musicinfos);
}