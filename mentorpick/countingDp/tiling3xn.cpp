/** 
Given a 3xN size field that needs to be covered by 2x1 size tiles.  We need to find out how many ways are there to cover the field, you can rotate 2x1 title and use it as 1x2 tile also. We also need to fulfill these constraints:
Field space should be completely covered by tiles.
You cannot break tiles, ie, you have to use a tile entirely or not at all.
Any tile should not extend beyond the field space.
Tiles should be placed parallel to the floor boundaries.
Your task is to find the number of ways in which you can lay the tiles on the field.
*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
  	long N;
  	string s;
  	
  	vector<long long>dp(35,0);
  	dp[0]=1,dp[1]=0,dp[2]=3,dp[3]=0;
  	for (int i=4;i<35;i++)
    	dp[i] = 4*dp[i-2]-dp[i-4];
      
  	while (getline(cin,s))
    {
    	if (s.empty())
          break;
      
      	N = stoi(s);
      	cout << dp[N] << endl;
    }

	return 0;
}


/** thought process 
Problem Approach:
You are to fill a 3*n rectangle with 1*2 rectangles. With input n, you need to output the number of ways to fill the big rectangle.

First, if n is odd, then the size of the big rectangle is odd, it is impossible to fill it with small rectangles with size 2. Hence, n must be even. Second, for a 3*n rectangle, let’s consider its rightmost 2 columns:

Suppose there are f(n) ways to fill the entire rectangle, then there are f(n-2) ways to fill the left rectangle without the rightmost 2 columns. There are 3 different ways to fill the 3*2 (orange) rectangle: 3 horizontal blocks or 1 horizontal and 2 vertical blocks (can flip to get another filling). So there are 3*f(n-2) ways of filling with the rightmost 2 columns filled nicely with 3 blocks.

Next, we consider the rightmost 4 columns. In order to avoid repetition, we do not count cases where the rightmost 2 columns are filled nicely with 3 blocks, because that case is already counted in the previous case. Then there are only 2 other ways to fill the big rectangle: the image below and its flip. Hence there are 2*f(n-4) ways with the rightmost 4 columns filled up.


Similarly, we consider the rightmost 6 columns. To avoid repetition, we don’t count cases where the rightmost 2 or 4 columns are filled up nicely. Then we only have 2 more ways: the image below and its flip. Hence we have 2*f(n-6) more ways.


We can notice that there are only 2 more possible ways to all n>2. Hence we derive the formula:

f(n)=3f(n-2) + 2f(n-4) + 2f(n-6) + … + 2f(n-(n-2)) + 2

The last term is 2 because there are 2 more ways if we consider the entire n columns without repetition with previous cases.

If we let f(0)=1, then the formula becomes:

f(n)=3f(n-2) + 2f(n-4) + 2f(n-6) + … + 2f(2) + 2f(0)

Sub the below quation into the above equation:

f(n-2)=3f(n-4) + 2f(n-6) + … + 2f(2) + 2f(0)

We get:

f(n) = 4f(n-2)-f(n-4), where f(0)=1, f(2)=3



*/
