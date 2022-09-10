class Solution {
private:
    int partition(vector<int> &nums, int l, int r) {
        int i = l, j = r + 1;
        while (true) {
            while (i < r && nums[++i] < nums[l]);
            while (j > l && nums[l] < nums[--j]);
            if (i >= j) break;
            swap(nums[i], nums[j]);
        }
        swap(nums[l], nums[j]);
        return j;
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        shuffle (nums.begin(), nums.end(), std::default_random_engine(seed));
        int l = 0, r = nums.size() - 1;
        k = nums.size() - k;
        while (l < r) {
            int pivot = partition(nums, l, r);
            if (pivot < k) {
                l = pivot + 1;
            } else if (pivot > k) {
                r = pivot - 1;
            } else {
                break;
            }
        }
        return nums[k];
    }
};