struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        int depth = 0;
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            int size = que.size();
            depth++;
            for (int i = 0; i < size; i++) {
                TreeNode* node = que.front();
                que.pop();
                if (node->left != nullptr) que.push(node->left);
                if (node->right != nullptr) que.push(node->right);
                if(node->left == nullptr && node->right == nullptr) return depth;
            }
        }
        return depth;
    }
};