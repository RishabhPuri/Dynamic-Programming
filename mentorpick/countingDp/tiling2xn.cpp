
#include<bits/stdc++.h>
using namespace std;
const long long mod = 1e9+7;

int main()
{
  	int tc;
	long N;
  	string s;
  	vector<long long>dp(255,0);
  	dp[0]=1,dp[1]=1,dp[2]=3,dp[3]=5,dp[4]=8;
  
  	for (int i=4;i<255;i++)
    	dp[i] = (dp[i-1]%mod+2*dp[i-2]%mod)%mod;
  	
  	while (getline(cin,s))
    {
      	if (s.empty()) 
        	break;
      
      	
  		N = stoi(s);
  		cout << dp[N] << " " ;
    }
	return 0;
}



/** 
  thought process 
  Let us consider space of dimensions 2xn, where we are allowed to only use 2x1 tiles or 2x2 tiles.

Let dp[i] denotes number of ways of filling space with 2xi dimensions.



Number of ways of filling a 2x0 space is 1. i.e, dp[0] = 1

Number of ways of filling a 2x1 space is 1. We can use a 2x1 tile. i.e, dp[1] = 1

Number of ways of filling a 2x2 space is 3. We can use one 2x2 tile, two 2x1 tiles placed vertically, two 1x2 tiles placed in horizontal way. i.e, dp[2] = 3.



From this we can generate a recurrence relation, dp[n] = dp[n-1] + 2*dp[n-2].



In bottom-up approach, let us build an array of size 100000, as N can be up to 1000000 maximum.

For each test case print the tilecount of given n from the pre-computed array.
*/
