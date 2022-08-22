class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        stack<int> s1, s2;
        vector<int> dp(n, 1);
        for (int i = 0; i < n; i++) {
            while (s1.size() && arr[s1.top()] < arr[i]) {
                int ini = arr[s1.top()];
                while (s1.size() && ini == arr[s1.top()]) {
                    if (s1.top() + d >= i)
                        dp[i] = max(dp[i], dp[s1.top()] + 1);
                    s2.push(s1.top());
                    s1.pop();
                }
                while (s2.size()) {
                    if (s1.size() && s1.top() + d >= s2.top())
                        dp[s1.top()] = max(dp[s1.top()], dp[s2.top()] + 1);
                    s2.pop();
                }
            }
            s1.push(i);
        }
        
        while (s1.size()) {
            int ini = arr[s1.top()];
            while (s1.size() && ini == arr[s1.top()]) {
                s2.push(s1.top());
                s1.pop();
            }
            while (s2.size()) {
                if (s1.size() && s1.top() + d >= s2.top())
                    dp[s1.top()] = max(dp[s1.top()], dp[s2.top()] + 1);
                s2.pop();
            }
        }
        
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};