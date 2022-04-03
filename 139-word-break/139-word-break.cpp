class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        sort(wordDict.begin(), wordDict.end());
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - i; j++) {
                dp[j][j + i] = binary_search(wordDict.begin(), wordDict.end(), s.substr(j, i + 1));
                for (int k = j; (k < j + i) && (dp[j][j + i] == false); k++) {
                    dp[j][j + i] = dp[j][j + i] | (dp[j][k] & dp[k + 1][j + i]);
                }
            }
        }
        return dp[0][n - 1];
    }
};