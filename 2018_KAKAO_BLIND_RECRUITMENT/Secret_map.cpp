#include <iostream>
#include <string>
#include <vector>
#include <bitset>

std::vector<std::string> solution(int n, std::vector<int> arr1, std::vector<int> arr2) {
    std::vector<std::string> answer;
    std::bitset<16> a , b;
    for(int i=0; i<arr1.size(); i++){
        a = arr1[i];
        b = arr2[i];

        std::string temp;
        for(int j=n-1; j>=0; j--){
            int k = a[j]|b[j];
            if(k==1)
                temp += "#";
            else
                temp += " ";
        }
        answer.emplace_back(temp);
    }
    return answer;
}

int main(){
    int n = 5;
    std::vector<int> arr1 = {9,20,28,18,11};
    std::vector<int> arr2 = {30,1,21,1,28};
    std::vector<std::string> answer = solution(n,arr1,arr2);
    for(auto data : answer)
        std::cout << data << std::endl;
}