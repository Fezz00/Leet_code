#include<iostream>
#include<string>

class Solution {
public:
    bool isSubsequence(std::string s, std::string t) {
        std::string temp = "";
        int cnt = 0;
        for(auto i : t){
            if(s[cnt] == i && cnt < s.length()){
                temp += i;
                cnt++;
            }
        }
        if(temp == s)
            return true;
        else
            return false;
    }
};

int main(){
    Solution s;
    std::string str1 = "abc";
    std::string str2 = "ahbgdc";
    bool result = s.isSubsequence(str1, str2);
    std::cout << (result ? "true" : "false") << std::endl;
    return 0;
}