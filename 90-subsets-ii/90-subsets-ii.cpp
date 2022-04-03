class Solution {
public:
    
    void solve(int s, vector<int> &nums, vector<int> &tmp, vector<vector<int>> &ans) {
        if (s == nums.size()) {
            ans.push_back(tmp);
            return;
        }
        tmp.push_back(nums[s]);
        solve(s + 1, nums, tmp, ans);
        tmp.pop_back();
        int t = 1;
        while (s + t != nums.size() && nums[s + t - 1] == nums[s + t])
            t++;
        solve(s + t, nums, tmp, ans);
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> tmp;
        vector<vector<int>> ans;
        solve(0, nums, tmp, ans);
        // ans.push_back({});
        return ans;
    }
};