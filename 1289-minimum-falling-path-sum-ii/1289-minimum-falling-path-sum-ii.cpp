class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n == 1)
            return grid[0][0];
        vector<vector<int>> v1(n, vector<int>(2, 100000)), v2(n, vector<int>(2, 100000));
        for (int i = 0; i < n; i++) {
            int jmin = -1;
            int jsmin = -1;
            for (int j = 0; j < n; j++) {
                if (i == 0)
                    v2[j][1] = grid[i][j];
                else
                    v2[j][1] = v1[j][0] + grid[i][j];
                if (jmin == -1 || v2[j][1] <= v2[jmin][1]) {
                    jsmin = jmin;
                    jmin = j;
                } else if (jsmin == -1 || v2[j][1] <= v2[jsmin][1])
                    jsmin = j;
            }
            for (int j = 0; j < n; j++) {
                if (j == jmin)
                    v2[j][0] = v2[jsmin][1];
                else
                    v2[j][0] = v2[jmin][1];
            }
            v1 = v2;
        }
        int ans = 100000;
        ans = min(ans, v1[0][1]);
        ans = min(ans, v1[0][0]);
        return ans;
    }
};