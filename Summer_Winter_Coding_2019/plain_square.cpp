#include <iostream>
#include <math.h>

long long solution(int w,int h) {
    long long answer = 0;
    for(int i=1; i<w; i++){
        answer += floor(h - static_cast<long double>(h)/w*i );
    }
    return 2*answer;
}

int main(){
    int w = 10000, h = 100;
    std::cout << solution(w,h);
}