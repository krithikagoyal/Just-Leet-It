class Solution {
public:
    int minInsertions(string s) {        
        int n = s.size();
        
        // if (n == 1) {
        //     return 0;    
        // }
        
        vector<vector<int>> dp(n, vector<int>(n));
        
        for (int i = 0; i < n; i++) {
            for (int j = n - 1; j >= 0; j--) {
                int val1 = (i > 0 ? dp[i - 1][j] : 0);
                int val2 = (j < n - 1 ? dp[i][j + 1] : 0);
                int val3 = (i > 0 && j < n - 1 ? dp[i - 1][j + 1] + (s[i] == s[j]) : 0);
                dp[i][j] = max({val1, val2, val3, 0 + (s[i] == s[j])});
            }
        }
        
        int ans = INT_MAX;
        
        for (int i = 0; i < 2 * n; i++) {
            int left, right;
            if (i % 2 == 0) {
                left = i / 2 - 1;
                right = left + 1;
            } else {
                left = i / 2 - 1;
                right = left + 2;
            }
            if (left >= 0 && right <= n - 1) {
                ans = min({ans, n - (i % 2) - 2 * dp[left][right]});
                // cout << ans << " " << i << endl;
            } else {
                ans = min(ans, max(left + 1, n - right));
            }
        }
        
        return ans;
    }
};