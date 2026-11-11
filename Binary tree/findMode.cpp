struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
private:
    void searchBST(TreeNode* cur, unordered_map<int, int>& map) {
        if (cur == nullptr) return;
        map[cur->val]++;
        searchBST(cur->left, map);
        searchBST(cur->right, map);
    }
    bool static cmp (const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    }
public:
    vector<int> findMode(TreeNode* root) {
        unordered_map<int, int> map;
        vector<int> result;
        if (root == nullptr) return result;
        searchBST(root, map);
        vector<pair<int, int>> vec(map.begin(), map.end());
        sort(vec.begin(), vec.end(), cmp);
        for (int i = 0; i < vec.size(); i++) {
            if (vec[i].second == vec[0].second) {
                result.push_back(vec[i].first);
            }
        }
        return result;
    }
};

class Solution {
private:
    int maxCount = 0; // 最大频率
    int count = 0; // 统计频率
    TreeNode* pre = nullptr;
    vector<int> result;
    void searchBST(TreeNode* cur) {
        if (cur == nullptr) return ;

        searchBST(cur->left);       // 左
                                    // 中
        if (pre == nullptr) { // 第一个节点
            count = 1;
        } else if (pre->val == cur->val) { // 与前一个节点数值相同
            count++;
        } else { // 与前一个节点数值不同
            count = 1;
        }
        pre = cur; // 更新上一个节点

        if (count == maxCount) { // 如果和最大值相同，放进result中
            result.push_back(cur->val);
        }

        if (count > maxCount) { // 如果计数大于最大值频率
            maxCount = count;   // 更新最大频率
            result.clear();     // 很关键的一步，不要忘记清空result，之前result里的元素都失效了
            result.push_back(cur->val);
        }

        searchBST(cur->right);      // 右
        return ;
    }

public:
    vector<int> findMode(TreeNode* root) {
        count = 0;
        maxCount = 0;
        pre = nullptr; // 记录前一个节点
        result.clear();

        searchBST(root);
        return result;
    }
};