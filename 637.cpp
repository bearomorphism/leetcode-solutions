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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ret;
        vector<TreeNode*> v;
        v.push_back(root);
        while (!v.empty()) {
            vector<TreeNode*> v2;
            long long sum = 0;
            for (auto node: v) {
                sum += node->val;
                for (auto nod: {node->left, node->right}) {
                    if (nod) v2.push_back(nod);
                }
            }
            ret.push_back((double)sum / v.size());
            v = v2;
        }
        return ret;
    }
};