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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ret;
        vector<TreeNode*> v;
        if (root) v.push_back(root);
        while (!v.empty()) {
            vector<TreeNode*> v2;
            vector<int> lev;
            for (auto node: v) {
                lev.push_back(node->val);
                for (auto nod: {node->left, node->right}) {
                    if (nod) v2.push_back(nod);
                }
            }
            ret.push_back(lev);
            v = v2;
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};