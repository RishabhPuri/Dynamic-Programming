/* 
You are given a floor of size 5xN. You have tiles of 2 different sizes: 1x5 and 2x5. Of course, you can rotate the tiles to get 2 more tile sizes: 5x1 and 5x2. You have to do the flooring using these tiles in the following way:
1. Floor space should be completely covered by tiles.
2. You cannot break tiles, ie, you have to use a tile entirely or not at all.
3. Any tile should not extend beyond the floor space.
4. Tiles should be placed parallel to the floor boundaries.

Your task is to find the number of ways in which you can lay the tiles on the floor.
1 <= T <= 10000
1 <= N <= 106
*/ 

#include<bits/stdc++.h>
using namespace std;


const long long mod = 1e9+7;

int main()
{

  long tc;
  int N;  
  cin >> tc;

  /** Thought process 
    Start calculating to see a pattern 
    N     Ways
    0     1  
    1     1
    2     2
    3     3
    4     5
    5     16 (special case) 
    dp[5] --> dp[n-1]+dp[n-2]+8*dp[n-5]
   
    Now here For N=0 we force fit to 1 so that we can calculate N=2 
    */

  vector<long long>dp(10005,0);
  dp[0]=1,dp[1]=1,dp[2]=2,dp[3]=3,dp[4]=5,dp[5]=16;
  for (int i=6;i<10005;i++)
    dp[i] = (dp[i-1]%mod+dp[i-2]%mod+8*dp[i-5]%mod)%mod;

  while (tc--)
  {
    cin >> N;
    cout << dp[N] << endl;
  }

	return 0;
}
