#include <iostream>

int solution(int n, int answer = 0){
    int count = answer;
    if(n==0)        // Àç±Í Á¾·á Á¶°Ç
        return count;
    if(n%2 != 0){   // n = È¦¼ö
        n--;
        count++;
    }
    else{           // n = Â¦¼ö
        n /= 2;
    }
    return solution(n,count);
}

int main(){
    int n = 1e9;
    std::cout << solution(n);
}