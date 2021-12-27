class Solution {
public:
    
    void solve(vector<int>& nums, vector<bool>& done, vector<vector<int>>& ans, vector<int>& tmp) {
        
        // cout << start << " " << end << endl;
        
        for (int i = 0; i < nums.size(); i++) {
            if (done[i] || (i && nums[i] == nums[i - 1] && !done[i - 1]))
                continue;
            done[i] = true;
            tmp.push_back(nums[i]);
            solve(nums, done, ans, tmp);
            tmp.pop_back();
            done[i] = false;
        }
        
        if (tmp.size() == nums.size())
            ans.push_back(tmp);
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> tmp;
        vector<bool> done(nums.size(), false);
        solve(nums, done, ans, tmp);
        return ans;
    }
};