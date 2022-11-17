class Solution {
public:
    Solution(vector<int>& nums): init_(nums) {

    }

    vector<int> reset() {
        return init_;
    }

    vector<int> shuffle() {
        vector<int> result(init_);
        for (int i = result.size() - 1; i >= 0; i--) {
            int j = rand() % (i + 1);
            swap(result[i], result[j]);
        }
        return result;
    }
private:
    vector<int> init_;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */