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
    int deepestLeavesSum(TreeNode* root) {
        vector<TreeNode*> v;
        v.push_back(root);
        while (1) {
            vector<TreeNode*> v2;
            for (auto &n: v) {
                if (n->left) v2.push_back(n->left);
                if (n->right) v2.push_back(n->right);
            }
            if (v2.empty()) {
                int sum = 0;
                for (auto &n: v) {
                    sum += n->val;
                }
                return sum;
            }
            v = v2;
        }
    }
};