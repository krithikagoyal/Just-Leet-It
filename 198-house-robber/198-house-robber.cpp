class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(3, 0);
        int mx = 0;
        for (int i = n - 1; i >= 0; i--) {
            int val = nums[i];
            // dp[i] = nums[i];
            if (i + 2 < n) {
                val = max(nums[i] + dp[1], val);
            }
            if (i + 3 < n) {
                val = max(nums[i] + dp[2], val);
            }
            dp[2] = dp[1];
            dp[1] = dp[0];
            dp[0] = val;
            mx = max(val, mx);
        }
        return mx;
    }
};