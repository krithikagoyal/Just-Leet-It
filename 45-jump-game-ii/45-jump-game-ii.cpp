class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        // vector<int> v(n, 0);
        int jumps = 0;
        int curr_idx = 0;
        int mx = 0;
        for (int i = 0; i < n; i++) {
            if (i) {
                mx = max(nums[i] + i, mx);
            } else {
                mx = nums[i] + i;
            }
            if (curr_idx >= n - 1) {
                return jumps;
            }
            if (i == curr_idx) {
                curr_idx = mx;
                jumps++;
            }
        }

        return jumps;
    }
};