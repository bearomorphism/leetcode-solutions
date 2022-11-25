class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        const int mod = 1e9 + 7;
        long long result = 0;
        stack<int> st;

        auto update = [&](int r) {
            int idx = st.top();
            st.pop();
            int l = st.empty() ? -1 : st.top();
            long long cnt = (r - idx) * (idx - l);
            result = (result + cnt * arr[idx]) % mod;
        };

        int n = arr.size();
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[i] <= arr[st.top()]) {
                update(i);
            }
            st.push(i);
        }

        while (!st.empty()) {
            update(n);
        }

        return result;
    }
};