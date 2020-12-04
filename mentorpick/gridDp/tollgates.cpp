#include <bits/stdc++.h>
using namespace std;

#define MAX_R 1000
#define MAX_C 1000

int cost[MAX_R][MAX_C];

const int inf = INT_MAX;
long long dp[MAX_R][MAX_C];



int minCostTollTravelRec(int r, int c, int i, int j)
{
  if ((i<0) || (j<0) || (i>r-1) || (j>c-1))
    return inf;

  /** if we just treat the above boundary condition as 
    * recursion terminating conditions, one problem is
    * everytime recursion chooses a row 'i' such that 
    * i<0 or i<r-1 then the min will always be considered
    * from that row 
    * Eg: in the following array
    *  2 9 1 7
    *  3 0 1 1
    *  6 2 1 8
    *  1 5 2 2
    *  7 3 2 9
    *  5 4 1 1
    * if we start with last row, then after we choose the 
    * first toll gate 5, we can choose 3,4,or i+1 (which is out of bounds)
    * now for i+1 (outofbounds) our code always returns 0, which is going 
    * be always minimum, hence this approach has an obvious flaw.
    *
    *
    *
    *
    *
    *
    *
    **/
  if (j==c-1)
    return cost[i][j];

  	return cost[i][j]+
      min({minCostTollTravelRec(r,c,i,j+1),
           minCostTollTravelRec(r,c,i-1,j+1),
           minCostTollTravelRec(r,c,i+1,j+1)});
}

int minCostofTollTravelTd(int r, int c, int i, int j)
{
  if ((i<0) || (j<0) || (i>r-1) || (j>c-1))
    return inf;

  if (dp[i][j]!=-1)
    return dp[i][j];
  
  if (j==c-1)
    return dp[i][j]=cost[i][j];

  	return dp[i][j] =  cost[i][j]+
      min({minCostofTollTravelTd(r,c,i,j+1),
           minCostofTollTravelTd(r,c,i-1,j+1),
           minCostofTollTravelTd(r,c,i+1,j+1)});

}

void precompute(int r, int c)
{
  	for (int i=0;i<r+1;i++)
		for(int j=0;j<c+1;j++)
        	dp[i][j] = inf;
  
  	// Answer is in dp[i][0] , first column
  	// so the last column is considerd the
  	// first toll gate, fill value as is
  	for (int i=0;i<r;i++)
    	dp[i][c-1] = cost[i][c-1];
  	
  	for (int j=c-2;j>=0;j--) {
		  for (int i=0;i<r;i++) {
          if (i==0)
      		  dp[i][j] = cost[i][j]+min({dp[i][j+1],dp[i+1][j+1]});
          else if (i==r-1)
      		  dp[i][j] = cost[i][j]+min({dp[i-1][j+1],dp[i][j+1]});
          else
      		  dp[i][j] = cost[i][j]+min({dp[i-1][j+1],dp[i][j+1],dp[i+1][j+1]});
      }
    }
}

int minCostOfTollTravelBu(int r, int c, int startLane)
{
    precompute(r,c);
  
  	return dp[startLane][0];
}

int minCostOfTollTravel(int r, int c, int startLane){
  
  //return minCostTollTravelRec(r,c,startLane-1,0);
  for (int i=0;i<=r;i++)
    for (int j=0;j<=c;j++)
      dp[i][j] = -1;
  
  //return minCostofTollTravelTd(r,c,startLane-1,0);
  return minCostOfTollTravelBu(r,c,startLane-1);

}

int main ()
{
  int tc,r,c,qc,q;
  cin >> tc;
  while(tc--)
  {
    cin >> r >> c;
    for (int i=0;i<r;i++)
      for (int j=0;j<c;j++)
        cin >> cost[i][j];
  
    cin >> qc;
    while (qc--)
    {
      cin >> q;
      cout << minCostOfTollTravel(r,c,q);
    }
  }

}
