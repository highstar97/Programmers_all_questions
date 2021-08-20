#include <iostream>
#include <string>
#include <vector>
#include <sstream>

std::vector<int> solution(std::vector<std::string> info, std::vector<std::string> query) {
    std::vector<int> answer;

    // query 스플릿
    for(auto data : query){
        int count = 0;
        std::istringstream ss(data);
        std::string v0, v1, v2, v3, v4, a0, a1, a2;
        ss >> v0 >> a0 >> v1 >> a1 >> v2 >> a2 >> v3 >> v4;

        // info와 비교
        for(int i=0; i<info.size(); i++){
            if(v0 == "-" || info[i].find(v0) != std::string::npos)
                if(v1 == "-" || info[i].find(v1) != std::string::npos)
                    if(v2 == "-" || info[i].find(v2) != std::string::npos)
                        if(v3 == "-" || info[i].find(v3) != std::string::npos)
                            if(stoi(v4) <= stoi(info[i].substr(info[i].rfind(' ')+1)))
                                count++;
        }
        answer.emplace_back(count);
    }

    return answer;
}

int main(){
    std::vector<std::string> info = {"java backend junior pizza 150","python frontend senior chicken 210","python frontend senior chicken 150","cpp backend senior pizza 260","java backend junior chicken 80","python backend senior chicken 50"};
    std::vector<std::string> query = {"java and backend and junior and pizza 100","python and frontend and senior and chicken 200","cpp and - and senior and pizza 250","- and backend and senior and - 150","- and - and - and chicken 100","- and - and - and - 150"};
    for(auto data : solution(info,query))
        std::cout << data << " ";
}