#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int>dp(101,-1);

int maxGoldBu(vector<int> &arr, int len)
{
    // fill the base cases 
    if (len==0)
        dp[0] = 0;
    if (len==1)
        dp[1] = arr[0];
    if (len==2)
        dp[2] = max (arr[0],arr[1]);
    for (int i=3;i<=len;i++)
        dp[i] = max(arr[i-1]+dp[i-2], dp[i-1]);
    
    return dp[len];
    
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    vector<int> arr(100);
    int l;cin>>l;
    for (int i=0;i<l;i++)
        cin>>arr[i];
    
    //cout << maxGold(arr,l) << endl;
    //cout << maxGoldTd(arr,l) << endl;
    cout << maxGoldBu(arr,l) << endl;
    return 0;
}
