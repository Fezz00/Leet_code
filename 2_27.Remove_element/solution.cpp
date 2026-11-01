#include <iostream>
#include <vector>

class Solution {
public:
    int removeElement(std::vector<int>& nums, int val) {
        for(int i=0; i < nums.size(); i++){
            if(nums[i] == val){
                nums.erase(nums.begin() + i);
                i--;
            }
        }
        return nums.size();
    }
};

int main(){
    Solution s;
    std::vector<int> nums = {0,1,2,2,3,0,4,2};
    int val = 2;
    int newLength = s.removeElement(nums, val);
    
    std::cout << "New length: " << newLength << std::endl;
    std::cout << "Modified array: ";
    for(int i = 0; i < newLength; i++){
        std::cout << nums[i] << " ";
    }
    std::cout << std::endl;

    return 0;

}
