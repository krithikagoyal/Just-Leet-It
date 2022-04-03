class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        sort(wordDict.begin(), wordDict.end());
        int n = s.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        for(int i = 1; i <= s.size(); i++){
            for(string str: wordDict){
                if(str.size() <= i){
                    if(dp[i - str.size()]){
                        if(s.substr(i - str.size(), str.size()).compare(str) == 0){
                            dp[i] = true;
                            break;
                        }
                    }
                }
            }
        }
        // for (int i = 0; i < n; i++) {
        //     dp[i] = binary_search(wordDict.begin(), wordDict.end(), s.substr(0, i + 1));
        //     for (int j = i; (j > 0) && (dp[i] == false); j--) {
        //         dp[i] = binary_search(wordDict.begin(), wordDict.end(), s.substr(j, i - j + 1)) & dp[j - 1]; 
        //     }
        // }
        return dp[n];
    }
};
