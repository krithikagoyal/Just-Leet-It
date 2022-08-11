class Solution {
public:
    vector<int> dp;
    
    int numDecodingsUtil(string& s, int start) {
        if (start >= s.size())
            return 1;
        if (s[start] == '0')
            return dp[start] = 0;
        if (start == s.size() - 1)
            return dp[start] = 1;
        if (dp[start] != -1)
            return dp[start];
        int ans = 0;
        ans += numDecodingsUtil(s, start + 1);
        if (start + 1 < s.size() && (s[start] == '1' || (s[start] == '2' && s[start + 1] <= '6')))
            ans += numDecodingsUtil(s, start + 2);
        return dp[start] = ans;
    }
    
    int numDecodings(string s) {
        dp.assign(s.size(), -1);
        int ans = numDecodingsUtil(s, 0);
        return ans;
    }
};