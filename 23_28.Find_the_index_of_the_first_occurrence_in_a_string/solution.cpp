#include<iostream>
#include<string>

class Solution {
public:
    int strStr(std::string haystack, std::string needle) {
        int index = -1;
        bool flag = true;
        int haystack_index = 0;
        int size = haystack.length();
        for(int i=0; i<size; i++){
            if(needle[0] == haystack[i]){
                index = i;
                haystack_index = i;
                flag = true;
                for(int j=0; j<needle.length(); j++){
                    if(haystack[haystack_index] != needle[j]){
                        flag = false;
                        break;
                    }
                    haystack_index++;
                }
                if(flag)
                    return index;
            }
        }
        return -1;
    }
};

int main() {
    Solution solution;
    std::string haystack = "hello";
    std::string needle = "ll";
    int result = solution.strStr(haystack, needle);
    std::cout << result << std::endl;
    return 0;
}