
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 前序遍历
class Solution {
public:
    void traversal(TreeNode* root, vector<int>& result) {
        if ( root == nullptr) {
            return;
        }
        result.push_back(root->val);
        traversal(root->left, result);
        traversal(root->right, result);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        traversal(root, result);
        return result;
    }
};

// 中序遍历
class Solution {
public:
    void traversal(TreeNode* root, vector<int>& result) {
        if ( root == nullptr) {
            return;
        }
        traversal(root->left, result);
        result.push_back(root->val);
        traversal(root->right, result);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        traversal(root, result);
        return result;
    }
};

// 后序遍历
class Solution {
public:
    void traversal(TreeNode* root, vector<int>& result) {
        if ( root == nullptr) {
            return;
        }
        traversal(root->left, result);
        traversal(root->right, result);
        result.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        traversal(root, result);
        return result;
    }
};
