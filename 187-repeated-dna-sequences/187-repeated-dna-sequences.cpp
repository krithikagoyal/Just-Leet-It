class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> um;
        vector<string> ans;
        if (s.size() < 10)
            return ans;
        for (int i = 0; i <= (s.size() - 10); i++) {
            string tmp = "";
            for (int j = i; j < i + 10; j++) {
                tmp += s[j];
            }
            um[tmp]++;
            if (um[tmp] == 2)
                ans.push_back(tmp);
        }
        return ans;
    }
};