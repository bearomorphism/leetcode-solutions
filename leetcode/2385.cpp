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
    int amountOfTime(TreeNode* root, int start) {
        vector<vector<int>> g(100005, vector<int>());
        init(g, root);
        vector<int> v;
        vector<bool> vis(100005, false);
        v.push_back(start);
        vis[start] = true;
        int ret = -1;
        while (!v.empty()) {
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
            ret++;
        }
        return ret;
    }
};