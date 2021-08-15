#include <iostream>
#include <string>
#include <vector>

using namespace std;

int score(int win){
    switch(win){
        case 2:
            return 5;
        case 3:
            return 4;
        case 4 :
            return 3;
        case 5:
            return 2;
        case 6:
            return 1;
        default:
            return 6;
    }
}

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    int zero = 0;
    int win = 0;
    vector<int> answer;
    
    for(int i=0; i<lottos.size(); i++){
        if(lottos[i] == 0)
            zero++;
        else{
            for(int j=0; j<win_nums.size(); j++){
                if(lottos[i] == win_nums[j])
                    win++;
            }
        }
    }

    answer.emplace_back(score(win+zero));
    answer.emplace_back(score(win));

    return answer;
}

int main(){
    for(auto data : solution({44,1,0,0,31,25},{31,10,1,6,19}))
        cout << data << " ";
    cout << endl;
    for(auto data : solution({0, 0, 0, 0, 0, 0},{38, 19, 20, 40, 15, 25}))
        cout << data << " ";
    cout << endl;
    for(auto data : solution({45, 4, 35, 20, 3, 9},{20, 9, 3, 45, 4, 35}))
        cout << data << " ";
    cout << endl;
}