class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            int j = 0;
            int k = i;
            while (j <= m - 1) {
                if (k + 1 < n && grid[j][k] == 1 && grid[j][k + 1] == 1) {
                    j++;
                    k++;
                } else if (k - 1 >= 0 && grid[j][k] == -1 && grid[j][k - 1] == -1) {
                    k--;
                    j++;
                } else {
                    ans[i] = -1;
                    break;
                }
            }
            if (j == m)
                ans[i] = k;
        }
        return ans;
    }
};