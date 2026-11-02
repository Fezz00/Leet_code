#include <iostream>
#include <vector>

class Solution {
public:
    int majorityElement(std::vector<int>& nums) {
        std::vector<std::vector<int>> table(2);
        for (int x : nums) {
            bool found = false;
            for (int j = 0; j < table[0].size(); j++) {
                if (table[0][j] == x) {
                    table[1][j]++;
                    found = true;
                    break;
                }
            }
            if (!found) {
                table[0].push_back(x);
                table[1].push_back(1);
            }
        }

        for (int j = 0; j < table[0].size(); j++) {
            if (table[1][j] > nums.size() / 2)
                return table[0][j];
        }
        return -1;
    }
};


int main(){
    Solution solution;
    std::vector<int> nums = {3, 2, 3};
    int result = solution.majorityElement(nums);
    std::cout << "Majority element: " << result << std::endl;
    return 0;
}