#include<iostream>
#include<string>

class Solution {
public:
    std::string toLower(std::string s) {
    transform(s.begin(), s.end(), s.begin(),
                   [](unsigned char c) { return tolower(c); });
    return s;
    }   

    bool isPalindrome(std::string s) {
        s = toLower(s);
        std::string test = "";
        for (unsigned char c : s) {
            if (isalnum(c))
                test += c;
        }
        std::string reverse(test.rbegin(), test.rend());
        return reverse == test;
    }
};

int main() {
    Solution solution;
    std::string input = "A man, a plan, a canal: Panama";
    bool result = solution.isPalindrome(input);
    std::cout << (result ? "True" : "False") << std::endl;
    return 0;
}