#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int giveParent(vector<string> enroll, vector<string> referral, unordered_map<string, int>& result , string name, int money){
    string parent;
    for(int i=0; i<enroll.size(); i++){
        if(enroll[i] == name){
            if(referral[i] == "-")
                parent = "center";
            else
                parent = referral[i];
        }
    }
    if(parent == "center"){
        result[parent] += money;
    }
    else{
        int left = 0.1 * money;
        result[parent] += money - left;
        giveParent(enroll, referral, result, parent, left);
    }
}

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    // result(이름, 수익금)
    unordered_map<string, int> result;
    result.emplace("center",0);
    for(int i=0; i<enroll.size(); i++){
        result.emplace(enroll[i],0);
    }

    // 정산
    for(int i=0; i<seller.size(); i++){
        string name = seller[i];
        int left = (amount[i] * 100)*0.1;
        result[name] +=amount[i]*100 - left;
        giveParent(enroll, referral, result, name, left);       // 추천인에게 10% 상납
    }

    vector<int> answer;
    for(int i=0; i<enroll.size(); i++){
        answer.emplace_back(result[enroll[i]]);
    }
    return answer;
}

int main(){
    vector<string>   enroll = {"john", "mary", "edward", "sam", "emily", "jaimie", "tod", "young"};
    vector<string> referral = {"-", "-", "mary", "edward", "mary", "mary", "jaimie", "edward"};
    vector<string> seller = {"young", "john", "tod", "emily", "mary"};
    vector<int> amount = {12, 4, 2, 5, 10};
    for(auto data : solution(enroll,referral,seller,amount))
        cout << data << " ";
    cout << endl;
    for(auto data : solution({"john", "mary", "edward", "sam", "emily", "jaimie", "tod", "young"},{"-", "-", "mary", "edward", "mary", "mary", "jaimie", "edward"},{"sam", "emily", "jaimie", "edward"},{2,3,5,4}))
        cout << data << " ";
}