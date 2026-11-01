#include <iostream>
#include <vector>

class Solution {
public:
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
        std::vector<int> temp;
        int index_1 = 0;
        int index_2 = 0;
        int size = m + n;
        for(int i=0; i < size; i++){
            if(index_2 >= n || (index_1 < m && nums1[index_1] < nums2[index_2])){
                temp.push_back(nums1[index_1]);
                index_1++;
            }
            else{
                temp.push_back(nums2[index_2]);
                index_2++;
            }
        }
        nums1 = temp;
    }
};

int main(){
    Solution s;
    std::vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    std::vector<int> nums2 = {2, 5, 6};
    s.merge(nums1, 3, nums2, 3);
    for(int i : nums1){
        std::cout << i << " ";
    }
    return 0;
}
