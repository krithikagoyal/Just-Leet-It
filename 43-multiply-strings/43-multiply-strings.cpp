class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1[0] == '0' || num2[0] == '0')
            return "0";
        string ans = "", to_add = "";
        int carry = 0;
        for (int i = num1.size() - 1; i >= 0; i--) {
            for (int j = 0; j < num1.size() - i - 1; j++) {
                ans += '0';
            }
            for (int j = num2.size() - 1; j >= 0; j--) {
                int val = (num1[i] - '0') * (num2[j] - '0') + carry;
                carry = val / 10;
                val %= 10;
                char c = (char)(val + (int)'0');
                ans += c;
            }
            while (carry) {
                int val = carry % 10;
                carry /= 10;
                char c = char(val + '0');
                ans += c;
            }
            int k = 0, l = 0;
            string tmp = "";
            while (k != to_add.size() && l != ans.size()) {
                int val = (to_add[k] - '0') + (ans[l] - '0') + carry;
                carry = val / 10;
                val %= 10;
                char c = char(val + '0');
                tmp += c;
                l++, k++;
            }
            while (k != to_add.size()) {
                int val = (to_add[k] - '0') + carry;
                carry = val / 10;
                val %= 10;
                char c = char(val + '0');
                tmp += c;  
                k++;
            }
            while (l != ans.size()) {
                int val = (ans[l] - '0') + carry;
                carry = val / 10;
                val %= 10;
                char c = (char)(val + (int)'0');
                tmp += c;  
                l++;
            }
            while (carry) {
                int val = carry;
                carry = val / 10;
                val %= 10;
                char c = char(val + '0');
                tmp += c;  
            }
            to_add = tmp;
            ans = "";
        }
        reverse(to_add.begin(), to_add.end());
        return to_add;
    }
};