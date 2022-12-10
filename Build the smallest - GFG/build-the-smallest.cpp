//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
string buildLowestNumber(string num, int k);
// Driver program to test above function
int main()
{
    int t,n;
    string str;
    cin>>t;
    while(t--)
    {
    cin>>n;
    cin>>str;
    cout << buildLowestNumber(str, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends


string buildLowestNumber(string num, int k)
{
    stack<char> st;
    for(int i = 0; i < num.length(); i++){
        if(st.empty()){
            st.push(num[i]);
        }
        else{
            while(k > 0 && st.empty() == false && st.top() - '0' > num[i] - '0' ){
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
    }
    while(k != 0 && st.empty() == false){
        st.pop();
    }
    string ans = "";
    while(st.empty() == false){
        ans += st.top();
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    int i = 0;
    while(i < ans.length() && ans[i] == '0'){
        i++;
    }
    if(i == ans.length()){
        return "0";
    }
    string curr = "";
    for(int idx = i; idx < ans.length(); idx++){
        curr += ans[idx];
    }
    return curr;
}