#include <iostream>
#include <vector>

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        bool check = false;
        for(int i=0; i<nums.size() - 1; i++){
            if((nums[i] == nums[i+1]) && check == false){
                check = true;
            }
            else if(nums[i] == nums[i+1] && check == true){
                nums.erase(nums.begin() + i);
                i--;
            }
            else{
                check = false;
            }
        }
        return nums.size();
    }
};

int main() {
    Solution solution;
    std::vector<int> nums = {1, 1, 1, 2, 2, 3};
    int newLength = solution.removeDuplicates(nums);
    
    std::cout << "New length: " << newLength << std::endl;
    std::cout << "Modified array: ";
    for (int i = 0; i < newLength; ++i) {
        std::cout << nums[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}