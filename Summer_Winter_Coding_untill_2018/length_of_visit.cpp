#include <iostream>
#include <string>
#include <vector>
#include <set>

int solution(std::string dirs) {
    int answer = 0;
    std::vector<std::vector<std::set<std::string>>> matrix(11,std::vector<std::vector<std::string>>(11,std::set<std::string>()));
    int x = 5, y = 5;
    for(int i=0; i<dirs.length(); i++){
        if( dirs[i] == 'U' ){
            if( x-1 >= 0){
                x--;
                matrix[x][y].emplace("D");
            }
        }
        else if( dirs[i] == 'D' ){
            if( x+1 <= 11 ){
                x++;
                matrix[x][y].emplace("U");
            }
        }
        else if( dirs[i] == 'L' ){
            if( y-1 >= 0){
                y--;
                matrix[x][y].emplace("R");
            }
        }
        else if( dirs[i] == 'R' ){
            if( y+1 <= 11 ){
                y++;
                matrix[x][y].emplace("L");
            }
        }
    }

    for(auto data : matrix){
        for(auto data2 : data){
            answer = data2.size();
        }
    }
    return answer;
}

int main(){
    std::string dirs = "ULURRDLLU";
    std::cout << solution(dirs);
}