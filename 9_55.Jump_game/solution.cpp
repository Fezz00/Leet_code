#include <iostream>
#include <vector>

class Solution {
public:
    bool canJump(std::vector<int>& nums) {    
    int reach = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (i > reach) return false;
        reach = std::max(reach, i + nums[i]);
        if (reach >= (int)nums.size() - 1) return true;
    }
    return true;
    }
};

int main(){
    class Solution solution;
    std::vector<int> nums = {1,1,2,2,0,1,1};
    std::cout << solution.canJump(nums) << std::endl;

    return 0;
}