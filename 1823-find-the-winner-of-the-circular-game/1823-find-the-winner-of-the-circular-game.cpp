class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int> q;
        for (int i = 0; i < n; i++)
            q.push(i + 1);
        
        while (n > 1) {
            // int num = k % n; // num = 2
            // if (num == 0) 
            //     num = n;
            int num = k;
            n--;
            for (int i = 0; i < num - 1; i++) {
                int val = q.front();
                q.pop();
                q.push(val);
                // cout << val << " " << n << " " << q.front() << endl;
            }
            q.pop();
        } // 5, 1 2 3 4 5, 3 4 5 1, 5 1 3, 3 5
        
        return q.front();
    }
};