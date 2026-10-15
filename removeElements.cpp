#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int removeElement(vector<int> &nums, int val) {
        int slowIndex = 0;
        for (int fastIndex = 0; fastIndex <nums.size(); fastIndex++) {
            if (val != nums[fastIndex]) {
                nums[slowIndex] = nums[fastIndex];
                slowIndex++;
            }
        }
        return slowIndex;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {3, 2, 2, 3};
    int val = 3;
    int newLength = solution.removeElement(nums, val);
    cout << "New length after removing " << val << ": " << newLength << endl;
    cout << "Modified array: [";
    for (int i = 0; i < newLength; i++) {
        cout << " " << nums[i] << " ";
    }
    cout << "] " << endl;
}