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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        bool emp = false;
        q.push(root);
        while (!q.empty()) {
            auto c = q.front();
            q.pop();
            if (!c) {
                emp = true;
            } else {
                if (emp) return false;
                q.push(c->left);
                q.push(c->right);
            }
        }
        return true;
    }
};