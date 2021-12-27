class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> newIntervals;
        for (int i = 0; i < intervals.size(); i++) {
            if (intervals[i][0] <= newInterval[0] && intervals[i][1] >= newInterval[0]) {
                newInterval = {intervals[i][0], max(intervals[i][1], newInterval[1])};
            } else if (intervals[i][0] >= newInterval[0] && intervals[i][0] <= newInterval[1]) {
                newInterval = {newInterval[0], max(intervals[i][1], newInterval[1])};
            } else if (intervals[i][0] > newInterval[0]) {
                newIntervals.push_back(newInterval);
                newIntervals.push_back(intervals[i]);
                newInterval = {10000000, 10000000};
            } else {
                newIntervals.push_back(intervals[i]);
            }
        }
        if (newInterval[0] != 10000000) {
            newIntervals.push_back(newInterval);
        }
        return newIntervals;
    }
};