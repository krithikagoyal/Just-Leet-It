class Solution {
public:
    int countPyramids(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int num = 0;
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1)
                    num++;
                else
                    num = 0;
                int val = (i > 0 && j > 0 ? dp[i - 1][j - 1] : 0);
                dp[i][j] = num != 0 ? min(val + 1, (num - 1) / 2 + 1) : 0;
                ans += max(dp[i][j] - 1, 0);
            }
        }
        
        dp.assign(n, vector<int>(m, 0));
        for (int i = n - 1; i >= 0; i--) {
            int num = 0;
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1)
                    num++;
                else
                    num = 0;
                int val = (i < n - 1 && j > 0 ? dp[i + 1][j - 1] : 0);
                dp[i][j] = num != 0 ? min(val + 1, (num - 1) / 2 + 1) : 0;
                ans += max(dp[i][j] - 1, 0);
            }
        }
        return ans;
    }
};