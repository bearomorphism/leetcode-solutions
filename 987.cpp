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
typedef pair<int, TreeNode*> iPair;
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<iPair> v({{0, root}});
        unordered_map<int, vector<int>> um;
        while (!v.empty()) {
            unordered_map<int, vector<int>> um2;
            vector<iPair> v2;
            for (auto &p: v) {
                um2[p.first].push_back(p.second->val);
                if (p.second->left) {
                    v2.push_back({p.first - 1, p.second->left});
                }
                if (p.second->right) {
                    v2.push_back({p.first + 1, p.second->right});
                }
            }
            for (auto &p: um2) {
                sort(p.second.begin(), p.second.end());
                for (int i: p.second) {
                    um[p.first].push_back(i);
                }
            }
            v = v2;
        }
        vector<pair<int, vector<int>>> u(um.begin(), um.end());
        sort(u.begin(), u.end());
        vector<vector<int>> ret;
        for (auto &p: u) {
            ret.push_back(p.second);
        }
        return ret;
    }
};