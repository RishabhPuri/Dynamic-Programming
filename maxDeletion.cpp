#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int maxDeletions(vector<int>&arr, int size, int currmax)
{
    vector<int> dp(size+1,-1);
    
    dp[0] = 0; dp[1] = 0;
    dp[2] = arr[0] > arr[1] ? 1 : 0;
    
    for (int i=3;i<=size;i++)
        dp[i] = arr[i-2] > arr[i-1] ? 1+dp[i-1] : dp[i-1];
    
    
    return dp[size];
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int t ; cin >> t;
    int size;
    vector<int> arr;
    while(t--)
    {
        cin>>size;
        arr.resize(size);
        for(int i=0;i<size;i++)
            cin>>arr[i];
        
        cout << maxDeletions(arr,size,0) << endl;
    }
    return 0;
}

