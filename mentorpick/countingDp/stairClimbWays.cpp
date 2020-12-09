#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
/** Thought process , first recursive 
   For recursive i thought for lets says (3,2)
   first , i will find all ways when i take 1 step 
   then, i will find all ways when i take 2 steps 
   (wont go beyond , because at max 2 steps )
   so extending this for n
    i will all ways when i take n steps
   Now : 
    every time i take a step say 1 , no of stairs decrease by 1
    similarly every time i take a step say 2, no of stairs decrease by 2
    Now: 
    Base case : when steps will become 0 or 1 , we return 1 , 
    means start with stairs = 3 , when we are left with 1 stair only
    we return 1 or when we are left with 0 stair , we return 1 ( because 
    we have climbed all stairs) 
  */

long long waysToClimbUp(int s, int m) 
{
  	long long ans = 0;
  
    if (s<0) return 0;	
  	if (s==0) return 1;
  	if (s==1) return 1;
  	if (m==1) return 1;
  
   	for (int i=1;i<=m;i++)
    {
   		ans += waysToClimbUp(s-i,m)%mod;
    }
  
  	return ans;
}

/** Thought process 
    We need to create a dp solution so that my nth problem is
    derived from n-1th problem's solution 
    I started with creating a table for lets say (6,2) 
    N(stairs)     N(steps)      Ways
    0               1             1    // special case , for no steps, we can reach in 1 way only 
    1               1             1
    1               2             1 (NA)
    2               1             1
    2               2             2 
    3               1             1 
    3               2             3 dp[2]+dp[1] 
    The above formulae will change for lets say 6,3
    it will become dp[2]+dp[1]+dp[0]
    The above formula means lets say for (6,2) if i need to  calculate
    all ways to reach lets say step 3, then we need all ways to reach step 1 and step2 
    why only last 2 steps , because as per question, to reach step 3 , we have just 2 steps 
    so we reach step 3 from step 2 ( using 1 step) or step 2 (using step2)
    Ways(3,2) = ways(2)+ways(1)
    For say 6,3 , this means all ways to reach step 4, then we need all ways to reach
    step 3, step2, step1a
    */

long long waysToClimbUpBu(int s, int m)
{
  long long dp[1001];
  memset(dp,0,sizeof dp); 
  
  dp[0] = 1;
  dp[1] = 1;  // if N(steps) = 1

  for (int stairs=2; stairs<=s; stairs++)
    for (int steps=1; steps<=m&&steps<=stairs; steps++)
      dp[stairs] = dp[stairs]+dp[stairs-steps]; 

  return dp[s];
}

int main ()
{
  int tc,s,m;
  cin >> tc;
  while (tc--)
  {
    cin >> s >> m;

    cout << waysToClimbUpBu(s,m) << " ";
  }
}
