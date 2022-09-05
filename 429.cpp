/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
private:
    vector<vector<int>> ret;
    void dfs(Node* root, int depth) {
        if (depth == ret.size()) {
            ret.push_back({});
        }
        ret[depth].push_back(root->val);
        for (auto node: root->children) {
            dfs(node, depth + 1);
        }
    }
public:
    vector<vector<int>> levelOrder(Node* root) {
        ret.clear();
        if (!root) return ret;
        dfs(root, 0);
        return ret;
    }
};