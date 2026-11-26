#include<iostream>
#include<vector>

class Solution {
public:
    int binary_search(std::vector<int>& numbers, int target, int lo, int hi){
        if(hi >= lo){
            int mid = lo + (hi - lo) / 2;
        
            if(numbers[mid] == target)
                return mid;
            if(numbers[mid] > target)
                return binary_search(numbers, target, lo, mid-1);
            return binary_search(numbers, target, mid+1, hi);
        }
        return -110001;
    }

    std::vector<int> twoSum(std::vector<int>& numbers, int target) {
        int size = (int)numbers.size();
        int temp = 0;
        int bin_search_result = 0;
        for (int i = 0; i < size; i++) {
            temp = target - numbers[i];
            bin_search_result = binary_search(numbers, temp, i + 1, size - 1);
            if (bin_search_result != -110001)
                return {i + 1, bin_search_result + 1};
        }
        return {};
    }
};

int main() {
    Solution solution;
    std::vector<int> numbers = {2, 7, 11, 15};
    int target = 9;
    std::vector<int> result = solution.twoSum(numbers, target);
    
    std::cout << "Indices: [" << result[0] << ", " << result[1] << "]" << std::endl;
    return 0;
}