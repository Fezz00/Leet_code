#include<iostream>
#include<string>

class Solution {
public:
    int lengthOfLastWord(std::string s) {
        std::string result;
        int size = s.length();
        int index = 0;

        if(size == 1 && s[0] == ' '){
            return 0;
        }else if(size == 1 && s[0] != ' ')
            return 1;
        
        for(int i=size-2; i>=0; i--){
            if(s[i] == ' ' && s[i+1] != ' '){
                index = i+1;
                break;
            }
        }
        for(int i=index; i<size; i++){
            if(s[i] == ' '){
                break;
            }
            result += s[i];
        }
        return result.length();
    }
};

int main(){
    Solution s;
    std::string str = "Hello World";
    std::cout << s.lengthOfLastWord(str) << std::endl;
    return 0;
}