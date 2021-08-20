#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>

std::vector<std::string> solution(std::vector<std::string> record) {
    std::unordered_map<std::string, std::string> map;
    std::queue<std::pair<std::string,std::string>> queue;
    std::vector<std::string> answer;
    // ���̵� & �г��� ����
    for(auto data : record){
        std::istringstream ss(data);
        std::string order;
        std::string ID;
        std::string nickname;

        ss >> order;
        ss >> ID;
        if(order == "Enter" || order == "Change"){
            ss >> nickname;
            if(map.find(ID) == map.end()){
                map.emplace(ID,nickname);
            }
            else
                map[ID] = nickname;
        }
        queue.emplace(std::make_pair(order,ID));
    }
    // queue ������� answer�� �ֱ�
    while(!queue.empty()){
        if(queue.front().first == "Enter"){
            answer.emplace_back(map[queue.front().second]+"���� ���Խ��ϴ�.");
        }
        else if(queue.front().first == "Leave")
            answer.emplace_back(map[queue.front().second]+"���� �������ϴ�.");
        queue.pop();
    }

    return answer;
}

int main(){
    std::vector<std::string> record = {"Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan"};
    for(auto data : solution(record))
        std::cout << data << " ";
}