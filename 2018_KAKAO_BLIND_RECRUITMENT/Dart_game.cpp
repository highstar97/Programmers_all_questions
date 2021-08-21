#include <iostream>
#include <string>
#include <vector>
#include <math.h>

int solution(std::string dartResult) {
    int answer = 0;
    std::string temp;
    std::vector<int> exp;
    for(int i=0; i<dartResult.length(); i++){
        if(isdigit(dartResult[i]))
            temp += dartResult[i];
        else{
            switch(dartResult[i]){
                case 'S':{
                    exp.emplace_back(stoi(temp));
                    temp.clear();
                    break;
                }
                case 'D':{
                    exp.emplace_back(pow(stoi(temp),2));
                    temp.clear();
                    break;
                }
                case 'T':{
                    exp.emplace_back(pow(stoi(temp),3));
                    temp.clear();
                    break;
                }
                case '*':{
                    int index = exp.size()-1;
                    if(index == 0){
                        exp[index] *= 2;
                    }
                    else{
                        exp[index-1] *= 2;
                        exp[index] *= 2;
                    }
                    break;
                }
                case '#':{
                    exp[exp.size()-1] *= -1;
                    break;
                }
            }
        }
    }
    for(auto data : exp){
        answer += data;
    }
    return answer;
}

int main(){
    std::string dartResult = "1S*2T*3S";
    std::cout << solution(dartResult);
}