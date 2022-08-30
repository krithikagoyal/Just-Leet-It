class Solution {
public:
    unordered_map<int, pair<int, int>> m;

    int dis(int x, int y) {
        return abs(m[x].first - m[y].first) + abs(m[x].second - m[y].second);
    }
    
    int minimumDistance(string word) {
        for (int j = 0; j < 4; j++) {
            for (int i = 0; i < 6; i++) {
                m[i + j * 6] = {j, i};
            }
        }
        m[24] = {4, 0};
        m[25] = {4, 1};
        
        int n = word.size();
        vector<vector<vector<int>>> v(26, vector<vector<int>>(26, vector<int>(n + 1, INT_MAX)));
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                v[i][j][0] = 0;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 26; j++) {
                for (int k = 0; k < 26; k++) {
                    if (v[j][k][i] == INT_MAX)
                        continue;
                    int num = word[i] - 'A';
                    // cout << v[j][k][i] << " " << num << endl;
                    v[num][k][i + 1] = min(v[j][k][i] + dis(num, j), v[num][k][i + 1]);
                    v[j][num][i + 1] = min(v[j][k][i] + dis(num, k), v[j][num][i + 1]);
                }
            }
        }
        int ans = INT_MAX;
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                ans = min(ans, v[i][j][n]);
            }
        }
        return ans;
    }
};