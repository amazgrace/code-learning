struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
private:
    // result 存放所有满足条件的路径
    // path 存放当前正在走的单条路径
    void traversal(TreeNode* cur, int count, vector<int>& path, vector<vector<int>>& result) {
        // 1. 遇到叶子节点，且 count 刚好为 0
        if (!cur->left && !cur->right && count == 0) {
            result.push_back(path); // 收集这条路径
            return;
        }
        // 2. 遇到叶子节点，但 count 不为 0（此路不通）
        if (!cur->left && !cur->right) {
            return;
        }

        // 3. 遍历左子树
        if (cur->left) {
            path.push_back(cur->left->val);          // 处理节点：加入路径
            traversal(cur->left, count - cur->left->val, path, result);
            path.pop_back();                         // 回溯：撤销处理
        }

        // 4. 遍历右子树
        if (cur->right) {
            path.push_back(cur->right->val);         // 处理节点：加入路径
            traversal(cur->right, count - cur->right->val, path, result);
            path.pop_back();                         // 回溯：撤销处理
        }
    }

public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> result;
        vector<int> path;
        if (root == nullptr) return result;
        
        path.push_back(root->val); // 先把根节点放进路径
        traversal(root, targetSum - root->val, path, result);
        return result;
    }
};