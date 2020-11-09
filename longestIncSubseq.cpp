#include <bits/stdc++.h>
using namespace std;

int lisHelperTd(int len1, int len2, vector<int> &oArr, vector<int> &sortArr, vector<vector<int>> &dp)
{
  if (len1 < 0)
      return 0;
    if (len2 < 0)
      return 0;
  
    if (len1 == 0)
      return 0;
    if (len2 == 0)
      return 0;
    
    if (dp[len1][len2]!=-1)
      return dp[len1][len2];
  
    if (oArr[len1-1] == sortArr[len2-1])
      return dp[len1][len2] = 1+lisHelperTd(len1-1,len2-1,oArr,sortArr,dp);
  
    return dp[len1][len2] = max (lisHelperTd(len1-1,len2,oArr,sortArr,dp),
                                 lisHelperTd(len1,len2-1,oArr,sortArr,dp));
  
}

int longestLISLength(int *arr, int n){
  
  vector<int> oArr(n);
  vector<int> sortArr(n);
  vector<vector<int>> dp(10,vector<int>(10,-1));
  
  for (int i=0;i<n;i++)
  {
    sortArr[i] = arr[i];
    oArr[i] = arr[i];
  }
  
  sort(sortArr.begin(), sortArr.end());
  return lisHelperTd(oArr.size(),sortArr.size(),oArr,sortArr,dp);
}

int main ()
{
  int t; cin>>t;
  int *arr = (int*)malloc(t*sizeof(int));

  for (int i=0;i<t;i++)
    cin>>arr[i];

  cout << longestLISLength(arr,t);  
}
