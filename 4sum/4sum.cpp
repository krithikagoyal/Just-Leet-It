class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
            // -2, -1, 0, 0, 1, 2
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        vector<int> v;
        for (int i = 0; i < n; i++) {
            // cout << nums[i] << endl;
            if (i && nums[i] == nums[i - 1]) 
                continue;
            for (int j = i + 1; j < n; j++) {
                if (j != i + 1 && nums[j] == nums[j - 1])
                    continue;
                int l = j + 1, r = n - 1;
                int val = target - nums[i] - nums[j];
                while (l < r) {
                    // cout << nums[i] << " " << nums[j] << " " << nums[l] << " " << nums[r] << endl;

                    if (nums[l] + nums[r] == val) {
                        v = {nums[i], nums[j], nums[l], nums[r]};
                        ans.push_back(v);
                        while (l + 1 < n && nums[l] == nums[l + 1])
                            l++;
                        while (r - 1 > 0 && nums[r] == nums[r - 1])
                            r--;
                        l++, r--;
                    } else if (nums[l] + nums[r] < val) {
                        l++;
                    } else {
                        r--;
                    }
                }
            }
        }
        return ans;
    }
};