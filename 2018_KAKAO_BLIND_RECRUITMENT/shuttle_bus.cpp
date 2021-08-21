#include <iostream>
#include <string>
#include <vector>
#include <map>

struct time{
    int hour;
    int minute;
};

std::string solution(int n, int t, int m, std::vector<std::string> timetable) {
    std::map<time,int> map;
    time first_time;
    first_time.hour = 9;
    first_time.minute = 0;
    map.emplace(first_time,0);
}

int main(){
    int n = 1, t = 1, m = 5;
    std::vector<std::string> timetable = {"08:00", "08:01", "08:02", "08:03"};
    std::cout << solution(n,t,m,timetable);
}