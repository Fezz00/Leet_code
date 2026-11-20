#include<iostream>
#include<string>
#include<vector>

class Solution {
public:
    std::vector<std::string> fullJustify(std::vector<std::string>& words, int maxWidth) {
        std::vector<std::string> result;
        int n = words.size();
        int i = 0;
        while (i < n) {
            int letters = words[i].length();
            int j = i + 1;
            while (j < n && letters + (j - i) + (int)words[j].length() <= maxWidth) {
                letters += words[j].length();
                j++;
            }

            int gaps = j - i - 1;
            std::string line = words[i];

            if (j == n || gaps == 0) {
                for (int k = i + 1; k < j; k++)
                    line += " " + words[k];
                line += std::string(maxWidth - line.length(), ' ');
            } else {
                int spaces = maxWidth - letters;
                int each = spaces / gaps;
                int extra = spaces % gaps;
                for (int k = i + 1; k < j; k++) {
                    int count = each + (k - i <= extra ? 1 : 0);
                    line += std::string(count, ' ') + words[k];
                }
            }

            result.push_back(line);
            i = j;
        }
        return result;
    }
};

int main(){
    Solution s;
    std::vector<std::string> words = {"Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"};
    int maxWidth = 20;
    std::vector<std::string> result = s.fullJustify(words, maxWidth);
    for(auto i : result){
        std::cout << i << std::endl;
    }
    return 0;
}