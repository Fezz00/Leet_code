#include <iostream>
#include <vector>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int size = prices.size();
        bool check = false;
        if(size <= 1)
            return 0;
        int result = 0;
        int min = prices[0];
        for(int i=0; i<size; i++){
            if(min >= prices[i]){
                min = prices[i];
                continue;
            }
            if(!check){
                result = prices[i] - min;
                check = true;
                continue;
            }
            if(result < prices[i] - min){
                result = prices[i] - min;
            }
        }
        return result;
    }
};

int main(){
    class Solution s;
    std::vector<int> prices = {7,1,5,3,6,4};
    std::cout << s.maxProfit(prices) << std::endl;
    return 0;
}