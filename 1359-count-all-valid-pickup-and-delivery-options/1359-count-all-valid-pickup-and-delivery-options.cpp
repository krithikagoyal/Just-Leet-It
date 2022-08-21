class Solution {
public:
    int countOrders(int n) {
        vector<long> dp(n + 1, 0);
        dp[0] = 1;
        const int mod = 1000000007;
        for (int i = 1; i < n + 1; i++) {
            int num = 2 * (i - 1);
            dp[i] += dp[i - 1] * (long)(((num + 1) * (num + 2)) % mod) / 2;
            dp[i] %= mod;
        }
        return (int)dp[n];
    }
};