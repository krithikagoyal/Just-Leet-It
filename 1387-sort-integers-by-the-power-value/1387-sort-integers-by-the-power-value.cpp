class Solution {
public:
    unordered_map<int, int> m;
    
    int getVal(int val) {
        if (val == 1)
            return 0;
        if (m[val] != 0)
            return m[val];
        int ans;
        if (val % 2) {
            ans = getVal(3 * val + 1) + 1;
        } else {
            ans = getVal(val / 2) + 1;
        }
        return m[val] = ans;
    }
    
    int getKth(int lo, int hi, int k) {
        vector<pair<int, int>> v;
        for (int i = lo; i <= hi; i++) {
            int val = getVal(i);
            v.push_back({val, i});
        }
        sort(v.begin(), v.end());
        return v[k - 1].second;
    }
};