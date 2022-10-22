//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:

 void explore_number(int i,int a,int b,int &count)
 {
     if(i>b)
     return;
     if(i>=a&&i<=b)
    count++;
     int last_val=i%10;
     if(last_val>0)
     explore_number(i*10+last_val-1,a,b,count);
     if(last_val<9)
     explore_number(i*10+last_val+1,a,b,count);
 }
   int steppingNumbers(int a, int b)
   {
     int count=0;
       if(a==0)
       count++;
      for(int i=1;i<=9;i++)
      {
          explore_number(i,a,b,count);
      }
      return count;
   }

};


//{ Driver Code Starts.

int main()
{
    Solution obj;
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        cin>>n>>m;
        cout << obj.steppingNumbers(n,m) << endl;
    }
	return 0;
}


// } Driver Code Ends