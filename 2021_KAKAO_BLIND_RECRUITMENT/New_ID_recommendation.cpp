#include <iostream>
#include <string>
#include <vector>

std::string solution(std::string new_id) {
    std::string answer = "";

    for(auto& data : new_id)
        data = tolower(data);

    for(int i=0; i<new_id.length(); i++){
        if(isalpha(new_id[i]) || isdigit(new_id[i]) || new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.');
        else{
            new_id.erase(i,1);
            i--;
        }
    }

    for(int i=0; i<new_id.length()-1; i++){
        if(new_id[i] == '.' && new_id[i+1] == '.'){
            new_id.erase(i+1,1);
            i--;
        }
    }

    if(new_id[0] == '.')
        new_id.erase(0,1);
    if(new_id[new_id.length()-1] == '.')
        new_id.erase(new_id.length()-1,1);

    if(new_id.length() == 0)
        new_id += "a";

    if(new_id.length() > 15){
        new_id.erase(15);
        if(new_id[new_id.length()-1] == '.')
            new_id.erase(new_id.length()-1);
    }

    while(new_id.length()<3)
        new_id += new_id[new_id.length()-1];

    answer = new_id;
    return answer;
}

int main(){
    std::string new_id = "...!@BaT#*..y.abcdefghijklm";
    std::cout << solution(new_id);
}