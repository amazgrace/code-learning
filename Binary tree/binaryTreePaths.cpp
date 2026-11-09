struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
private:
    void traverse(TreeNode* cur, vector<int>& path, vector<string>& result) {
        path.push_back(cur->val);
        if (cur->left == nullptr && cur->right == nullptr) {
            string sPath;
            for (int i = 0; i < path.size() - 1; i++) {
                sPath += to_string(path[i]);
                sPath += "->";
            }
            sPath += to_string(path[path.size() - 1]);
            result.push_back(sPath);
            return;
        }
        if (cur->left) {
            traverse(cur->left, path, result);
            path.pop_back();
        }
        if (cur->right) {
            traverse(cur->right, path, result);
            path.pop_back();
        }
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {    
        vector<string> result;
        vector<int> path;
        if (root == nullptr) return result;
        traverse(root, path, result);
        return result;
    }
};