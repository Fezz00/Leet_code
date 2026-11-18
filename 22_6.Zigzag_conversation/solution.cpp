#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    std::string convert(std::string s, int numRows) {
        if (numRows == 1) return s;

        std::vector<std::string> rows(numRows);
        int row = 0;
        bool decrease = false;

        for (char c : s) {
            rows[row] += c;

            if (row == 0) decrease = false;
            else if (row == numRows - 1) decrease = true;

            row += decrease ? -1 : 1;
        }

        std::string result;
        for (std::string& r : rows) result += r;
        return result;
    }
};

int main() {
    Solution solution;
    std::string s = "PAYPALISHIRING";
    int numRows = 3;
    std::string result = solution.convert(s, numRows);
    std::cout << result << std::endl; // Output: "PAHNAPLSIIGYIR"
    return 0;
}