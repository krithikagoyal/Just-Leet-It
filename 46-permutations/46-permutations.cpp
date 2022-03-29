class Solution {
public:
    
    void solve(vector<bool>& done, vector<int>& nums, vector<int>& tmp, vector<vector<int>>& ans) {
        if (tmp.size() == nums.size()) {
            ans.push_back(tmp);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (done[i])
                continue;
            tmp.push_back(nums[i]);
            done[i] = true;
            solve(done, nums, tmp, ans);
            done[i] = false;
            tmp.pop_back();
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> tmp;
        vector<vector<int>> ans;
        vector<bool> done(nums.size(), 0);
        solve(done, nums, tmp, ans);
        return ans;
    }
};