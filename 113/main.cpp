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
public:
    void dfs(vector<int> &c, vector<vector<int>> &res, TreeNode *cur, int targetSum)
    {
        c.push_back(cur->val);
        if (!cur->left && !cur->right)
        {
            if (targetSum - cur->val == 0)
            {
                res.push_back(c);
            }
        }
        else
        {
            if (cur->left)
                dfs(c, res, cur->left, targetSum - cur->val);
            if (cur->right)
                dfs(c, res, cur->right, targetSum - cur->val);
        }
        c.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        if (!root)
            return {};
        vector<int> v;
        vector<vector<int>> res;
        dfs(v, res, root, targetSum);
        return res;
    }
};