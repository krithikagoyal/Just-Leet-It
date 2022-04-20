class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        obstacleGrid[0][0] = obstacleGrid[0][0] ^ 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (obstacleGrid[i][j] == 0) {
                    obstacleGrid[i][j] += (i == 0 ? 0 : obstacleGrid[i - 1][j]) + (j == 0 ? 0 : obstacleGrid[i][j - 1]);
                } else if (i + j != 0) {
                    obstacleGrid[i][j] = 0;
                }
            }
        }
        return obstacleGrid[n - 1][m - 1];
    }
};