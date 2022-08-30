class Solution {
public:
    int longestDecomposition(string text) {
        int n = text.size();
        int ln = n / 2;
        string s1 = "", s2 = "";
        int sz = 0;
        int ans = 0;
        for (int i = 0; i < ln; i++) {
            s1 += text[i];
            s2 += text[n - i - 1];
            sz++;
            bool ok = true;
            for (int j = 0; j < sz; j++) {
                if (s1[j] != s2[sz - j - 1]) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                sz = 0;
                s1 = "";
                s2 = "";
                ans++;
            }
        }
        ans *= 2;
        if (sz || n % 2)
            ans++;
        return ans;
    }
};