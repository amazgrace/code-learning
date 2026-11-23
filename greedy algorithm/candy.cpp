class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> candyVec(ratings.size(), 1);
        // 从左到右遍历，如果当前评分大于前一个评分，糖果数加1
        for (int i = 1; i < ratings.size(); i++) {
            if (ratings[i] > ratings[i - 1]) {
                candyVec[i] = candyVec[i - 1] + 1;
            }
        }
        // 从右到左遍历，如果当前评分大于后一个评分，糖果数加1
        for (int i = ratings.size() - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                candyVec[i] = max(candyVec[i], candyVec[i + 1] + 1);
            }
        }
        // 计算总糖果数
        int total = 0;
        for (int i = 0; i < ratings.size(); i++) {
            total += candyVec[i];
        }
        return total;
    }
};