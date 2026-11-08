#include<iostream>
#include<vector>

class Solution {
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums) {
        std::vector<int> answer;
        int size = nums.size();
        int flag = 0;
        int temp = 1;
        for(int i : nums){
            if(i == 0){
                flag++;
                continue;
            }
            temp *= i;
        }
        if(flag == 0){
            for(int i : nums){
                answer.push_back(temp/i);
            }
        }else if(flag == 1){
            for(int i : nums){
                if(i == 0){
                    answer.push_back(temp);
                    continue;
                }
                answer.push_back(0);
            }
        }else{
            for(int i=0; i<size; i++){
                answer.push_back(0);
            }
        }
        return answer;
    }
};

int main(){
    Solution s;
    std::vector<int> nums = {-1, 1, 0, -3, 3};
    std::vector<int> result = s.productExceptSelf(nums);
    for(int i : result){
        std::cout << i << " ";
    }
    return 0;
}