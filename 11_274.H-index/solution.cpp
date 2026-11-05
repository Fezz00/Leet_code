#include <iostream>
#include <vector>

class Solution {
public:
    int how_many_greater_than(std::vector<int>& citations, int num){
        int output = 0;
        for(auto i : citations){
            if(num <= i)
                output++;
        }
        return output;
    }
    int hIndex(std::vector<int>& citations) {
        int output = 0;
        for(int i=0; i<citations.size(); i++){
            if(i + 1 <= how_many_greater_than(citations, i+1))
                output = i + 1;
        }
        return output;
    }
};

int main() {
    Solution solution;
    std::vector<int> citations = {3, 0, 6, 1, 5};
    int h_index = solution.hIndex(citations);
    std::cout << "H-Index: " << h_index << std::endl;
    
    return 0;
}