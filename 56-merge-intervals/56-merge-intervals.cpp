class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int st = intervals[0][0], en = intervals[0][1];
        vector<vector<int>> ans;
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] <= en) {
                en = max(intervals[i][1], en);
            } else {
                ans.push_back({st, en});
                st = intervals[i][0];
                en = intervals[i][1];
            }
        }
        ans.push_back({st, en});
        return ans;
    }
};