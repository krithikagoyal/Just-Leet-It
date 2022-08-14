class Solution {
public:
    bool isDigit(char c) {
        if ((c <= 'z' && c >= 'a') || c == '[')
            return false;
        return true;
    }
    
    int convertStr(string s) {
        if (s.size() == 3) {
            return 100 * (s[2] - '0') + 10 * (s[1] - '0') + (s[0] - '0');
        } else if (s.size() == 2) {
            return 10 * (s[1] - '0') + (s[0] - '0');
        }
        return s[0] - '0';
    }
    
    string decodeString(string s) {
        stack<char> st;
        for (char c : s) {
            if (c == ']') {
                string tmp = "";
                while (st.top() != '[') {
                    tmp += st.top();
                    st.pop();
                }
                st.pop();
                string dig = "";
                
                while (st.size() && isDigit(st.top())) {
                    dig += st.top();
                    st.pop();
                }
                
                // cout << dig << endl;
                int times = convertStr(dig);
                // cout << times << endl;
                // reverse(tmp.begin(), tmp.end());
                string tmp2 = "";
                while (times--) {
                    tmp2 += tmp;
                }
                for (int i = tmp2.size() - 1; i >= 0; i--)
                    st.push(tmp2[i]);
            } else {
                st.push(c);
            }
        }
        string ans = "";
        while (st.size()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};