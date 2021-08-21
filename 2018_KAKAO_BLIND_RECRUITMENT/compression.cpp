#include <iostream>
#include <string>
#include <vector>
#include <map>

std::vector<int> solution(std::string msg) {
    int index = 27;
    std::vector<int> answer;
    std::map<std::string, int> dictionary;
    // �⺻ ���ĺ� ������ �Է�
    std::string str = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for(int i=1; i<=26; i++){
        std::string temp;
        temp += str[i-1];
        dictionary.emplace(temp,i);
    }
    // msg �����鼭 ���� �߰� �� answer �Է�
    for(int i=0; i<msg.length(); i++){
        int len = msg.length() - i;
        // msg�� �ڿ������� �ѱ��ھ� ������ �� ������ ���� ������ while��
        while(dictionary.find(msg.substr(i,len)) == dictionary.end()){
            len--;
        }
        // ���� ���� w �� answer�� ��� && w + �������� c �� ������ ���
        answer.emplace_back(dictionary[msg.substr(i,len)]);
        dictionary.emplace(msg.substr(i,len+1),index);
        index++;
        i += len-1;
    }

    return answer;
}

int main(){
    std::string msg = "KAKAO";
    for(auto data : solution(msg))
        std::cout << data << ", ";
}