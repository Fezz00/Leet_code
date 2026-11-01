#include <iostream>
#include <vector>

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        for(int i=0; i < nums.size() - 1; i++){
            if(nums[i] == nums[i+1]){
                nums.erase(nums.begin() + i);
                i--;
            }
        }
        return nums.size();
    }
};

void printVector(const std::vector<int>& nums) {
    for (int num : nums) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main(){
    Solution s;
    std::vector<int> nums = {1, 1, 2};
    int newLength = s.removeDuplicates(nums);
    std::cout << "New length: " << newLength << std::endl;
    std::cout << "Modified array: ";
    printVector(nums);
    for(int i = 0; i < newLength; i++){
        std::cout << nums[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}