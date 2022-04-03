class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        sort(wordDict.begin(), wordDict.end());
        int n = s.size();
        vector<bool> dp(n, false);
        for (int i = 0; i < n; i++) {
            dp[i] = binary_search(wordDict.begin(), wordDict.end(), s.substr(0, i + 1));
            for (int j = i; (j > 0) && (dp[i] == false); j--) {
                dp[i] = binary_search(wordDict.begin(), wordDict.end(), s.substr(j, i - j + 1)) & dp[j - 1]; 
            }
        }
        return dp[n - 1];
    }
};