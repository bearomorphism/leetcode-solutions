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
class Solution
{
private:
    // find the maximum path sum from the root to its children
    int dfs(TreeNode *root, int &ret)
    {
        int left = root->left ? dfs(root->left, ret) : 0;
        int right = root->right ? dfs(root->right, ret) : 0;
        ret = max(ret, left + right + root->val);
        return max(0, root->val + max(left, right));
    }

public:
    int maxPathSum(TreeNode *root)
    {
        int ret = INT_MIN;
        dfs(root, ret);
        return ret;
    }
};
