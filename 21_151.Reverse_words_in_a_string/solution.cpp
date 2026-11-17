#include<iostream>
#include<string>
#include<vector>

class Solution {
public:
    std::string reverseWords(std::string s) {
        int size = s.length();
        std::string temp = "";
        std::vector<std::string> reverse;
        for(int i=0; i<size; i++){
            if(s[i] != ' '){
                temp += s[i];
            }
            else{
                if(temp != "")
                    reverse.push_back(temp);
                temp = "";
            }
        }
        if (temp != "")
            reverse.push_back(temp);
        temp = reverse[reverse.size()-1];
        for(int i=reverse.size()-2; i>=0; i--){
            temp += " ";
            temp += reverse[i];
        }
        return temp;
    }
};

int main(){
    Solution s;
    std::string str = "the sky is blue";
    std::cout << s.reverseWords(str) << std::endl;
    return 0;
}