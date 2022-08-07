class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> adj(numCourses);
        for (auto& x : prerequisites) {
            adj[x[1]].push_back(x[0]);
            indegree[x[0]]++;
        }
        
        queue<int> q;
        
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        
        vector<int> ans;
        
        int num = 0;
        
        while (q.size() && num <= numCourses) {
            int x = q.front();
            ans.push_back(x);
            q.pop();
            for (int y : adj[x]) {
                indegree[y]--;
                if (indegree[y] == 0) {
                    q.push(y);
                }
            }
            num++;
        }
        
        vector<int> u;
        
        return (ans.size() != numCourses ? u : ans);
    }
};