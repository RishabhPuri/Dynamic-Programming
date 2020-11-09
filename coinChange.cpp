#include <bits/stdc++.h>

using namespace std;

int waysCoinChangeHelperRec(vector<int> &arr, int s, int n)
{
  if (s < 0)
      return 0;
    if (n == 0)
      return 0;
    if (s == 0)
      return 1;
  
    return waysCoinChangeHelperRec(arr,s-arr[n-1],n) + waysCoinChangeHelperRec(arr,s,n-1);
}

int waysCoinChangeHelperTd(vector<int> &arr, vector<vector<int>>&dp, int s, int n)
{
    if (s<0)
      return 0;
    if (n==0)
      return 0;
    if (s==0)
      return 1;
  
    if (dp[s][n]!=-1)
      return dp[s][n];
  
    return (dp[s][n] = waysCoinChangeHelperTd(arr,dp,s-arr[n-1],n) + waysCoinChangeHelperTd(arr,dp,s,n-1));
}

int waysCoinChange(vector<int> &arr, int s)
{
    int size = arr.size();
    vector<vector<int>> dp(size+1, vector<int>(s+1,-1));
  
    //return waysCoinChangeHelperRec(arr,s,arr.size());
    
    return waysCoinChangeHelperTd(arr,dp,s,arr.size());
}


int main()
{
  int t;cin>>t;
    int size, qc,q;
    vector<int> arr;
    while (t--)
    {
        arr.clear();
        cin>>size;
        arr.resize(size);
      
        
        for(int i=0;i<size;i++)
              cin>>arr[i];
        
        cin>>qc;
        while(qc--)
        {
          cin>>q;
          cout << waysCoinChange(arr,q) << " ";       
        }
        cout << endl;
        
    }
    
  return 0;
}
