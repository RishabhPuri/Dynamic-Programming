#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;


int minCost(vector<vector<long>> arr, int n)
{
    long long dp[n+1][3+1];
    
    for (int i=0;i<=n;i++)
        dp[i][0] = 0;
    
    for (int j=0;j<=3;j++)
        dp[0][j] = 0;
     
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=3;j++)
        {
            if (j==1)
                dp[i][j] = arr[i-1][j-1] + min(dp[i-1][j+1],dp[i-1][j+2]);
            else if (j==2)
                dp[i][j] = arr[i-1][j-1] + min(dp[i-1][j-1],dp[i-1][j+1]);
            else if (j==3)
                dp[i][j] = arr[i-1][j-1] + min(dp[i-1][j-2],dp[i-1][j-1]);
        }
    }
    
    int minCost = INT_MAX;
    for (int j=1;j<=3;j++)
    {
        if (minCost > dp[n][j])
            minCost = dp[n][j];
    }
    
    return minCost;
}

int main() {
    vector<vector<long>> n;
    long houses;cin>>houses;
    n.resize(houses);
    for(int i=0;i<houses;i++)
        n[i].resize(3);
    long item;
    for (int i=0;i<houses;i++)
    {
        for (int j=0;j<3;j++)
        {
            cin>>item;
            n[i][j]= item;
        }
    }
        
    cout << minCost(n, houses) << endl;
    return 0;
}

