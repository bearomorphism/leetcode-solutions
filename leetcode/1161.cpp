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
    int maxLevelSum(TreeNode* root) {
        vector<TreeNode*> v({root});
        int ret = 1, maxi = root->val, depth = 1;
        while (!v.empty()) {
            vector<TreeNode*> v2;
            int sum = 0;
            for (auto node: v) {
                sum += node->val;
                for (auto child: {node->left, node->right}) {
                    if (child) {
                        v2.push_back(child);
                    }
                }
            }
            v = v2;
            if (maxi < sum) {
                maxi = sum;
                ret = depth;
            }
            depth++;
        }
        return ret;
    }
};