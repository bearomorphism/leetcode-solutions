/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    void init(vector<vector<int>> &g, TreeNode *root) {
        if (root->left) {
            g[root->left->val].push_back(root->val);
            g[root->val].push_back(root->left->val);
            init(g, root->left);
        }
        if (root->right) {
            g[root->right->val].push_back(root->val);
            g[root->val].push_back(root->right->val);
            init(g, root->right);
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<vector<int>> g(505, vector<int>());
        init(g, root);
        vector<int> v;
        vector<bool> vis(505, false);
        v.push_back(target->val);
        vis[target->val] = true;
        while (!v.empty() && k) {
            vector<int> v2;
            for (int i: v) {
                for (int j: g[i]) {
                    if (!vis[j]) {
                        vis[j] = true;
                        v2.push_back(j);
                    }
                }
            }
            v = v2;
            k--;
        }
        return v;
    }
};