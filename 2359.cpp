class Solution {
private:
    vector<int> dist(vector<int>& edges, int node) {
        int n = edges.size();
        vector<int> ret(n, 10000000);
        int x = 0;
        while (node != -1 && ret[node] == 10000000) {
            ret[node] = x;
            node = edges[node];
            x++;
        }
        return ret;
    }
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> v1 = dist(edges, node1), v2 = dist(edges, node2);
        int ret = -1, m = 9999999;
        for (int i = 0; i < n; i++) {
            int t = max(v1[i], v2[i]);
            // cout << i << ' ' << t << '\n';
            if (t < m) {
                m = t;
                ret = i;
            }
        }
        return ret;
    }
};