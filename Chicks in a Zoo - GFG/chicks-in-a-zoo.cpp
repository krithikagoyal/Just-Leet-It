//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
long long int NoOfChicks(int n){
    // Code here
    
       // O(N) is easy
       
       vector<long long int> v(n); // hold's newly hatched chicks on ith day
       
       v[0]=1; 
       
       long long int sum=1;    // holds total chicks on given day
       
       for(int i=1; i<n; i++){
           if(i>=6) sum -= v[i-6];
           v[i] = 2*sum;
           sum += v[i];
               
       }
       
       return sum;
}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution obj;
		long long int ans = obj.NoOfChicks(N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends