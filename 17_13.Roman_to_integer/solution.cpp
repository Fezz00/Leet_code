#include<iostream>
#include<string>

class Solution {
public:
    int romanToInt(std::string s) {
        int size = s.length();
        if(size == 0)
            return 0;
        //s = s.toupper();
        int sum = 0;
        for(int i = 0; i < size-1; i++){
            if(s[i] == 'M')
                sum += 1000;
            else if(s[i] == 'D')
                sum += 500;
            else if(s[i] == 'C')
                if(s[i+1] == 'D' || s[i+1] == 'M')
                    sum -= 100;
                else
                    sum += 100;
            else if(s[i] == 'L')
                sum += 50;
            else if(s[i] == 'X')
                if(s[i+1] == 'L' || s[i+1] == 'C')
                    sum -= 10;
                else
                    sum += 10;
            else if(s[i] == 'V')
                sum += 5;
            else
                if(s[i+1] == 'V' || s[i+1] == 'X')
                    sum -= 1;
                else
                    sum += 1;
        }
        if(s[size-1] == 'M')
            sum += 1000;
        else if(s[size-1] == 'D')
            sum += 500;
        else if(s[size-1] == 'C')
            sum += 100;
        else if(s[size-1] == 'L')
            sum += 50;
        else if(s[size-1] == 'X')
            sum += 10;
        else if(s[size-1] == 'V')
            sum += 5;
        else
            sum += 1;

        return sum;
    }
};

int main(){
    Solution s;
    std::string str = "MCMXCIV";
    std::cout << s.romanToInt(str) << std::endl;
    return 0;
}