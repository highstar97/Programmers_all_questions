#include <iostream>
#include <string>
#include <set>

struct location{
    int x,y;
    bool operator<(const location& l) const;
};

bool location::operator<(const location& l) const{
    if(x != l.x)
        return x < l.x;
    return y < l.y;
}

int solution(std::string dirs) {
    std::set<std::pair<location,location>> visited;

    int answer = 0;
    int nx = 0, ny = 0;
    for(int i=0; i<dirs.length(); i++){
        location l1, l2;
        l1.x = nx, l1.y = ny;
        switch(dirs[i]){
            case 'U':{
                l2.x = nx;
                l2.y = ny+1;
                if(l2.y <= 5){
                    if(visited.find(std::make_pair(l1,l2)) == visited.end() && visited.find(std::make_pair(l2,l1)) == visited.end()){
                        answer++;
                        visited.emplace(std::make_pair(l1,l2));
                        visited.emplace(std::make_pair(l2,l1));
                    }
                    ny++;
                }
                break;
            }
            case 'D':{
                l2.x = nx;
                l2.y = ny-1;
                if(l2.y >= -5){
                    if(visited.find(std::make_pair(l1,l2)) == visited.end() && visited.find(std::make_pair(l2,l1)) == visited.end()){
                        answer++;
                        visited.emplace(std::make_pair(l1,l2));
                        visited.emplace(std::make_pair(l2,l1));
                    }
                    ny--;
                }
                break;
            }
            case 'L':{
                l2.x = nx-1;
                l2.y = ny;
                if(l2.x >= -5){
                    if(visited.find(std::make_pair(l1,l2)) == visited.end() && visited.find(std::make_pair(l2,l1)) == visited.end()){
                        answer++;
                        visited.emplace(std::make_pair(l1,l2));
                        visited.emplace(std::make_pair(l2,l1));
                    }
                    nx--;
                }
                break;
            }
            case 'R':{
                l2.x = nx+1;
                l2.y = ny;
                if(l2.x <= 5){
                    if(visited.find(std::make_pair(l1,l2)) == visited.end() && visited.find(std::make_pair(l2,l1)) == visited.end()){
                        answer++;
                        visited.emplace(std::make_pair(l1,l2));
                        visited.emplace(std::make_pair(l2,l1));
                    }
                    nx++;
                }
                break;
            }
        }
    }
    return answer;
}

int main(){
    std::string dirs = "LULLLLLLU";
    std::cout << solution(dirs);
}