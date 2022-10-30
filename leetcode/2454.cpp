struct El {
    int num;
    mutable int cnt;
    int idx;

    bool operator<(const El& rhs) const {
        if (num == rhs.num) return idx < rhs.idx;
        return num < rhs.num;
    }
};

class Solution {
public:
    vector<int> secondGreaterElement(vector<int>& nums) {
        set<El> se; // num, cnt, index
        int n = nums.size();
        vector<int> result(n, -1);
        for (int i = 0; i < n; i++) {
            auto it = se.upper_bound({nums[i] - 1, 0, 1000000});
            vector<set<El>::iterator> toErase;
            for (auto j = se.begin(); j != it; j++) {
                j->cnt++;
                if (j->cnt > 1) {
                    toErase.push_back(j);
                }
            }
            for (auto j: toErase) {
                result[j->idx] = nums[i];
                se.erase(j);
            }

            se.insert({nums[i], 0, i});
        }
        return result;
    }
};