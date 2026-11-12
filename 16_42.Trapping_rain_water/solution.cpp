#include<iostream>
#include<vector>

class Solution {
public:
    int trap(std::vector<int>& height) {
        int size = height.size();
        if(size <= 0)
            return 0;
        std::vector<int> water(size, 0);
        int local_max = height[0];
        int index = 0;
        int sum = 0;
        for(int i=1; i<size; i++){
            if(height[i] >= local_max){
                for(int j=index+1; j<i; j++){
                    water[j] = local_max - height[j];
                }
                local_max = height[i];
                index = i;
            }
        }
        int peak = index;
        local_max = height[size-1];
        index = size-1;
        for(int i=size-2; i>=peak; i--){
            if(height[i] >= local_max){
                for(int j=i+1; j<index; j++){
                    water[j] = local_max - height[j];
                }
                local_max = height[i];
                index = i;
            }
        }

        for(int i=0; i<size; i++){
            sum += water[i];
        }
        return sum;
    }
};

int main(){
    Solution s;
    std::vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    std::cout << s.trap(height) << std::endl;
    return 0;
}