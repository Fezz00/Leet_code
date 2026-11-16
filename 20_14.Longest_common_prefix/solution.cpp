#include<iostream>
#include<vector>
#include<string>

class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        int size = strs.size();
        int length = strs[0].length();
        std::string output = "";
        for (int i = 0; i < length; i++) {
            char c = strs[0][i];
            for (int j = 1; j < size; j++) {
                if (i >= strs[j].length() || strs[j][i] != c)
                    return output;
            }
            output += c;
        }
        return output;
    }
};

int main() {
    Solution solution;
    std::vector<std::string> strs = {"flower", "flow", "flight"};
    std::string result = solution.longestCommonPrefix(strs);
    std::cout << "Longest Common Prefix: " << result << std::endl;
    return 0;
}