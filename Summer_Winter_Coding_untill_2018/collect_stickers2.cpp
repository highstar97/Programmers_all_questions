#include <iostream>
#include <vector>

int solution(std::vector<int> sticker){
    int len = sticker.size();
    int a, b;
    std::vector<int> sum(len,0);
    if(len == 1)
        return sticker[0];
    else{
        // sticker[0] 포함
        a = sticker[0];
        for (int i = 2; i < len - 1; i++){
            if (i == 2)
                sum[i] = sticker[i];
            else if (i == 3)
                sum[i] = std::max(sticker[i], sum[i - 1]);
            else
                sum[i] = std::max(sum[i - 2] + sticker[i], sum[i - 1]);
        }
        a += std::max(sum[len - 3], sum[len - 2]);
        // sticker[0] 불포함
        b = 0;
        for (int i = 1; i < len; i++){
            if (i == 1)
                sum[i] = sticker[i];
            else if (i == 2)
                sum[i] = std::max(sticker[i], sum[i - 1]);
            else
                sum[i] = std::max(sum[i - 2] + sticker[i], sum[i - 1]);
        }
        b += std::max(sum[len - 2], sum[len - 1]);
        return std::max(a, b);
    }
}

int main(){
    std::vector<int> sticker = {14, 17, 2};
    std::cout << solution(sticker);
}