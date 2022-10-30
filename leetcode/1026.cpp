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
    tuple<int, int, int> dfs(TreeNode* root) {
        int diff = 0, maxi = root->val, mini = root->val;
        for (TreeNode* node: {root->left, root->right}) {
            if (node) {
                auto [n_diff, n_maxi, n_mini] = dfs(node);
                diff = max(diff, n_diff);
                diff = max(diff, abs(root->val - n_maxi));
                diff = max(diff, abs(root->val - n_mini));
                maxi = max(maxi, n_maxi);
                mini = min(mini, n_mini);
            }
        }
        return make_tuple(diff, maxi, mini);
    }
public:
    int maxAncestorDiff(TreeNode* root) {
        auto [a, b, c] = dfs(root);
        return a;
    }
};