#include <iostream>

int solution(int n, int answer = 0){
    int count = answer;
    if(n==0)        // ��� ���� ����
        return count;
    if(n%2 != 0){   // n = Ȧ��
        n--;
        count++;
    }
    else{           // n = ¦��
        n /= 2;
    }
    return solution(n,count);
}

int main(){
    int n = 1e9;
    std::cout << solution(n);
}