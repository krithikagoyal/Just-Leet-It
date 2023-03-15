//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//User function Template for C++

class Solution{   
  public:
    string secondSmallest(int S, int D){
        // code here 
        if (D * 9 <= S) {
            return "-1";
        }
        string ans = "";
        int val = S / 9;
        int left = S % 9;
        int dig = 0;
        if (val > 0)
            dig += val;
        if (left > 0)
            dig += 1;
        
        if (dig < D) {
            val = (S - 1)/ 9;
            left = (S -1) % 9;
        }
        
        for (int i = 0; i < val - 1; i++) {
            ans += '9';
        }
        int to = D - val - 1;
        // cout << ans << endl;
        if (val > 0) {
            ans += '8';
            ans += char(left + 1 + int('0'));
            // cout << ans << " " << left << endl;
        } else {
            ans += char(left - 1 + int('0'));
        }
        
        
        if (val > 0) {
            for (int i = 0; i < to - 1; i++) {
                ans += '0';
            }
            if (to > 0) {
                ans += '1';
            }
        } else {
            if (to - 1 == 0)
                ans += '2';
            else 
                ans += '1';
            for (int i = 0; i < to - 2; i++) {
                ans += '0';
            }
            if (to - 1 > 0) {
                ans += '1';
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int S,D;
        cin >> S >> D;
        Solution ob;
        cout << ob.secondSmallest(S,D) << endl;
    }
    return 0; 
} 
// } Driver Code Ends