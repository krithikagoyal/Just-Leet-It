class Solution {
public:
    int calculate(vector<string>& words, vector<int>& count, int idx, vector<int>& score) {
        if (idx >= words.size())
            return 0;
        int ans = 0;
        bool ok = true;
        for (char c : words[idx]) {
            count[c - 'a']--;
            ans += score[c - 'a'];
            if (count[c - 'a'] < 0) {
                ok = false;
            }
        }
        if (ok)
            ans += calculate(words, count, idx + 1, score);
        else
            ans = 0;
        for (char c : words[idx]) {
            count[c - 'a']++;
        }
        ans = max(ans, calculate(words, count, idx + 1, score));
        return ans;
    }
    
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> count(26, 0);
        for (char c : letters) {
            count[c - 'a']++;
        }
        return calculate(words, count, 0, score);
    }
};