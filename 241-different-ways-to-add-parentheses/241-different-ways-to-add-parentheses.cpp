class Solution {
public:
    bool checkDig(char c) {
        if (c != '*' && c != '+' && c != '-') {
            return true;
        } 
        return false;
    }
    
    int eval(int num1, int num2, char op) {
        if (op == '*')
            return num1 * num2;
        else if (op == '-')
            return num1 - num2;
        return num1 + num2;
    }
    
    vector<int> diffWaysToCompute(string expression) {
        if (expression.size() == 2) {
            return {(expression[0] - '0') * 10 + (expression[1] - '0')};
        } else if (expression.size() == 1) {
            return {expression[0] - '0'};
        }
        
        int n = expression.size();
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            if (checkDig(expression[i]) == false) {
                auto v1 = diffWaysToCompute(expression.substr(0, i));
                auto v2 = diffWaysToCompute(expression.substr(i + 1, n - i - 1));
                for (int x : v1) {
                    for (int y : v2) {
                        ans.push_back(eval(x, y, expression[i]));
                    }
                }
            }
        }
        
        return ans;
    }
};