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
    void dfs(TreeNode* t, unordered_set<int> &us, vector<TreeNode*> &ret) {
        int cnt = us.count(t->val);
        for (auto c: {t->left, t->right}) {
            if (c) {
                if (cnt && !us.count(c->val)) ret.push_back(c);
                dfs(c, us, ret);
            }
        }
        if (t->left && us.count(t->left->val)) t->left = nullptr;
        if (t->right && us.count(t->right->val)) t->right = nullptr;
    }
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> us(to_delete.begin(), to_delete.end());
        vector<TreeNode*> ret;
        if (!us.count(root->val)) ret.push_back(root);
        dfs(root, us, ret);
        return ret;
    }
};