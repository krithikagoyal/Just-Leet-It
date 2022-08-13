class Solution {
public:
    int findTheWinner(int n, int k) {
        int ans = 1;
        for (int i = 2; i <= n; i++) {
            int num = k % i;
            if (num == 0)
                num = i;
            int start = num + 1;
            if (start == i + 1)
                start = 1;
            if (start > num)
                start--;
            ans = ((start - 1) + ans) % (i - 1);
            if (ans == 0)
                ans = i - 1;
            if (ans >= num) {
                ans++;
            }
            // cout << i << " " << ans << endl;
        } // 
        return ans;
    }
};