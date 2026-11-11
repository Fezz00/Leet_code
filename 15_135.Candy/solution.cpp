#include<iostream>
#include<vector>

class Solution {
public:
    int candy(std::vector<int>& ratings) {
        int n = ratings.size();
        std::vector<int> candies(n, 1);

        // Left to right: a child rated higher than the left neighbor gets one more.
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }

        // Right to left: a child rated higher than the right neighbor needs more,
        // keeping whatever the first pass already gave if it's larger.
        int total = candies[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                candies[i] = std::max(candies[i], candies[i + 1] + 1);
            }
            total += candies[i];
        }
        return total;
    }
};

int main() {
    Solution solution;
    std::vector<int> ratings = {1, 0, 2};
    int result = solution.candy(ratings);
    std::cout << "Minimum candies: " << result << std::endl;
    return 0;
}
