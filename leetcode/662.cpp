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
    int widthOfBinaryTree(TreeNode* root) {
        long long ret = 0;
        vector<pair<TreeNode*, long long>> v;
        v.push_back({root, 0});
        while (!v.empty()) {
            ret = max(ret, v.back().second - v[0].second);
            vector<pair<TreeNode*, long long>> v2;
            for (auto p: v) {
                if (p.first->left) {
                    v2.push_back({p.first->left, p.second << 1});
                }
                if (p.first->right) {
                    v2.push_back({p.first->right, (p.second << 1) | 1});
                }
            }
            long long m = LONG_LONG_MAX;
            for (auto &p: v2) {
                m = min(m, p.second);
            }
            for (auto &p: v2) {
                p.second -= m;
            }
            v = v2;
        }
        return ret + 1;
    }
};