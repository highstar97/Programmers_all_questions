#include <iostream>
#include <vector>

int solution(int n, std::vector<int> stations, int w){
    int len;
    int answer = 0;
    int can_reach = 2*w+1;
    for(int i=0; i<stations.size(); i++){
        if(i==0){
            len = stations[i] - w - 1;
            if(len > 0)
                answer += (len/can_reach + ((len%can_reach == 0) ? 0 : 1));
        }
        else{
            len = stations[i] - stations[i-1] - 2*w -1;
            if(len > 0)
                answer += (len/can_reach + ((len%can_reach == 0) ? 0 : 1));
        }
    }
    len = n - stations[stations.size()-1] - w;
    if(len > 0)
        answer += (len/can_reach + ((len%can_reach == 0) ? 0 : 1));
    return answer;
}

int main(){
    int n = 11;
    int w = 1;
    std::vector<int> station = {4,11};
    std::cout << solution(n,station,w);
}