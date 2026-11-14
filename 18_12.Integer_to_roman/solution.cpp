#include<iostream>
#include<string>

class Solution {
public:
    std::string intToRoman(int num) {
        std::string result;
        int thousand = num / 1000;
        if(thousand >= 1)
            num %= 1000;
        int five_hundered = num / 500;
        if(five_hundered >= 1)
            num -= 500;
        int hundered = num / 100;
        if(hundered >= 1)
            num %= 100;
        int fifty = num / 50;
        if(fifty >= 1)
            num -= 50;
        int ten = num / 10;
        if(ten >= 1)
            num %= 10;
        int five = num / 5;
        if(five >= 1)
            num -= 5;
        int one = num;

        bool hundered_flag = false;
        bool ten_flag = false;
        bool one_flag = false;

        for(int i=0; i<thousand; i++){
            result += 'M';
        }

        if(five_hundered == 1 && hundered == 4){
            result.append("CM");
            hundered_flag = true;
        }
        if(hundered == 4 && five_hundered == 0){
            result.append("CD");
            hundered_flag = true;
        }
        if(!hundered_flag){
            if(five_hundered == 1)
                result += 'D';
            for(int i=0; i<hundered; i++){
                result += 'C';
            }
        }

        if(fifty == 1 && ten == 4){
            result.append("XC");
            ten_flag = true;
        }
        if(ten == 4 && fifty == 0){
            result.append("XL");
            ten_flag = true;
        }
        if(!ten_flag){
            if(fifty == 1)
                result += 'L';
            for(int i=0; i<ten; i++){
                result += 'X';
            }
        }

        if(five == 1 && one == 4){
            result.append("IX");
            one_flag = true;
        }
        if(one == 4 && five == 0){
            result.append("IV");
            one_flag = true;
        }
        if(!one_flag){
            if(five == 1)
                result += 'V';
            for(int i=0; i<one; i++){
                result += 'I';
            }
        }

        return result;
    }
};

int main() {
    Solution solution;
    int tests[] = {3749, 58, 1994, 3999, 4, 9, 40, 90, 400, 900};
    for(int num : tests)
        std::cout << num << " -> " << solution.intToRoman(num) << std::endl;
    return 0;
}
