class Solution {
public:
    
    pair<int, int> winner(vector<int>& nums, int s, int e, vector<vector<pair<int, int>>>& dp) {
        if (s > e)
            return {0, 0};
        
        pair<int, int> tmp = {-1, -1};
        if (dp[s][e] != tmp)
            return dp[s][e];
        
        pair<int, int> ans;
        
        auto ans1 = winner(nums, s + 1, e, dp);
        auto ans2 = winner(nums, s, e - 1, dp);
        
        ans1.second += nums[s];
        ans2.second += nums[e];
        
        ans = ans2;
        if (ans1.second - ans1.first > ans2.second - ans2.first)
            ans = ans1;
        
        return dp[s][e] = {ans.second, ans.first};
    }
    
    bool PredictTheWinner(vector<int>& nums) {
        vector<vector<pair<int, int>>> dp(nums.size(), vector<pair<int, int>>(nums.size(), {-1, -1}));
        auto x = winner(nums, 0, nums.size() - 1, dp);
        return x.first >= x.second;
    }
};