#include <iostream>
#include <vector>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int profit = 0;
        for (int i = 1; i < prices.size(); i++)
            if (prices[i] > prices[i-1])
                profit += prices[i] - prices[i-1];
        return profit;
    }
};

int main(){
    // 2,1,2,0,1
    Solution s;
    std::vector<int> prices = {1,3,5,4,3,7,6,9,2,4};
    std::cout << s.maxProfit(prices) << std::endl;

    return 0;
}