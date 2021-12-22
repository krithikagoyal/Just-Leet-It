class Solution {
public:
    
    void solve(vector<string>& ans, vector<vector<char>>& v, string& digits, int k, string& tmp) {
        if (k == digits.size()) {
            ans.push_back(tmp);
            return;
        }
        for (auto c : v[digits[k] - '0' - 2]) {
            tmp.push_back(c);
            // cout << k << " " << digits.size() << endl;
            solve(ans, v, digits, k + 1, tmp);
            tmp.pop_back();
        }
        return;
    }
    
    vector<string> letterCombinations(string digits) {
        vector<vector<char>> v = {{'a', 'b', 'c'}, {'d', 'e', 'f'}, {'g', 'h', 'i'}, {'j', 'k', 'l'}, {'m', 'n', 'o'}, {'p', 'q', 'r', 's'}, {'t', 'u', 'v'}, {'w', 'x', 'y', 'z'}};
        vector<string> ans;
        if (digits.size() == 0)
            return ans;
        string tmp = "";
        solve(ans, v, digits, 0, tmp);
        return ans;
    }
};