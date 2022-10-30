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
    void dfs(TreeNode *t, int cur, int &ret) {
        if (t->val >= cur) ret++;
        cur = max(cur, t->val);
        if (t->left) dfs(t->left, cur, ret);
        if (t->right) dfs(t->right, cur, ret);
    }
public:
    int goodNodes(TreeNode* root) {
        int ret = 0;
        dfs(root, INT_MIN, ret);
        return ret;
    }
};