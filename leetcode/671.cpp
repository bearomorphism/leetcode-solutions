/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    void dfs(TreeNode *root, int &ret) {
        if (root->left) {
            if (root->left->val == root->val) dfs(root->left, ret);
            else ret = ret == -1 ? root->left->val : min(ret, root->left->val);
        }
        if (root->right) {
            if (root->right->val == root->val) dfs(root->right, ret);
            else ret = ret == -1 ? root->right->val : min(ret, root->right->val);
        }
    }
public:
    int findSecondMinimumValue(TreeNode* root) {
        int ret = -1;
        dfs(root, ret);
        return ret;
    }
};