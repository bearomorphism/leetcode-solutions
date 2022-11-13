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
public:
    vector<int> rightSideView(TreeNode* root) {
        result_ = {};
        dfs(root, 1);
        return result_;
    }
private:
    vector<int> result_;
    void dfs(TreeNode *root, int depth) {
        if (!root) return;
        if (result_.size() < depth) result_.resize(depth);
        result_[depth - 1] = root->val;
        dfs(root->left, depth + 1);
        dfs(root->right, depth + 1);
    }
};