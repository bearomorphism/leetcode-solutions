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
    int pathSum(TreeNode* root, int targetSum) {
        cnt_ = {};
        cnt_[0] = 1;
        ans_ = 0;
        target_ = targetSum;
        dfs(root, 0);
        return ans_;
    }
private:
    unordered_map<long long, int> cnt_;
    int ans_, target_;
    void dfs(TreeNode *root, long long last) {
        if (!root) return;
        long long cur = last + root->val;
        ans_ += cnt_[cur - target_];
        cnt_[cur]++;
        dfs(root->left, cur);
        dfs(root->right, cur);
        cnt_[cur]--;
    }
};