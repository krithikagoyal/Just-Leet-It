class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);
        int mx = 0;
        for (int i = n - 1; i >= 0; i--) {
            dp[i] = nums[i];
            if (i + 2 < n) {
                dp[i] = max(nums[i] + dp[i + 2], dp[i]);
            }
            if (i + 3 < n) {
                dp[i] = max(nums[i] + dp[i + 3], dp[i]);
            }
            mx = max(dp[i], mx);
        }
        return mx;
    }
};