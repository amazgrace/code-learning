struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
private:
    vector<int> vec;
    void traverse(TreeNode* root) {
        if (root == nullptr) return;
        traverse(root->left);
        vec.push_back(root->val);
        traverse(root->right);
    }
public:
    bool isValidBST(TreeNode* root) {
        vec.clear();
        traverse(root);
        for (int i = 0; i < vec.size() - 1; i++) {
            if (vec[i] >= vec[i + 1]) return false;
        }
        return true;
    }
};

class Solution {
public:
    TreeNode* pre = nullptr; // 用来记录前一个节点
    bool isValidBST(TreeNode* root) {
        if (root == nullptr) return true;
        bool left = isValidBST(root->left);

        if (pre != nullptr && pre->val >= root->val) return false;
        pre = root; // 记录前一个节点

        bool right = isValidBST(root->right);
        return left && right;
    }
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* cur = root;
        TreeNode* pre = nullptr; // 记录前一个节点
        while (cur != nullptr || !st.empty()) {
            if (cur != nullptr) {
                st.push(cur);
                cur = cur->left;                // 左
            } else {
                cur = st.top();                 // 中
                st.pop();
                if (pre != nullptr && cur->val <= pre->val)
                return false;
                pre = cur; //保存前一个访问的结点

                cur = cur->right;               // 右
            }
        }
        return true;
    }
};