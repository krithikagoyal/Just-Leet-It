class Solution {
public:
    int numSplits(string s) {
        vector<int> ve(26, 0), vb(26, 0);
        int totalUnique = 0;
        for (auto c : s) {
            ve[c - 'a']++;
            if (ve[c - 'a'] == 1)
                totalUnique++;
        }
        
        int ans = 0;
        int uniqueFromStart = 0;
        for (auto c : s) {
            vb[c - 'a']++;
            if (vb[c - 'a'] == 1)
                uniqueFromStart++;
            ve[c - 'a']--;
            if (ve[c - 'a'] == 0)
                totalUnique--;
            
            if (uniqueFromStart == totalUnique)
                ans++;
        }
        
        return ans;
    }
};