class Solution {
public:
    char findKthBit(int n, int k) {
        bool reverse = false;
        vector<int> v(n + 1);
        v[0] = 0;
        for (int i = 1; i < n + 1; i++) {
            v[i] = v[i - 1] * 2 + 1;
        }
        char ans = '0';
        while (n != 1) {
            if (k == v[n] / 2 + 1) {
                ans = '1';
                break;
            }
            if (k > v[n] / 2) {
                k = v[n] - k + 1;
                reverse ^= true;
            }
            n--;
        }
        if (reverse) {
            if (ans == '0')
                ans = '1';
            else
                ans = '0';
        }
        return ans;
    }
};