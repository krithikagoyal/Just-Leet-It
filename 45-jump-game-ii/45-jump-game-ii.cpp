class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> v(n, 0);
        for (int i = 0; i < n; i++) {
            if (i) {
                v[i] = max(nums[i] + i, v[i - 1]);
            } else {
                v[i] = nums[i] + i;
            }
        }
        int jumps = 0;
        int curr_idx = 0;
        while (curr_idx < n - 1) {
            curr_idx = v[curr_idx];
            jumps++;
        }
        return jumps;
    }
};