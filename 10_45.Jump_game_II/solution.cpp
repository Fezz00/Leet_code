#include <iostream>
#include <vector>

class Solution {
public:
    int jump(std::vector<int>& nums) {
        int jumps = 0;
        int curEnd = 0;
        int farthest = 0;

        for (int i = 0; i < (int)nums.size() - 1; i++) {
            farthest = std::max(farthest, i + nums[i]);
            if (i == curEnd) {
                jumps++;
                curEnd = farthest;
            }
        }
        return jumps;
    }
};

int main(){
    class Solution solution;
    std::vector<int> nums = {2,3,1,1,4};
    std::cout << solution.jump(nums) << std::endl;

    return 0;
}