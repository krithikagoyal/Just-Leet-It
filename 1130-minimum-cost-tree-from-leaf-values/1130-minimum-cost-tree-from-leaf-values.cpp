class Solution {
public:
    int calculate(vector<int>& arr, int i, int j, vector<vector<int>>& dp) {
        // cout << i << " " << j << endl;
        if (dp[i][j] != -1)
            return dp[i][j];
        if (i == j)
            return dp[i][j] = 0;
        int ans = INT_MAX;
        vector<int> mxRight(j - i + 1, 0), mxLeft(j - i + 1, 0);
        mxRight[0] = arr[i];
        mxLeft[j - i] = arr[j];
        for (int k = i + 1; k <= j; k++) {
            mxRight[k - i] = max(arr[k], mxRight[k - i - 1]);
        }
        for (int k = j - 1; k >= i; k--) {
            mxLeft[k - i] = max(mxLeft[k - i + 1], arr[k]);
        }
        for (int k = i; k <= j - 1; k++) {
            int valLeft = calculate(arr, i, k, dp);
            int valRight = calculate(arr, k + 1, j, dp);
            // cout << i << " " << j << " " << valLeft << " " << valRight << endl;
            ans = min(ans, valLeft + valRight + mxRight[k - i] * mxLeft[k + 1 - i]);
        }
        // cout << i << " " << j << " " << ans << endl;
        return dp[i][j] = ans;
    }
    
    int mctFromLeafValues(vector<int>& arr) {
        vector<vector<int>> dp(arr.size(), vector<int>(arr.size(), -1));
        return calculate(arr, 0, arr.size() - 1, dp);
    }
};