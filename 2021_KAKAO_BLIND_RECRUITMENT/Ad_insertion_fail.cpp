#include <iostream>
#include <string>
#include <vector>

std::string solution(std::string play_time, std::string adv_time, std::vector<std::string> logs) {
    std::string answer = "";
    return answer;
}

int main(){
    std::string play_time = "02:03:55";
    std::string adv_time = "00:14:15";
    std::vector<std::string> logs = {"01:20:15-01:45:14", "00:40:31-01:00:00", "00:25:50-00:48:29", "01:30:59-01:53:29", "01:37:44-02:02:30"};
    std::cout << solution(play_time,adv_time, logs);
}