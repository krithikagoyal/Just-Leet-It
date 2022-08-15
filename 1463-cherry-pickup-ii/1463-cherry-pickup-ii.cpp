class Solution {
public:
    bool valid(int j, int k, int m) {
        if (j >= 0 && k >= 0 && j < m && k < m)
            return true;
        return false;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, 0)));
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < m; k++) {
                dp[n - 1][j][k] = (j != k ? grid[n - 1][j] + grid[n - 1][k] : grid[n - 1][j]);
            }
        }
        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j < m; j++) {
                for (int k = 0; k < m; k++) {
                    for (int forj = j - 1; forj <= j + 1; forj++) {
                        for (int fork = k - 1; fork <= k + 1; fork++) {
                            if (valid(forj, fork, m)) {
                                dp[i][j][k] = max(dp[i][j][k], dp[i + 1][forj][fork] + (j != k ? grid[i][j] + grid[i][k] : grid[i][j]));
                            }
                        }
                    }
                }
            }
        }
        return dp[0][0][m - 1];
    }
};