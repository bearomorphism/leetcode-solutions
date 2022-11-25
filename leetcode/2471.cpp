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
    int minimumOperations(TreeNode* root) {
        vector<TreeNode*> v1{root}, v2;
        int result = 0;
        while (!v1.empty()) {
            result += helper(v1);
            v2.clear();
            for (auto node: v1) {
                for (auto child: {node->left, node->right}) {
                    if (child) {
                        v2.emplace_back(child);
                    }
                }
            }
            v1.swap(v2);
        }
        return result;
    }
private:
    int helper(vector<TreeNode*> &t) {
        vector<pair<int, int>> v;
        for (int i = 0; i < t.size(); i++) {
            v.push_back({t[i]->val, i});
        }
        sort(v.begin(), v.end());
        int cnt = 0;
        for (int i = 0; i < v.size(); i++) {
            while (v[i].second != i) {
                swap(v[v[i].second], v[i]);
                cnt++;
            }
        }
        return cnt;
    }
};