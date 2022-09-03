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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) return {};
        vector<TreeNode*> v({root});
        vector<vector<int>> ret;
        bool f = false;
        while (!v.empty()) {
            vector<TreeNode*> v2;
            vector<int> a;
            for (auto node: v) {
                a.push_back(node->val);
                for (auto n: {node->left, node->right}) {
                    if (n) v2.push_back(n);
                }
            }
            if (f) reverse(a.begin(), a.end());
            ret.push_back(a);
            v = v2;
            f = !f;
        }
        return ret;
    }
};