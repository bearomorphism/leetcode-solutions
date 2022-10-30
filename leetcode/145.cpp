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
    vector<int> result;
    void dfs(TreeNode* root) {
        for (auto &node: {root->left, root->right}) {
            if (node) dfs(node);
        }
        result.push_back(root->val);
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        result.clear();
        if (!root) return {};
        dfs(root);
        return result;
    }
};