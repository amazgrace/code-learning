#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> nums_set(nums1.begin(), nums1.end());
        unordered_set<int> result_Set;
        for (int num : nums2) {
            if (nums_set.count(num)) {
                result_Set.insert(num);
            }
        }
        return vector<int>(result_Set.begin(), result_Set.end());
    }
};

int main() {
    Solution s;
    vector<int> nums1 = {1, 2, 2, 1};
    vector<int> nums2 = {2, 2};
    vector<int> result = s.intersection(nums1, nums2);
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}