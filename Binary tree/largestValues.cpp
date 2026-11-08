struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        queue<TreeNode*> que;
        vector<int> result;
        if (root != nullptr) que.push(root);
        while (!que.empty()) {
            int size = que.size();
            int maxVal = INT_MIN;
            for (int i = 0; i < size; i++) {
                TreeNode* node = que.front();
                que.pop();
                maxVal = max(maxVal, node->val);
                if (node->left != nullptr) que.push(node->left);
                if (node->right != nullptr) que.push(node->right);
            }
            result.push_back(maxVal);
        }
        return result;
    }
};