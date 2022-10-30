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
    int pseudoPalindromicPaths (TreeNode* root) {
        f = vector<bool>(10);
        ans = 0;
        dfs(root);
        return ans;
    }
private:
    vector<bool> f;
    int ans;
    void dfs(TreeNode *root) {
        f[root->val] = !f[root->val];
        if (!root->left && !root->right) {
            int cnt = 0;
            for (int i = 1; i < 10; i++) {
                if (f[i]) cnt++;
            }
            if (cnt < 2) {
                ans++;
            }
        }
        for (auto &node: {root->left, root->right}) {
            if (node) dfs(node);
        }
        f[root->val] = !f[root->val];
    }
};