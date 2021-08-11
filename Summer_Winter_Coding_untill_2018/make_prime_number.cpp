#include <iostream>
#include <vector>
#include <math.h>

bool IsPrime(int n){
    // n은 3부터 시작
    if( n==3 )
        return true;
    // 6i+1 or 6i-1 형식이면 소수 가능성 있음
    if( n%6 == 1 || n%6 == 5 ){
        // 합성수인지 체크
        for(int i =2; i<=sqrt(n); i++)
            if( n%i == 0 )
                return false;
    }
    else    // 형식을 따르지 않으면 합성수
        return false;
    // 체크를 통과하면 소수
    return true;
}

int solution(std::vector<int> nums) {
    int answer = 0;
    for(int i=0; i<nums.size(); i++){
        for(int j=i; j<nums.size(); j++){
            for(int k=j; k<nums.size(); k++){
                if( i==j || i==k || j==k )
                    continue;
                else{
                    if( IsPrime(nums[i]+nums[j]+nums[k]) == true )
                        answer++;
                }    
            }
        }
    }

    return answer;
}

int main(){
    std::vector<int> nums = {1,2,7,6,4};
    std::cout << solution(nums) << std::endl;
}