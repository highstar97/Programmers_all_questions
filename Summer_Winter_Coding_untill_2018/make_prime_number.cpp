#include <iostream>
#include <vector>
#include <math.h>

bool IsPrime(int n){
    // n�� 3���� ����
    if( n==3 )
        return true;
    // 6i+1 or 6i-1 �����̸� �Ҽ� ���ɼ� ����
    if( n%6 == 1 || n%6 == 5 ){
        // �ռ������� üũ
        for(int i =2; i<=sqrt(n); i++)
            if( n%i == 0 )
                return false;
    }
    else    // ������ ������ ������ �ռ���
        return false;
    // üũ�� ����ϸ� �Ҽ�
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