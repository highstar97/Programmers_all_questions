#include <iostream>
#include <string>
#include <vector>

class Tree{
    int ID;
    int x, y;
public:
    void emplace(std::vector<std::vector<int>> v);
    void preorder();
    void postorder();
};

void Tree::emplace(std::vector<std::vector<int>> v){
    
}

std::vector<std::vector<int>> solution(std::vector<std::vector<int>> nodeinfo) {
    std::vector<std::vector<int>> answer;
    Tree tree;
    tree.emplace(nodeinfo);
    return answer;
}

int main(){
    std::vector<std::vector<int>> nodeinfo = {{5,3},{11,5},{13,3},{3,5},{6,1},{1,3},{8,6},{7,2},{2,2}};
    for(auto data : solution(nodeinfo)){
        for(auto d : data){
            std::cout << d << " ";
        }
        std::cout << std::endl;
    }
}