#include <iostream>
#include <vector>
#include <cstdint>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int> &nums) {
        int result = INT32_MAX;
        int sum = 0;
        int i = 0;
        int sublength = 0;
        for (int j = 0; j < nums.size(); j++) {
            sum += nums[j];
            while(sum >= s) {
                sublength = j - i + 1;
                result = result < sublength ? result : sublength;
                sum -= nums[i++];
            }
        }
        return result == INT32_MAX ? 0 : result;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {2, 3, 1, 2, 4, 3};
    int s = 7;
    int result = solution.minSubArrayLen(s, nums);
    cout << result << endl; // Output: 2
    return 0;
}

