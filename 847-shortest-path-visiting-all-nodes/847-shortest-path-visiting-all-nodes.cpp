class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        if (n == 1)
            return 0;
        queue<pair<int, int>> q;
        vector<vector<bool>> vis(n, vector<bool>((1 << n), false));
        for (int i = 0; i < n; i++) {
            q.push({i, 1 << i});
            vis[i][(1 << i)] = true;
        }
        
        int ans = 0;
        while (q.size()) {
            int sz = q.size();
            while (sz--) {
                int mask = q.front().second;
                int node = q.front().first;
                q.pop();
                for (int x : graph[node]) {
                    int nmask = mask | (1 << x);
                    if (!vis[x][nmask]) {
                        vis[x][nmask] = true;
                        if (nmask == (1 << n) - 1)
                            return ans + 1;
                        q.push({x, nmask});
                    }
                }
            }
            ans++;
        }
        
        return ans;
    }
};