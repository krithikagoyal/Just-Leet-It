//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    int solve(int N, int K, vector<int> &arr) {
        // code here
        // make a prefix array
        for(int i = 1;i<N;i++){
            arr[i] += arr[i-1];
        }
        // converting array to prefix sum array
        vector<int> divisors;
        int sum = arr[N-1];
        for(int i = 1;i*i<=sum;i++){
            if(sum%i == 0){
                divisors.push_back(i);
                if(i != sum/i){
                    divisors.push_back(sum/i);
                }
            }
        }
        // finding all the divisors for the solution;
        int ans = 1; // because 1 is universal GCD;
        for(int divisor : divisors){
            int count = 0; // counts possible sums which can be divided for divisor
            for(int i = 0 ;i<N;i++){
                if(arr[i] % divisor == 0)count++;
                if(count>=K){
                    ans = max(ans,divisor);
                }
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        int K;
        scanf("%d",&K);
        
        
        vector<int> arr(N);
        Array::input(arr,N);
        
        Solution obj;
        int res = obj.solve(N, K, arr);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends