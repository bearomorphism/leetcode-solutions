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
    vector<string> binaryTreePaths(TreeNode* root) {
        result = {};
        cur = {};
        dfs(root);
        return result;
    }
private:
    vector<int> cur;
    vector<string> result;
    void dfs(TreeNode *root) {
        if (!root) return;
        cur.push_back(root->val);
        if (root->left || root->right)
            for (auto node: {root->left, root->right}) {
                dfs(node);
            }
        else {
            string s = to_string(cur[0]);
            for (int i = 1; i < cur.size(); i++) {
                s += "->" + to_string(cur[i]);
            }
            result.push_back(s);
        }
        cur.pop_back();
    }
};