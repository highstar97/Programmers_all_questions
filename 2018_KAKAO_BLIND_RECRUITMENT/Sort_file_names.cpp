#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

bool cmp(std::string str1, std::string str2){
    int Head_index1 = 0, Head_index2 = 0;
    while(isdigit(str1[Head_index1]) == false){
        Head_index1++;
    }
    while(isdigit(str2[Head_index2]) == false){
        Head_index2++;
    }
    std::string Head1 = str1.substr(0,Head_index1);
    std::string Head2 = str2.substr(0,Head_index2);
    transform(Head1.begin(), Head1.end(), Head1.begin(), tolower);
    transform(Head2.begin(), Head2.end(), Head2.begin(), tolower);
    if(Head1 > Head2)
        return false;
    else if(Head1 < Head2)
        return true;
    else{
        int Number_index1 = Head_index1, Number_index2 = Head_index2;
        while(isdigit(str1[Number_index1]) == true){
            Number_index1++;
        }
        while(isdigit(str2[Number_index2]) == true){
            Number_index2++;
        }
        std::string Number1 = str1.substr(Head_index1,Number_index1-Head_index1);
        std::string Number2 = str2.substr(Head_index2,Number_index2-Head_index2);
        // Number1이 뒤에 있는 숫자 , Number2가 앞에 있는 숫자 (sort 함수 내부 문제인듯)
        if(stoi(Number1) > stoi(Number2))
            return false;
        else if(stoi(Number1) < stoi(Number2))
            return true;
        else
            return false;
    }
}

std::vector<std::string> solution(std::vector<std::string> files) {
    std::stable_sort(files.begin(), files.end(), cmp);
    return files;
}

int main(){
    std::vector<std::string> files = {"img12.png", "img10.png", "img02.png", "img1.png", "IMG01.GIF", "img2.JPG"};
    for(auto data : solution(files))
        std::cout << data << std::endl;
}