class Solution {
public:
    
    vector<string> solve(int n, vector<vector<string>>& dp) {
        if (n == 0 || dp[n].size() != 0)
            return dp[n];
        vector<string> ans, fans;
        for (int i = 0; i < n; i++) {
            vector<string> v1 = solve(i, dp);
            vector<string> v2 = solve(n - i - 1, dp);
            for (string& x : v1) {
                ans.push_back('(' + x + ')');
            }
            for (string& x : v2) {
                for (string& y : ans) {
                    fans.push_back(y + x);
                }
            }
            ans.clear();
        }
        return dp[n] = fans;
    }
    
    vector<string> generateParenthesis(int n) {
        vector<vector<string>> dp(n + 1);
        dp[1] = {"()"};
        dp[0] = {""};
        return solve(n, dp);
    }
};