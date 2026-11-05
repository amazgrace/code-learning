struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 统一迭代法中序遍历（空指针标注法）
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        if (root != nullptr) {
            st.push(root);
        }
        while ( !st.empty()) {
            TreeNode* node = st.top();
            if (node != nullptr) {
                st.pop();
                if (node->right) st.push(node->right);
                st.push(node);
                st.push(nullptr);
                if (node->left) st.push(node->left);
            } else {
                st.pop();
                node = st.top();
                st.pop();
                result.push_back(node->val);
            }
        }
        return result;
    }
};

// 统一迭代法中序遍历（boolean 标记法）
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<pair<TreeNode*, bool>> st;
        if (root != nullptr)
            st.push(make_pair(root, false)); // 多加一个参数，false 为默认值，含义见下文注释

        while (!st.empty()) {
            auto node = st.top().first;
            auto visited = st.top().second; //多加一个 visited 参数，使“迭代统一写法”成为一件简单的事
            st.pop();

            if (visited) { // visited 为 True，表示该节点和两个儿子位次之前已经安排过了，现在可以收割节点了
                result.push_back(node->val);
                continue;
            }

            // visited 当前为 false, 表示初次访问本节点，此次访问的目的是“把自己和两个儿子在栈中安排好位次”。
            
            // 中序遍历是'左中右'，右儿子最先入栈，最后出栈。
            if (node->right)
                st.push(make_pair(node->right, false));
            
            // 把自己加回到栈中，位置居中。
            // 同时，设置 visited 为 true，表示下次再访问本节点时，允许收割。
            st.push(make_pair(node, true));

            if (node->left)
                st.push(make_pair(node->left, false)); // 左儿子最后入栈，最先出栈
        }
        
        return result;
    }
};