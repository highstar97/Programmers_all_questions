#include <iostream>
#include <string>
#include <vector>

class timer{
public:
    int Y, M, D, h, m, s, ms=0;
    std::string ps;  // processing time;
    timer(std::string str);
    void stot(std::string str);
    timer Find_Start_Time();
};
// Constructor
timer::timer(std::string str){
    stot(str);
}
// sting to timer
void timer::stot(std::string str){
    Y = stoi(str.substr(0,4));
    M = stoi(str.substr(5,2));
    D = stoi(str.substr(8,2));
    h = stoi(str.substr(11,2));
    m = stoi(str.substr(14,2));
    s = stoi(str.substr(17,2));
    ms = stoi(str.substr(20,3));
    if(str[23] == ',')
        ps = str.substr(24);
}
// Find Start Time
timer timer::Find_Start_Time(){
    int _s = stoi(ps.substr(0,1));
    int _ms = stod(ps.substr(2,ps.length()-3));
    // 빼기
    s -= _s;
    ms -= _ms;
    ms += 1;        // 양 끝 시간 포함으로 인한 0.001초 추가
    // 음수가 있으면 양수로 변경
    if(ms < 0){
        s--;
        ms += 1000;
        if(s < 0){
            m--;
            s += 60;
            if(m < 0){
                h--;
                m += 60;
                if(h < 0){
                    D--;
                    h += 24;
                    if(D < 0){
                        M--;
                        D += 30;        // 9월은 30일
                        if(M < 0){
                            Y--;
                            M += 12;
                        }
                    }
                }
            }
        }
    }
    return *this;
}

bool cmp(timer a, timer b){
    if(a.Y > b.Y)
        return true;
    else if(a.Y < b.Y)
        return false;
    else{
        if(a.M > b.Y)
            return true;
        else if(a.M < b.M)
            return false;
        else{
            if(a.D > b.D)
                return true;
            else if(a.D < b.D)
                return true;
            else{
                if(a.h > b.h)
                    return true;
                else if(a.h < b.h)
                    return false;
                else{
                    if(a.m > b.m)
                        return true;
                    else if(a.m < b.m)
                        return false;
                    else{
                        if(a.s > b.s)
                            return true;
                        else if(a.s < b.s)
                            return false;
                        else{
                            if(a.ms > b.ms)
                                return true;
                            else if(a.ms < b.ms)
                                return false;
                            else return true;
                        }
                    }
                }
            }
        }
    }
}

int solution(std::vector<std::string> lines){
    std::vector<timer> Start_Time;
    std::vector<timer> End_Time;
    for(std::string data : lines){
        timer temp(data);
        Start_Time.emplace_back(temp.Find_Start_Time());
        End_Time.emplace_back(temp);
    }
    std::vector<int> count;
    for(int i=0; i<Start_Time.size(); i++){
        int c = 0;
        int a = Start_Time[i].s;
        int b = a+1;
        for(int j=0; j<Start_Time.size(); j++){
            if( End_Time[j].s < a || b < Start_Time[j].s ){}
            else
                c++;
        }
        std::cout << c << " ";
    }
    for(int i=0; i<End_Time.size(); i++){

    }

}

int main(){
    std::vector<std::string> lines = { "2016-09-15 01:00:04.002 2.0s","2016-09-15 01:00:07.000 2s"};
    std::cout << solution(lines);
}