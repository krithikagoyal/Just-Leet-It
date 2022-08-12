class Solution {
public:
    int countSubstrings(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dpl(n, vector<int>(m, 0)), dpr(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (s[i] == t[j]) {
                    dpl[i][j] = (i - 1 >= 0 && j - 1 >= 0 ? dpl[i - 1][j - 1] : 0) + 1;
                    // cout << i << " " << j << " " << dpl[i][j] << endl;
                }
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if (s[i] == t[j]) {
                    dpr[i][j] = (i + 2 <= n && j + 2 <= m ? dpr[i + 1][j + 1] : 0) + 1;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (s[i] != t[j]) {
                    int l = (i - 1 >= 0 && j - 1 >= 0 ? dpl[i - 1][j - 1] + 1 : 1);
                    int r = (i + 2 <= n && j + 2 <= m ? dpr[i + 1][j + 1] + 1 : 1);
                    ans += l * r;
                }
            }
        }
        return ans;
    }
};