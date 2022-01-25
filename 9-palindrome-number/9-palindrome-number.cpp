class Solution {
public:
    bool isPalindrome(int x) {
        vector<int> dig;
        if (x < 0) {
            return false;
        }
        
        while (x) {
            dig.push_back(x % 10);
            x /= 10;
        }
        
        for (int i = 0; i < dig.size() / 2; i++) {
            if (dig[i] != dig[dig.size() - 1 - i])
                return false;
        }
        
        return true;
    }
};