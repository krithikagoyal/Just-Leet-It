class Solution {
public:
    int palindromePartition(string s, int k) {
        int n = s.size();
        vector<vector<int>> v(n, vector<int>(k, INT_MAX));
        vector<vector<int>> cng(n, vector<int>(n, 0));
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - i; j++) {
                if (s[j] == s[j + i] && j + 1 <= j + i - 1)
                    cng[j][j + i] = cng[j + 1][j + i - 1];
                else if (j + 1 <= j + i - 1)
                    cng[j][j + i] = cng[j + 1][j + i - 1] + 1;
                else if (s[j] != s[j + i])
                    cng[j][j + i] = 1;
            }
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < min(i + 1, k); j++) {
                for (int l = i; l >= 0; l--) {
                    int val = 0;
                    if (j - 1 < 0 && l - 1 >= 0)
                        val = INT_MAX;
                    else if (l - 1 < 0 && j - 1 >= 0)
                        val = INT_MAX;
                    else if (l - 1 >= 0 && j - 1 >= 0)
                        val = v[l - 1][j - 1];
                    if (val != INT_MAX) {
                        v[i][j] = min(v[i][j], val + cng[l][i]);
                    }
                }
            }
        }
        return v[n - 1][k - 1];
    }
};