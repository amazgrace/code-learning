struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

//0：该节点无覆盖
//1：本节点有摄像头
//2：本节点有覆盖
class Solution {
private:
    int result;
    int travesal(TreeNode* cur) {
        if (cur == nullptr) return 2;
        int left = travesal(cur->left);
        int right = travesal(cur->right);
        if (left == 2 || right == 2) return 0;
        if (left == 0 || right == 0) {
            result++;
            return 1;
        }
        if (left == 1 || right == 1) return 2;
        return -1;
    }
public:
    int minCameraCover(TreeNode* root) {
        result = 0;
        if (travesal(root) == 0) {
            result++;
        }
        return result;
    }
};


class Solution {
private:
    int result;
    int traversal(TreeNode* cur) {
        if (cur == NULL) return 2;
        int left = traversal(cur->left);    // 左
        int right = traversal(cur->right);  // 右
        if (left == 2 && right == 2) return 0;
        else if (left == 0 || right == 0) {
            result++;
            return 1;
        } else return 2;
    }
public:
    int minCameraCover(TreeNode* root) {
        result = 0;
        if (traversal(root) == 0) { // root 无覆盖
            result++;
        }
        return result;
    }
};