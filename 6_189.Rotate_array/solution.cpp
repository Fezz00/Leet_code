#include <iostream>
#include <vector>

class Solution {
public:
    void rotate(std::vector<int>& nums, int k) {
        std::vector<int> temp = nums;
        int size = nums.size();
        int index = 0;
        for(int i=0; i<size; i++){
            index = (i+k)%size;
            temp[index] = nums[i];
        }
        nums = temp;
    }
};

int main() {
    Solution solution;
    std::vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;

    solution.rotate(nums, k);

    for (int num : nums) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}