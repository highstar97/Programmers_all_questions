#include <iostream>
#include <string>
#include <vector>

std::string Num_Change(int n, int num){
    std::string answer;
    while(num/n >= 1){
        if(static_cast<int>(num)%n < 10){
            std::string temp = std::to_string(static_cast<int>(num)%n);
            answer = temp + answer;
        }
        else{
            switch(static_cast<int>(num)%n){
                case 10:{
                    answer = "A" + answer;
                    break;
                }
                case 11:{
                    answer = "B" + answer;
                    break;
                }
                case 12:{
                    answer = "C" + answer;
                    break;
                }
                case 13:{
                    answer = "D" + answer;
                    break;
                }
                case 14:{
                    answer = "E" + answer;
                    break;
                }
                case 15:{
                    answer = "F" + answer;
                    break;
                }
                default:{
                    answer = "Error" + answer;
                    break;
                }
            }
        }
        num /= n;
    }
    if(static_cast<int>(num)%n < 10){
        std::string temp = std::to_string(static_cast<int>(num)%n);
        answer = temp + answer;
    }
    else{
        switch(static_cast<int>(num)%n){
                case 10:{
                    answer = "A" + answer;
                    break;
                }
                case 11:{
                    answer = "B" + answer;
                    break;
                }
                case 12:{
                    answer = "C" + answer;
                    break;
                }
                case 13:{
                    answer = "D" + answer;
                    break;
                }
                case 14:{
                    answer = "E" + answer;
                    break;
                }
                case 15:{
                    answer = "F" + answer;
                    break;
                }
                default:{
                    answer = "Error" + answer;
                    break;
                }
            }
    } 
    return answer;
}

// 진법 n, 미리 구할 숫자의 갯수 t, 게임에 참가하는 인원 m, 튜브의 순서 p
std::string solution(int n, int t, int m, int p) {
    int count = 0;
    std::string answer = "";

    for(int num = 0;    ; num++){
        std::string str_num = Num_Change(n,num);
        for(int i=0; i<str_num.length(); i++){
            if(count%m+1 == p){
                answer += str_num[i];
                if(--t == 0)
                    return answer;
            }
            count++;
        }
    }
    return answer;
}

int main(){
    int n = 16, t = 16, m = 2, p = 2;
    std::cout << solution(n,t,m,p);
}