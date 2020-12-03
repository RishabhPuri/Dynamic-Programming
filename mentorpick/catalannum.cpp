#include<bits/stdc++.h>
using namespace std;

const long mod = 1e9+7;
long long dp[1004];

long long catNum(int n)
{
	if (n <=1) return 1;

	long long ans = 0;

	for (int i=0; i<n;i++)
	{
		ans += (catNum(i)%mod*catNum(n-i-1)%mod)%mod;
	}

	return ans;
}

long catNumTd(int n)
{
	if (n <= 1) return 1 ;
  	
  	if (dp[n]!=-1)
      return dp[n];
  
  	long ans = 0;
  	for (int i=0; i<n;i++)
    {
    	ans += (catNum(i)%mod*catNum(n-i-1)%mod)%mod;
    }
  	
  	return dp[n] = ans;
}

void catNumPreCompute(int n)
{
	dp[0] = 1;
  	dp[1] = 1;
  	// Compute for each n, so that we just 
  	// end up performing a lookup.
  	long long ans = 0;
  	for (int i=2;i<=n;i++)
    {
			ans = 0;
    	for (int j=0;j<=i-1;j++)
        {
        	ans+=(dp[j]%mod*dp[i-j-1]%mod)%mod;
        }
      	dp[i] = ans;
    }
}

long catNumBu(int n)
{
  return dp[n];
}

int main()
{
	int tc;
  	int n;
  	cin >> tc;
  	for (int i=0;i<1001;i++)
    	dp[i] = -1;
    
  	// we already know the range of n, so we precompute here
  	catNumPreCompute(1000);
  	
  	while (tc--)
    {
    	cin >> n;
      	
      
      	//cout << catNum(n) << endl;
      	//cout << catNumTd(n) << endl;
      	cout << catNumBu(n) << endl;
    }

	return 0;
}
