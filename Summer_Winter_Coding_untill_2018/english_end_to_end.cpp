#include <iostream>
#include <vector>
#include <set>

std::vector<int> solution(int n, std::vector<std::string> words) {
    char c = words[0].back();   // ù �ܾ� �� ���� c ����
    std::set<std::string> set;
    set.emplace(words[0]);      // ù �ܾ� �߰�

    for(int i=1; i<words.size(); i++){
        // �����ձ� ����
        if( c != words[i].front()){
            return std::vector<int> {(i%n)+1, (i/n)+1};
        }
        else    c = words[i].back();
        // �ߺ� �ܾ�
        if(set.find(words[i]) == set.end()){
            set.emplace(words[i]);
        }
        else{
            return std::vector<int> {(i%n)+1, (i/n)+1};
        }
    }
    // Ż���ڰ� ����.
    return std::vector<int> (2,0);
}

int main(){
    int n = 2;
    std::vector<std::string> words = {"hello", "one", "even", "never", "now", "world", "draw"};
    for(auto data : solution(n,words))
        std::cout << data << " ";
}