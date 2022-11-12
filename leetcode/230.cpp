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
    int kthSmallest(TreeNode* root, int k) {
        flag_ = false;
        i_ = ans_ = 0;
        k_ = k;
        dfs(root);
        return ans_;
    }
private:
    bool flag_;
    int i_, ans_, k_;
    void dfs(TreeNode *root) {
        if (flag_ || !root) return;
        dfs(root->left);
        i_++;
        if (i_ == k_) {
            flag_ = true;
            ans_ = root->val;
            return;
        }
        dfs(root->right);
    }
};