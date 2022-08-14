class Solution {
public:
    int cl (int n, int k) {
        if (n % k == 0)
            return n / k;
        else
            return n / k + 1;
    }
    
    int minSetSize(vector<int>& arr) {
        map<int, int> m;
        for (int val : arr) {
            m[val]++;
        }
        
        int n = arr.size();
        
        int ans = 0;
        int count = 0;
        
        vector<int> freq;
        
        for (auto it = m.rbegin(); it != m.rend(); it++) {
            freq.push_back(it->second);
        }
        
        sort(freq.begin(), freq.end(), greater<int>());
        
        int i = 0;
        while (count < cl(n, 2)) {
            count += freq[i];
            ans++;
            i++;
        }
        
        return ans;
    }
};