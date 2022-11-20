/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        vector<vector<int>> edges(101);
        vector<bool> vis(101);
        dfs(node, vis, edges);
        vector<Node*> nodes(101);
        for (int i = 1; i < 101; i++) {
            nodes[i] = new Node(i);
        }
        for (int i = 1; i < 101; i++) {
            for (int e: edges[i]) {
                nodes[i]->neighbors.push_back(nodes[e]);
            }
        }
        return nodes[node->val];
    }
private:
    void dfs(Node *node, vector<bool> &vis, vector<vector<int>> &edges) {
        vis[node->val] = true;
        for (auto next: node->neighbors) {
            edges[node->val].push_back(next->val);
            // cout << node->val << ' ' << next->val << '\n';
            if (!vis[next->val]) {
                dfs(next, vis, edges);
            }
        }
    }
};